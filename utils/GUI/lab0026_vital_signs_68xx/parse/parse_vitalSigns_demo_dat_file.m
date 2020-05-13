%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 %
 %      (C) Copyright 2016 Texas Instruments, Inc.
 %
 %  Redistribution and use in source and binary forms, with or without
 %  modification, are permitted provided that the following conditions
 %  are met:
 %
 %    Redistributions of source code must retain the above copyright
 %    notice, this list of conditions and the following disclaimer.
 %
 %    Redistributions in binary form must reproduce the above copyright
 %    notice, this list of conditions and the following disclaimer in the
 %    documentation and/or other materials provided with the
 %    distribution.
 %
 %    Neither the name of Texas Instruments Incorporated nor the names of
 %    its contributors may be used to endorse or promote products derived
 %    from this software without specific prior written permission.
 %
 %  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 %  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 %  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 %  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 %  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 %  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 %  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 %  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 %  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 %  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 %  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 %
 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
 % Updatd 4/1/19
 % Changes: export to .xlsx, plots of HR and BR
 

 %% Inputs
USE_GUI_INPUT = 0; % 0 = edit in script

if(USE_GUI_INPUT)
    [cliCfgFileName cliCfgPathName] = uigetfile('*.cfg', 'Select CFG File');
    [dataFileName, dataPathName] = uigetfile( ...
    {'*.bin;*.txt;*.log;',...
    'Data Files (*.bin,*.txt,*.log)';...
   '*.*',  'All Files (*.*)'}, ...
   'Select data file');
else
    cliCfgPathName = 'G://icra_mbeats//lab0026_vital_signs_68xx//gui//build-VitalSignsRadar_Demo-Desktop_Qt_5_13_0_MSVC2017_64bit-Release//profiles//';
    %cliCfgPathName = 'G://icra_mbeats//lab0026_vital_signs_68xx//parse//';
    cliCfgFileName = '2.cfg';
    dataPathName = 'G://icra_exp//8-14//mmwave_Data//0//2//';
    dataFileName = 'dataOutputFromEVM.bin'; %'dataOutputFromEVM.bin' %use 'bin' for file type instead of 'hex_text';
end
s = strsplit(dataFileName,'.');
if(strcmp(s{2},'bin'))
    dataFileType = 'bin';
else
    dataFileType = 'hex_log';
end

%% parse cfg
[Params] = parseCfgFile([cliCfgPathName cliCfgFileName]);

%% read file
[bytesBuffer, bytesBufferLen, bytesAvailableFlag] = readVitalSignsDataFile2Buffer([dataPathName dataFileName], dataFileType);

%% parse bytes to frame
maxFramesToRead = 0; %0=read all available frames
[frame, remainderBytesBuffer] = parseBytes(Params, bytesBuffer,maxFramesToRead);


%% export to file
%NOTE no error checking to handle case where filename already exists. Will
%overwrite existing cells in the xlsx. Error will be thrown if file is
%open.
frame_num = [frame.frame_num];
v = [frame.valid_frame];
valid_fn = frame_num(v);

exportFilenameVitalStats = [dataPathName s{1} '_vitalstats.xlsx'];
exportFilenameRP = [dataPathName s{1} '_RP.xlsx'];
exportFilenameSummary = [dataPathName s{1} '_Summary.xlsx'];
t1 = struct2table([frame.vitalStats]);
tf = table(frame_num');
tf.Properties.VariableNames = {'frameNum'};
t1 = [tf t1];

writetable(t1,exportFilenameVitalStats);
xlswrite(exportFilenameRP,[frame.rp]', 'range_profile');
xlswrite(exportFilenameRP,[frame.rp_cmplx]', 'cmplx_range_profile');

% selected summary data
summaryData_tbl = table(valid_fn', t1.heartRateEst_FFT(v), t1.heartRateEst_xCorr(v), t1.heartRateEst_peakCount(v),...
    t1.breathingRateEst_FFT(v), t1.breathingRateEst_xCorr(v), t1.breathingRateEst_peakCount(v),  t1.outputFilterHeartOut(v), t1.outputFilterBreathOut(v));  
summaryData_tbl.Properties.VariableNames = {'Frame', 'HR_FFT_method_BPM', 'HR_Auto_correlation_method_BPM', 'HR_Peak_count_method_BPM', 'BR_FFT_method_BPM', 'BR_Auto_correlation_method_BPM','BR_Peak_count_method_BPM', 'Heart_Wfm_rad','Breath_Wfm_rad'};
writetable(summaryData_tbl,exportFilenameSummary);


%% example plots
allRP = [frame.rp]';
figure
imagesc(allRP)

figure

plot(valid_fn,t1.heartRateEst_FFT(v),'m-',valid_fn,t1.heartRateEst_xCorr(v),'c-', valid_fn, t1.heartRateEst_peakCount(v),'g-')
ylabel('Heart Rate [BPM]'), xlabel('Frame Number')
legend('FFT method', 'Auto correlation method', 'Peak count method')
title('Heart Rate Estimation');

figure
plot(valid_fn,t1.breathingRateEst_FFT(v),'m-',valid_fn,t1.breathingRateEst_xCorr(v),'c-', valid_fn, t1.breathingRateEst_peakCount(v),'g-')
ylabel('Breathing Rate [BPM]'), xlabel('Frame Number')
legend('FFT method', 'Auto correlation method', 'Peak count method')
title('Breathing Rate Estimation');

figure
plot(valid_fn,t1.outputFilterHeartOut(v),'b-')
ylabel('Heart Waveform [rad]'), xlabel('Frame Number')
title('Heart Waveform [rad]');

figure
plot(valid_fn,t1.outputFilterBreathOut(v),'b-')
ylabel('Breath Waveform [rad]'), xlabel('Frame Number')
title('Breath Waveform [rad]');
