import os
os.environ["CUDA_DEVICE_ORDER"]="PCI_BUS_ID"
os.environ["CUDA_VISIBLE_DEVICES"]="2"

import torch
from torch.utils.data import TensorDataset, DataLoader
from torch.autograd import Variable
from model import cnn_activity
import torch.nn.functional as F
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

cuda = torch.cuda.is_available()
device = "cuda:0"if cuda else "cpu"

torch.set_num_threads(4)
trainingset = pd.read_csv('../data/holistic/train.csv')
trainingset.head()
train_x = trainingset.iloc[:, 4:204]
train_x = train_x.values
train_y = trainingset.iloc[:, 0]
train_y = train_y.values
#train_w = trainingset.iloc[:, 2]
#train_w = train_w.values
print("training set loaded")
train_x = train_x.reshape(len(train_x),1,200)

validationset = pd.read_csv('../data/holistic/validation.csv')
validationset.head()

validation_x = validationset.iloc[:,4:204]
validation_x = validation_x.values
validation_y = validationset.iloc[:,0]
validation_y = validation_y.values
#validation_w = validationset.iloc[:,2]
#validation_w = validation_w.values
print("validation set loaded")
validation_x = validation_x.reshape(len(validation_x),1,200)

uncertainty = False

def AnnealingStepLR(optimizer, lr):
    for param_group in optimizer.param_groups:
        param_group['lr'] = lr

def weighted_mse_loss(input, target, weight):
    return torch.sum(weight * (input - target) ** 2)

def train(epoch, uncertainty):

    model.train()
    total_loss = 0
    total_n = 0
    for batch_idx, (data_x, data_y) in enumerate(train_loader):

        data = data_x.to(device)
        label = data_y.to(device)
        #weight = data_w.to(device)

        mean, log_var = model(data)
        if uncertainty:
            loss = torch.mean(0.5 * torch.exp(-1 * log_var) * (10 * (label - mean.view(-1)) ** 2) + 0.5 * log_var)
        else:
            loss = F.mse_loss(mean.view(-1), label)

        loss.backward()
        optimizer.step()
        model.zero_grad()

        total_n += 1
        total_loss += loss.item()

        #print('batch loss: ', loss1.item(), loss.item())

    print('Train Epoch: {}, Loss: {:.4f}'.format(epoch, total_loss / total_n))

def val(epoch, uncertainty):

    model.eval()
    total_loss = 0
    total_n = 0
    for batch_idx, (data_x, data_y) in enumerate(val_loader):

        data = data_x.to(device)
        label = data_y.to(device)
        #weight = data_w.to(device)

        mean, log_var = model(data)
        if uncertainty:
            loss = torch.mean(0.5 * torch.exp(-1 * log_var) * (10 * (label - mean.view(-1)) ** 2) + 0.5 * log_var)
        else:
            loss = F.mse_loss(mean.view(-1), label)

        total_n += 1
        total_loss += loss.item()

    print('Val Epoch: {}, Loss: {:.4f}'.format(epoch, total_loss / total_n))

x_dim = 1
h_dim=200
output_dim = 1
epoch_num = 10000
batch_size = 512
learning_rate = 0.00001
seed = 400
clip = 10
print_every = 10
save_every = 10

torch.manual_seed(seed)

train_data = TensorDataset(torch.from_numpy(train_x).type(torch.FloatTensor),
                           torch.from_numpy(train_y).type(torch.FloatTensor))
val_data = TensorDataset(torch.from_numpy(validation_x).type(torch.FloatTensor),
                         torch.from_numpy(validation_y).type(torch.FloatTensor))

train_loader = DataLoader(train_data, batch_size=batch_size, shuffle=True)
val_loader = DataLoader(val_data, batch_size=batch_size, shuffle=False)

model = cnn_activity(x_dim, h_dim, batch_size, output_dim)
model.to(device)
model.fc_var.weight.data.zero_()
model.fc_var.bias.data.zero_()

if uncertainty:
    model.load_state_dict(torch.load('./saves/cnn_state_dict_270.pth', map_location=device))
    for param in model.parameters():
        param.requires_grad = False

    model.fc_var.weight.requires_grad = True
    model.fc_var.bias.requires_grad = True

    optimizer = torch.optim.Adam(filter(lambda p: p.requires_grad, model.parameters()), lr=learning_rate)
else:
    optimizer = torch.optim.Adam(model.parameters(), lr=learning_rate)

train_loss_list = []
test_loss_list = []

for epoch in range(1, epoch_num+1):
    train(epoch, uncertainty)

    # saving model
    if epoch % save_every == 0:
        fn = 'saves/normal/cnn_state_dict_' + str(epoch) + '.pth'
        torch.save(model.state_dict(), fn)
        print('Saved model to ' + fn)
        val(epoch, uncertainty)