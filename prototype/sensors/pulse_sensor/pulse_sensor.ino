#include<dht.h>
dht d1;
#include<ArduinoJson.h>
#include <ESP8266WiFi.h>                                                
#include <FirebaseArduino.h>                                            

#define FIREBASE_HOST "final-try-73ff3.firebaseio.com"                         
#define FIREBASE_AUTH "j7zAzS6t5HWF4b3gFOht4dLtxiySb4Ktsy1I0zSz"                    
#define WIFI_SSID "KING"                                          
#define WIFI_PASSWORD "12345678"                                   
String fire1 ;  
 
void setup() 
{ 
  Serial.begin(115200);
  delay(1000);   
  pinMode(A0,INPUT);   
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                      
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("IP Address is : ");
  Serial.println(WiFi.localIP());                                                      
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);  
  Firebase.setString("BPM", "0");  
  Firebase.setString("Temp","0");  
}

void loop() {
  int readData = d1.read11(D4);
  float t = d1.temperature; 
  t=(t*9)/5+40+2.4;
  String T=String(t);
  int b=analogRead(A0)/8-10;
  if(b>70)
{ String A=String(b);
 Serial.println(A);
 Firebase.setString("BPM",A);
 
 
}
Serial.print("Temperature: ");
Serial.println(T);
Firebase.setString("Temp",T);
delay(5000);
}
