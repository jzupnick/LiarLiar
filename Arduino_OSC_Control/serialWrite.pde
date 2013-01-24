//write serial data to for the Arduino to read
void serialWrite() {
  if (truthVal == 1) //if the osc message reads obama truth
  {  
    arduinoPort.write(97);
  }

  else if (truthVal == 2) //if the osc message reads obama lie
  {  
    arduinoPort.write(98);
  }

  else if (truthVal == 3) //if the osc message reads obama half-truth
  {  
    arduinoPort.write(99);
  }
  
  else if (truthVal == 4) //if the osc message reads romeny truth
  {  
    arduinoPort.write(100);
  }
  
  else if (truthVal == 5) //if the osc message romney lie
  {  
    arduinoPort.write(101);
  }
  
  else if (truthVal == 6) //if the osc message reads romney half-truth
  {  
    arduinoPort.write(102);
  }
}

