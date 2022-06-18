unsigned long  MyMillis;
unsigned long  oldMillis = 10000;
unsigned long interval_ON = 240000;
unsigned long interval_OFF = 600000;
bool status1 ;
int status2 = 0 ;
#include <Controllino.h>
#define FAN CONTROLLINO_R9
#define HEATER CONTROLLINO_R8
float Probe_value;
//int Probe_treshold = 245; //teest
float Probe_treshold = 215; ///27C
bool heater_bool = true;

void setup() {
  pinMode(CONTROLLINO_AI1, INPUT);
  pinMode(CONTROLLINO_R9, OUTPUT);
  pinMode(CONTROLLINO_R8, OUTPUT);
  pinMode(CONTROLLINO_DO0, OUTPUT);
  pinMode(CONTROLLINO_DO1, OUTPUT);
  pinMode(CONTROLLINO_DO2, OUTPUT);
  pinMode(CONTROLLINO_DO3, OUTPUT);
  pinMode(CONTROLLINO_DO4, OUTPUT);
  pinMode(CONTROLLINO_DO5, OUTPUT);
  //// LOW = OFF. HIGH = ON
  digitalWrite(FAN, HIGH);
  digitalWrite(HEATER, HIGH);
  Serial.begin(115200);
}
void loop() {
  Probe_value = analogRead(CONTROLLINO_AI1);
  Serial.print("Probe target: ");
  Serial.println(Probe_treshold);
  Serial.print("Probe reading: ");
  Serial.println(Probe_value);
  float temp = Probe_value / 7.822878;
  Serial.print("Estimated temperature: ");
  Serial.println(temp);
  if  (Probe_value   >= Probe_treshold) {
    digitalWrite(HEATER, LOW);
    //digitalWrite(FAN, LOW);
    status1 = false;
    Serial.println("Heater OFF");
  }
  if  (Probe_value   < Probe_treshold - 2) {
    Serial.println("Heater ON");
    digitalWrite(HEATER, HIGH);
    //digitalWrite(FAN, HIGH);
  }
  Serial.print("Bool Enable: ");
  Serial.println(status1);
  Serial.println("----------------");
  status2++;
  if (status2 > 5) {
    status2 = 0;
  }
  delay(1000);
  if (status2 == 0) {
    digitalWrite(CONTROLLINO_DO0, HIGH);
    digitalWrite(CONTROLLINO_DO1, LOW);
    digitalWrite(CONTROLLINO_DO2, LOW);
    digitalWrite(CONTROLLINO_DO3, LOW);
    digitalWrite(CONTROLLINO_DO4, LOW);
    digitalWrite(CONTROLLINO_DO5, LOW);
  }
  if (status2 == 1) {
    digitalWrite(CONTROLLINO_DO0, LOW);
    digitalWrite(CONTROLLINO_DO1, HIGH);
    digitalWrite(CONTROLLINO_DO2, LOW);
    digitalWrite(CONTROLLINO_DO3, LOW);
    digitalWrite(CONTROLLINO_DO4, LOW);
    digitalWrite(CONTROLLINO_DO5, LOW);
  }
  if (status2 == 2) {
    digitalWrite(CONTROLLINO_DO0, LOW);
    digitalWrite(CONTROLLINO_DO1, LOW);
    digitalWrite(CONTROLLINO_DO2, HIGH);
    digitalWrite(CONTROLLINO_DO3, LOW);
    digitalWrite(CONTROLLINO_DO4, LOW);
    digitalWrite(CONTROLLINO_DO5, LOW);
  }
  if (status2 == 3) {
    digitalWrite(CONTROLLINO_DO0, LOW);
    digitalWrite(CONTROLLINO_DO1, LOW);
    digitalWrite(CONTROLLINO_DO2, LOW);
    digitalWrite(CONTROLLINO_DO3, HIGH);
    digitalWrite(CONTROLLINO_DO4, LOW);
    digitalWrite(CONTROLLINO_DO5, LOW);
  }
  if (status2 == 4) {
    digitalWrite(CONTROLLINO_DO0, LOW);
    digitalWrite(CONTROLLINO_DO1, LOW);
    digitalWrite(CONTROLLINO_DO2, LOW);
    digitalWrite(CONTROLLINO_DO3, LOW);
    digitalWrite(CONTROLLINO_DO4, HIGH);
    digitalWrite(CONTROLLINO_DO5, LOW);
  }
  if (status2 == 5) {
    digitalWrite(CONTROLLINO_DO0, LOW);
    digitalWrite(CONTROLLINO_DO1, LOW);
    digitalWrite(CONTROLLINO_DO2, LOW);
    digitalWrite(CONTROLLINO_DO3, LOW);
    digitalWrite(CONTROLLINO_DO4, LOW);
    digitalWrite(CONTROLLINO_DO5, HIGH);
  }
}
