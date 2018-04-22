#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


#define WIFI_SSID       "PED"
#define WIFI_PASSWORD   "12345678"
#define FIREBASE_HOST   "webauth-38bc1.firebaseio.com"
#define FIREBASE_AUTH   "0FN1SIlY3CtL3F4nJfl38hQrKjYGyRZ1v234eRYM"


int LED = D1;
int var = 0;
void setup() {
  Serial.begin(250000);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(250);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  pinMode(LED, OUTPUT);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setInt("status", 0); 
}
void loop() {
  lighthigh();
  lightlow();
}
void lighthigh(){
  delay(100);
  if (Firebase.getInt("status") != 0){
    digitalWrite(LED, 1);
    delay(10000);
  }
}

void lightlow(){
  delay(100);
  if (Firebase.getInt("status") != 0){
    Firebase.setInt("status", 0);
    digitalWrite(LED, 0);
  }
}

