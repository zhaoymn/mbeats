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

function [frame, bytesBuffer] = parseBytes(Params, bytesBuffer,maxFramestoRead)

    frameStruct = struct('frame_num', 0, 'valid_frame',0, 'packet',[],'idxPacket',0,...
                'header',[],'vitalStats',[],...
                'rp',[], 'rp_cmplx',[]); %idxPacket = is the index of the last element that has been parsed/processed
   VITAL_SIGNS_OUTPUT_STATS = 6;
   VITAL_SIGNS_RANGE_PROFILE = 2; 
        
    % convert bytes array to string for searching
    bytesBufferStr = char(bytesBuffer);
        
    % search for all indices of magic word in buffer (frame packet start)
    startIdxMagicWord = strfind(bytesBufferStr', char([2 1 4 3 6 5 8 7]));
    numFramesAvailable = numel(startIdxMagicWord)-1; 
    
    % preallocate frame array depending on buffer size and limitFrame flag
    if(maxFramestoRead == 0 || maxFramestoRead > numFramesAvailable)
        maxFramestoRead = numFramesAvailable;
    end
    frame(maxFramestoRead,1) = frameStruct;
    
    
    
    if (maxFramestoRead)
        for frNum=1:maxFramestoRead
            % get bytes for entire frame packet 
            frame(frNum).packet = bytesBuffer(startIdxMagicWord(frNum):startIdxMagicWord(frNum+1)-1);
            idxBytesBuffer = startIdxMagicWord(frNum+1)-1;
            
            % get header from packet
            frame(frNum).idxPacket = 0;
            [frame(frNum).header, validFrame, frame(frNum).idxPacket] = getFrameHeader(frame(frNum).packet,frame(frNum).idxPacket);
            frame(frNum).frame_num = frame(frNum).header.frameNumber;
            frame(frNum).valid_frame = validFrame;
            
            % get and parse TLV from packet message
            if(validFrame)
                for i=1:frame(frNum).header.numTLVs
                    % getTLV
                    [tlv, frame(frNum).idxPacket] = getTLV(frame(frNum).packet, frame(frNum).idxPacket);
                    
                    % parseTLV                   
                    switch tlv.type
                        case VITAL_SIGNS_OUTPUT_STATS
                            [frame(frNum).vitalStats] = getOutputStats(tlv.payload);
                    
                        case VITAL_SIGNS_RANGE_PROFILE
                            [frame(frNum).rp, frame(frNum).rp_cmplx] = getRangeProfile(tlv.payload, Params.dataPath.numRangeBinProcessed);
                                                          
                        otherwise
                            disp(['Unrecognized type: ' num2str(tlv.type)]);
                    end
                end
            else
                outputStatsBadFrame = struct('rangeBinIndexMax', -1,...
                    'rangeBinIndexPhase', -1,...
                    'maxVal', -1,...
                    'processingCyclesOut' , -1, ...
                    'rangeBinStartIndex' , -1, ...
                    'rangeBinEndIndex' , -1, ...
                    'unwrapPhasePeak_mm' , -1, ...
                    'outputFilterBreathOut' , -1, ...
                    'outputFilterHeartOut' , -1, ...
                    'heartRateEst_FFT' , -1, ...
                    'heartRateEst_FFT_4Hz' , -1, ...
                    'heartRateEst_xCorr' , -1, ...
                    'heartRateEst_peakCount' , -1, ...
                    'breathingRateEst_FFT' , -1, ...
                    'breathingRateEst_xCorr' , -1, ...
                    'breathingRateEst_peakCount' , -1, ...
                    'confidenceMetricBreathOut' , -1, ...
                    'confidenceMetricBreathOut_xCorr' , -1, ...
                    'confidenceMetricHeartOut' , -1, ...
                    'confidenceMetricHeartOut_4Hz' , -1, ...
                    'confidenceMetricHeartOut_xCorr' , -1, ...
                    'sumEnergyBreathWfm' , -1, ...
                    'sumEnergyHeartWfm' , -1, ...
                    'motionDetectedFlag' , -1, ...
                    'reserved', -1);
                frame(frNum).vitalStats = outputStatsBadFrame;
                frame(frNum).rp = zeros(Params.dataPath.numRangeBinProcessed*2,1); 
                frame(frNum).rp_cmplx = zeros(Params.dataPath.numRangeBinProcessed,1); 
            end
                 
        end
        if(idxBytesBuffer+1 < numel(bytesBuffer))
            bytesBuffer = bytesBuffer(idxBytesBuffer+1:end);
        else
            bytesBuffer = [];
        end
    end 
return



       