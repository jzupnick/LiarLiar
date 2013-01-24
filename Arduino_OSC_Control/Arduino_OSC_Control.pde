//libraries needed for arduino communication
import processing.serial.*;
import ddf.minim.*;

//libraries needed for osc
import oscP5.*;
import netP5.*;

Serial arduinoPort;        //  Set arduinoPort as serial connection
OscP5 oscP5;
NetAddress myRemoteLocation;

Minim minim;
AudioSnippet sample1;
AudioSnippet sample2;
AudioPlayer sample3;
AudioPlayer sample4;
AudioPlayer sample5;
AudioPlayer sample6;
AudioPlayer sample7;
AudioPlayer sample8;
AudioPlayer sample9;
AudioPlayer sample10;
AudioPlayer sample11;
AudioPlayer sample12;
AudioPlayer sample13;
AudioPlayer sample14;
AudioPlayer sample15;
AudioPlayer sample16;
AudioPlayer sample17;
AudioPlayer sample18;
AudioPlayer sample19;
AudioPlayer sample20;
AudioPlayer sample21;
AudioPlayer sample22;

//set/change port numbers here
int incomingPort = 8000;
int outgoingPort = 9000;

//set/change the IP address that the OSC data is being sent to
//127.0.0.1 is the local address (for sending osc to an application on the same computer)
String ipAddress = "127.0.0.1";

int truthVal;  //truthValue
int sampleVal;  //sampleValue
String addr;
String noseDir;
String sampleNum;

void setup() 
{
  size(100, 100);
  background(0);
  frameRate(20);

  /* start oscP5, listening for incoming messages at port 8000 */
  //for INCOMING osc messages
  oscP5 = new OscP5(this, incomingPort); //port number set above

  arduinoPort = new Serial(this, Serial.list()[4], 57600);  //port 4 is Arduino via USB

  minim = new Minim(this);
  
  // Load soundbite files
  sample1 = minim.loadSnippet( "1.mp3");
  sample2 = minim.loadSnippet( "2.mp3");
  sample3 = minim.loadSnippet( "3.mp3");
  sample4 = minim.loadSnippet( "4.mp3");
  sample5 = minim.loadSnippet( "5.mp3");
  sample6 = minim.loadSnippet( "6.mp3");
  sample7 = minim.loadSnippet( "7.mp3");
  sample8 = minim.loadSnippet( "8.mp3");
  sample9 = minim.loadSnippet( "9.mp3");
  sample10 = minim.loadSnippet( "10.mp3");
  sample11 = minim.loadSnippet( "11.mp3");
  sample12 = minim.loadSnippet( "12.mp3");
  sample13 = minim.loadSnippet( "13.mp3");
  sample14 = minim.loadSnippet( "14.mp3");
  sample15 = minim.loadSnippet( "15.mp3");
  sample16 = minim.loadSnippet( "16.mp3");
  sample17 = minim.loadSnippet( "17.mp3");
  sample18 = minim.loadSnippet( "18.mp3");
  sample19 = minim.loadSnippet( "19.mp3");
  sample20 = minim.loadSnippet( "20.mp3");
}

void draw() 
{
  serialWrite();
}

// Incoming osc message are forwarded to the following oscEvent method. Write to the arduino here--------
// This method is called for each OSC message recieved
void oscEvent(OscMessage theOscMessage) 
{
  //Convert the OSC address pattern to a string
  addr = theOscMessage.addrPattern();

  //Parse the nose direction off the address pattern
  noseDir = addr.substring(1, 6);  
  //Convert to truthValue for serialWrite
  truthVal(noseDir);  

  //Parse the sample number off the address pattern
  sampleNum = addr.substring(7,9);
  //Convert to an integer
  sampleVal = int(sampleNum);

  //Play the selected sample
  playSample();
}

