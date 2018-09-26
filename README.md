# ArduinoGravity
Arduino gravity experiment

This includes matlab code to look at the output, but the basics are this:

Use the Arduino COM port 115200

Timer is started when any beam is crossed, The top beam is 0mm and every rung below that is the offset from the top
Each time and distance is printed out when the object crosses the beam, so you could do from bottom up, or have an oscilliating object.

To reset the timer - write a capital X back to the serial port, and the process starts all over again. 

The matlab code gives a sample of capturing the output from the serial port, plotting a graph, and then writing the output to a text file. 
