void truthVal(String val) {

   if ( noseDir.equals("o/tru")){
    truthVal = 1;    //Set truthVal to 1
  } if (noseDir.equals( "o/lie")) {  
    truthVal = 2;  //Set truthVal to 2
  }
   if (noseDir.equals("o/mid"))  {
    truthVal = 3;  //Set truthVal to 3
  } 
  
  if ( noseDir.equals("r/tru")){
    truthVal = 4;    //Set truthVal to 4
  } if (noseDir.equals( "r/lie")) {  
    truthVal = 5;  //Set truthVal to 5
  }
   if (noseDir.equals("r/mid"))  {
    truthVal = 6;  //Set truthVal to 6
  } 
}
