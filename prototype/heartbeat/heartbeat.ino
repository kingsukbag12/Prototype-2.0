
void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  
 
    // send the value of analog input 0:
      String a=String(analogRead(A0)/7);
      
      Serial.println(a);
 
  //Wait for a bit to keep serial data from saturating
 delay(5000);
}
