s = setSerial();
disp("Drop the object and press a key");
pause;
M = ballDrop(s)
save('myfile.m','M','-ascii')


