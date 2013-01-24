void motorMoveB(int target)
{
  posB;
  potValB = analogRead(lineTrackB);
  posReadB = analogRead(lineTrackB);


  //Move backward if potValue greater than target
  if ( potValB > target)                  // If position is greater than the target
  {  
    do 
    {  
      posReadB = analogRead(lineTrackB);         //Read position
      int Speed=map (posB,posReadB, target, 255,0);  //Decrease PWM proportionally as target position nears
      analogWrite (enablePinB,Speed);
      digitalWrite (PinB1, HIGH);        
      digitalWrite (PinB2, LOW);
      potValB = analogRead(lineTrackB);    //Read positioning
      posB = potValB;                        //Update position
    } 
    while (posB > target);        // While position is greater than the target
  }


  //Move forward if potValue less than target
  if (potValB < target)      // If position is less than the target
  {
    do
    {
      posReadB = analogRead(lineTrackB);     //Read position
      int Speed=map (posB,posReadB, target,255,0);  //Decrease PWM proportionally as target position nears
      analogWrite (enablePinB,Speed);
      digitalWrite (PinB1, LOW);        
      digitalWrite (PinB2, HIGH);
      potValB = analogRead(lineTrackB);    //Read position
      posB = potValB;                      //Update position
    }
    while
      (posB < target);   // While position is less than the target
  }

  // Stop the motor if on target
  if (potValB == target){
    digitalWrite (enablePinB,HIGH);
    digitalWrite (PinB1,HIGH);
    digitalWrite (PinB2,HIGH);
    return;
  }
}

