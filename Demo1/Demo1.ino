/* 
Auteur  : Rajith Rajathurai & Bavith Rajathurai
Date    : 1 decembre 2022
Titre   : TP3 - Cube de DELs 3D - Demo 1
*/

// Pins
const int column[] = {4,8,13,3,9,12,2,10,11};
int layer[] = {7,6,5};

void setup() {
  Serial.begin(9600);
  for(int num=0;num<9;num++){ pinMode(column[num], OUTPUT); digitalWrite(column[num], HIGH); }  // Set all columns to OUTPUT and ON
  for(int num=0;num<3;num++){ pinMode(layer[num],  OUTPUT); digitalWrite(layer[num],  HIGH); }  // Set all layers  to OUTPUT and ON
}

void loop() {}
