unsigned long  MyMillis;
unsigned long  oldMillis=180000;
unsigned long interval = 60000;
#include <Controllino.h>
#define FAN CONTROLLINO_R9
#define HEATER CONTROLLINO_R8
float Probe_value;
//int Probe_treshold = 245; //teest
int Probe_treshold = 223; ///27C

bool heater_bool=true;

void setup() {
  pinMode(CONTROLLINO_AI1, INPUT);
  pinMode(CONTROLLINO_R9, OUTPUT);
  pinMode(CONTROLLINO_R8, OUTPUT);
 //// LOW = OFF. HIGH = ON
  digitalWrite(FAN, HIGH);
  digitalWrite(HEATER, HIGH);
  Serial.begin(9600);
}
void loop() {
  MyMillis = millis();
  if (MyMillis > oldMillis+interval) {
   heater_bool = true;
  }
    if (MyMillis > oldMillis+interval+interval) {
   heater_bool = false;
    oldMillis =  MyMillis + interval;
  }
  
  // put your main code here, to run repeatedly:
  Probe_value = analogRead(CONTROLLINO_AI1);
  Serial.println(Probe_value);
  if  (Probe_value   >= Probe_treshold) {
    digitalWrite(HEATER, LOW);
    Serial.println("Thermostat OFF");
  }
  if  (Probe_value   < Probe_treshold-1) {
     Serial.println("Thermostat ON");
    if (heater_bool==true){
    digitalWrite(HEATER, HIGH);
    Serial.println("heater_bool=True");
    }
     if (heater_bool==false){
    digitalWrite(HEATER, LOW);
    Serial.println("heater_bool=False");
    }
  }
  delay(1000);
}
