/* 
Auteur  : Rajith Rajathurai & Bavith Rajathurai
Date    : 1 decembre 2022
Titre   : TP3 - Cube de DELs 3D - Demo 3
*/

// Pins
const int column[] = {4,8,13,2,9,12,3,10,11}; 
int layer[] = {7,6,5};
// LEDs
int D1[]  = {layer[0],column[0]};
int D11[] = {layer[1],column[1]};
int D21[] = {layer[2],column[2]};

int Time = 2;

void setup() {
  Serial.begin(9600);
  for(int num=0;num<9;num++){ pinMode(column[num], OUTPUT); digitalWrite(column[num], LOW); }    // Set all columns to OUTPUT and OFF
  for(int num=0;num<3;num++){ pinMode(layer[num],  OUTPUT); digitalWrite(layer[num],  LOW); }    // Set all layers  to OUTPUT and OFF
}

void offAll() {
  for(int num=0;num<9;num++){ digitalWrite(column[num], LOW); }   // Set OFF all columns
  for(int num=0;num<3;num++){ digitalWrite(layer[num],  LOW); }   // Set OFF all layers
}

void onLED(int LEDArray[]) { // Set ON selected LED only for 2ms
  digitalWrite(LEDArray[0], HIGH);
  digitalWrite(LEDArray[1], HIGH);
  delay(Time);
  offAll();
}

void loop() {
onLED(D1);  // Set ON LED D1
onLED(D11); // Set ON LED D11
onLED(D21); // Set ON LED D21
}
