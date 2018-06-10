function s = setSerial()
 s = serial('com3');
 set(s,'BaudRate',115200);
 fopen(s);
 flushinput(s);
end

% - Drop ball now
% M = ballDrop(s)