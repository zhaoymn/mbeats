import torch
import torch.nn as nn
from torch.autograd import Variable
import torch.nn.functional as F


class cnn_activity(nn.Module):

    def __init__(self, x_dim, h_dim, batch_size, output_dim):

        super(cnn_activity, self).__init__()

        self.x_dim = x_dim
        self.h_dim = h_dim
        self.output_dim = output_dim
        self.conv1 = nn.Conv1d(1, 64, kernel_size=5, stride=1, padding=2)
        self.conv2 = nn.Conv1d(64, 64, kernel_size=5, stride=1, padding=2)
        self.conv3 = nn.Conv1d(64, 64, kernel_size=5, stride=1, padding=2)
        self.batch_size = batch_size
        self.dropout = nn.Dropout(0.2)
        self.fc_mean = nn.Linear(64*200, output_dim)
        self.fc_var = nn.Linear(64*200, output_dim)

    def forward(self, x):

        x = F.relu(self.conv1(x))
        x = F.relu(self.conv2(x))
        cnn_out = F.relu(self.conv3(x))
        cnn_out = self.dropout(cnn_out)
        mean = self.fc_mean(cnn_out.view(-1, 64*200))
        log_var = self.fc_var(cnn_out.view(-1, 64*200))
        return mean, log_var
