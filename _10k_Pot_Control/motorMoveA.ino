void motorMoveA(int target)
{
  posA;
  potValA = analogRead(lineTrackA);
  posReadA = analogRead(lineTrackA);

  //Move backward if potValue greater than target
  if ( potValA > target)      // If position is greater than the target
  {  
    do 
    {
      posReadA = analogRead(lineTrackA);               //Read position
      int Speed=map (posA,posReadA, target, 255,0);    //Decrease PWM proportionally as target position nears
      analogWrite (enablePinA,Speed);
      digitalWrite (PinA1, HIGH);        
      digitalWrite (PinA2, LOW);
      potValA = analogRead(lineTrackA);    // Read positioning
      posA = potValA;        //Update position
    }
    while (posA > target);    // While position is greater than the target
  }


  //Move forward if potValue less than target
  if (potValA < target)            // If position is less than the target
  {
    do
    {
      posReadA = analogRead(lineTrackA);             //Read position
      int Speed=map (posA,posReadA, target,255,0);  //Decrease PWM proportionally as target position nears
      analogWrite (enablePinA,Speed);
      digitalWrite (PinA1, LOW);        
      digitalWrite (PinA2, HIGH);
      potValA = analogRead(lineTrackA);  //Read positioning
      posA = potValA;              //Update position
    }
    while
      (posA < target);        // While position is less than the target
  }

  // Stop the motor if on target
  if (potValA == target){
    digitalWrite (enablePinA,HIGH);
    digitalWrite (PinA1,HIGH);
    digitalWrite (PinA2,HIGH);
    return;
  }
}























































