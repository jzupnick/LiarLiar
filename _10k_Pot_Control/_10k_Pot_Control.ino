//Many thanks to ash901226 who helped me with the code along the way
//Follow the development of this code at this forum thread:
//    http://arduino.cc/forum/index.php/topic,135074.0.html


//=====INITIALIZE PINS========

const int enablePinA = 11;    // motor 1/2 h-bridge enable pin
const int enablePinB = 3;    // motor 1/2 h-bridge enable pin

const int PinA1 = 10;    // H-bridge Pin A1 (pin 2) PWM
const int PinA2 = 9;    // H-bridge  Pin A2 (pin 7) PWM

const int PinB1 = 6;    // H-bridge Pin B1 (pin 15) PWM
const int PinB2 = 5;    // H-bridge  Pin B2 (pin 10) PWM


//For proper lineTrack readings, insert 2 to A5, 3 to 5V, 1 to GND
int lineTrackA = A5;    //line track for motor 1 position reading
int lineTrackB = A3;    //line track for motor 2 position reading

//For motor 1 position reading
int posA;      
int potValA;
int posReadA;

//For motor 2 position reading
int posB;
int potValB;
int posReadB;

int inByte = 0;   // for incoming serial data

//=============================

void setup(){

  Serial.begin(57600);    

  // set the line track as input
  pinMode(lineTrackA, INPUT);
  pinMode(lineTrackB, INPUT);

  //set the motor logic pins and enable pin as outputs
  pinMode(PinA1, OUTPUT);
  pinMode(PinA2, OUTPUT);
  pinMode(PinB1, OUTPUT);
  pinMode(PinB2, OUTPUT);
  pinMode(enablePinA, OUTPUT);
  pinMode(enablePinB, OUTPUT);
}

void loop() {

  //Read the positions from both motors
  potValA = analogRead(lineTrackA);
  posReadA = analogRead(lineTrackA);

  potValB = analogRead(lineTrackB);
  posReadB = analogRead(lineTrackB);

  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {

    // get incoming byte:
    inByte = Serial.read();

    switch (inByte) {          
    //Remember: cases are being read in ASCII format
    case 'a':    
      motorMoveA(0);      // truth - move motor 1 backwards
      break;
    case 'b':   
      motorMoveA(1023);   //lie - move motor 1 forward
      break;
    case 'c':    
      motorMoveA(512);    //half-truth - move motor 1 to the middle
      break;
    case 'd':    
      motorMoveB(0);      // truth - move motor 2 backwards
      break;
    case 'e':   
      motorMoveB(1023);   //lie - move motor 2 forward
      break;
    case 'f':   
      motorMoveB(512);    //half-truth - move motor 2 to the middle
      break;

    default:
      motorStop();      //stop motor
      break;
    }
  }
} 

















































