/* 
Auteur  : Rajith Rajathurai & Bavith Rajathurai
Date    : 1 decembre 2022
Titre   : TP3 - Cube de DELs 3D - Demo 2
*/

// Pins
const int column[] = {4,8,13,3,9,12,2,10,11};
int layer[] = {7,6,5};
int Time = 500;

void offLayers() { // Set OFF all layers after 500ms
  delay(Time);
  for(int rep=0;rep<3;rep++){ digitalWrite(layer[rep], LOW); }
}

void setup() {
  Serial.begin(9600);
  for(int num=0;num<9;num++){ pinMode(column[num], OUTPUT); digitalWrite(column[num], HIGH); }  // Set all columns to OUTPUT and ON
  for(int num=0;num<3;num++){ pinMode(layer[num],  OUTPUT); digitalWrite(layer[num],  LOW); }   // Set all layers  to OUTPUT and OFF
}

void loop() {
  for (int num=0;num<3;num++) { // Set ON layers from 1 to 3 with 500ms intervals
    digitalWrite(layer[num], HIGH);
    offLayers();
  }
    digitalWrite(layer[1], HIGH); // Set ON layer 2 for 500ms
    offLayers();
}
