
int ledPin = 13;                 // LED connected to digital pin 13

bool currentLed = 0;
bool tripped = 0;

int fillCount = 0;
int readingCount = 0;
#define counts 200
int currPos[counts];
unsigned long time[counts]; 


// copied from https://playground.arduino.cc/Main/PinChangeInterrupt

void pciSetup(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}


//ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
// {    
//     // Pins should all be High, if one is low, that should be our 
     // leading edge
//     currentLed = !currentLed;
//     digitalWrite(ledPin,currentLed);
// }
 
//ISR (PCINT1_vect) // handle pin change interrupt for A0 to A5 here
// {
//     digitalWrite(13,digitalRead(A0));
// }  

void checkPin(int pinno,int distance){
  if ((digitalRead(pinno) == 0)&tripped){
    currPos[fillCount] = distance;
    time[fillCount] = micros();
    fillCount = (fillCount+1)%counts;
  }
}


ISR (PCINT2_vect) // handle pin change interrupt for D0 to D7 here
 {
     // Pins should all be High, if one is low, that should be our 
     // leading edge
     checkPin(2,0);
     checkPin(3,150);
     checkPin(4,300);
     checkPin(5,450);
     checkPin(6,600);
     checkPin(7,750);

     currentLed = !currentLed;
     digitalWrite(ledPin,currentLed);

 }  

ISR (PCINT0_vect) // handle pin change interrupt for D0 to D7 here
 {
     // Pins should all be High, if one is low, that should be our 
     // leading edge
     checkPin(8,900);
     checkPin(9,1050);
     checkPin(10,1200);
     checkPin(11,1350);

     currentLed = !currentLed;
     digitalWrite(ledPin,currentLed);

 }  




void setup()
{
  Serial.begin(115200);
  fillCount = 0;
  readingCount = 0;
  tripped =0;
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  pinMode(0, INPUT_PULLUP);      
  pinMode(1, INPUT_PULLUP);      
  pinMode(2, INPUT_PULLUP);      
  pinMode(3, INPUT_PULLUP);      
  pinMode(4, INPUT_PULLUP);      
  pinMode(5, INPUT_PULLUP);      
  pinMode(6, INPUT_PULLUP);      
  pinMode(7, INPUT_PULLUP);      
  pinMode(8, INPUT_PULLUP);      
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pciSetup(2);
  pciSetup(3);
  pciSetup(4);
  pciSetup(5);
  pciSetup(6);
  pciSetup(7);
  pciSetup(8);
  pciSetup(9);
  pciSetup(10);
  pciSetup(11);

  delay(100);
  tripped=1;
  
  
  //Serial.println("----------------"); 
}

void loop()
{
 
  if (fillCount > readingCount){
    Serial.print(readingCount);
    Serial.print(",");
    Serial.print(currPos[readingCount]);
    Serial.print(",");
    Serial.println((time[readingCount]-time[0])/1000000.0,6);
    readingCount = readingCount+1;
  }
  if (Serial.available()){
    byte incomingByte = Serial.read();
    if (incomingByte == 'X'){
	//reset if we get a capital X
	readingCount = 0;
	fillCount = 0;
      }
  }

}




