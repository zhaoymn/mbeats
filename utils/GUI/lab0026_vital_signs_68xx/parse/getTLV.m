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
 
function [tlv, idx] = getTLV(framePacket, idx)
    word = [1 256 65536 16777216]';
    
    % size of the parameters; 0 = variable/unknown    
    tlvSize = struct('type',4, 'length',4, 'payload',0);
    
    % get fieldnames of frame header struct
    fnFrameHeader = fieldnames(tlvSize);
    
    tlv = struct();
    
    for i=1:numel(fnFrameHeader)
        % subindices for parsing to struct fields
        idxStart = idx+1;
        idxEnd = idxStart + tlvSize.(fnFrameHeader{i})-1;
        
        % parse to struct fields
        if(~strcmp(fnFrameHeader{i},'payload'))
            tlv.(fnFrameHeader{i}) = sum(framePacket(idxStart:idxEnd) .* word);
        else
            %TODO: The length value for the rp tlv is wrong. Temp fix
            %assign all remaining bytes in packet to payload then handle in
            %getRangeProfile
            if(tlv.type == 6)
                idxEnd = idxStart+tlv.length-1;
                tlv.payload = framePacket(idxStart:idxEnd);
            else %type = 2 is rp
                if(idxStart+tlv.length<numel(framePacket))
                    idxEnd = idxStart+tlv.length;
                else
                    idxEnd = numel(framePacket);
                end
                tlv.payload = framePacket(idxStart:idxEnd); 
            end
        end
        idx = idxEnd;
    end
    
return