function M = ballDrop(s)
M = [];
while s.BytesAvailable()
    A = fscanf(s,"%d,%d,%f");
    M = [M;A'];
end
fprintf(s,"X") %reset trigger
end

% s = serial('com3')
% set(s,'BaudRate',115200)
% fopen(s)
% - Drop ball now
% M = ballDrop(s)   - col1 = number, col2 distance in mm, col3 = time in seconds 