#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


#define WIFI_SSID       "PED"
#define WIFI_PASSWORD   "12345678"
#define FIREBASE_HOST   "webauth-38bc1.firebaseio.com"
#define FIREBASE_AUTH   "0FN1SIlY3CtL3F4nJfl38hQrKjYGyRZ1v234eRYM"


int LED = D1;   //Setting
int Voice = D3;
int i;

void setup() {
  Serial.begin(250000);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); //begin connect WIFI
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(250);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  pinMode(LED, OUTPUT); //Set LED PinMode
  pinMode(Voice, OUTPUT); //Set Voice PinMode
  digitalWrite(Voice, HIGH); //Set voice default
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); //Connect to firebase
  Firebase.setInt("status", 0); //Set default status
}
void loop() {
  lighthigh(); //Unlock function
  lightlow(); //Lock function
}
void lighthigh(){
  delay(100);
  if (Firebase.getInt("status") != 0){ //Recieve status from fireabse
    digitalWrite(LED, 1); //Unlock
    for (i = 0; i <= 10; i = i+1){ //Delay with Alert while its Unlock
      digitalWrite(Voice, 0);
      delay(1000);
      digitalWrite(Voice, 1);
      delay(1000);
  }
  }
}

void lightlow(){
  delay(100);
  if (Firebase.getInt("status") != 0){ //Auto Lock after delay
    Firebase.setInt("status", 0); //Set status to firebase
    digitalWrite(LED, 0); //Lock
  }
}
