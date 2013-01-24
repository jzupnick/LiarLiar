void motorStop()
{
  digitalWrite (enablePinA, LOW);
  digitalWrite (enablePinB, LOW);
  digitalWrite (PinA1,HIGH);
  digitalWrite (PinA2,HIGH);
  digitalWrite (PinB1,HIGH);
  digitalWrite (PinB2,HIGH);
  return;
}



