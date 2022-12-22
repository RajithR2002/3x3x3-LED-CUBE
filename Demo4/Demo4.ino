/* 
Auteur  : Rajith Rajathurai & Bavith Rajathurai
Date    : 1 decembre 2022
Titre   : TP3 - Cube de DELs 3D - Demo 4
*/

// Pins
const int column[] = {4,8,13,2,9,12,3,10,11}; 
int layer[] = {7,6,5};
// Times
int Time = 2;
int Time2 = 500;
int Time3 = 1000;
// LEDs
int D1[]  = {layer[0],column[0]};
int D2[]  = {layer[0],column[1]};
int D3[]  = {layer[0],column[2]};
int D4[]  = {layer[0],column[3]};
int D5[]  = {layer[0],column[4]};
int D6[]  = {layer[0],column[5]};
int D7[]  = {layer[0],column[6]};
int D8[]  = {layer[0],column[7]};
int D9[]  = {layer[0],column[8]};

int D10[] = {layer[1],column[0]};
int D11[] = {layer[1],column[1]};
int D12[] = {layer[1],column[2]};
int D13[] = {layer[1],column[3]};
int D14[] = {layer[1],column[4]};
int D15[] = {layer[1],column[5]};
int D16[] = {layer[1],column[6]};
int D17[] = {layer[1],column[7]};
int D18[] = {layer[1],column[8]};

int D19[] = {layer[2],column[0]};
int D20[] = {layer[2],column[1]};
int D21[] = {layer[2],column[2]};
int D22[] = {layer[2],column[3]};
int D23[] = {layer[2],column[4]};
int D24[] = {layer[2],column[5]};
int D25[] = {layer[2],column[6]};
int D26[] = {layer[2],column[7]};
int D27[] = {layer[2],column[8]};

void setup() {
  Serial.begin(9600);
  for(int num=0;num<9;num++){ pinMode(column[num], OUTPUT); digitalWrite(column[num], LOW); }  // Set all columns to OUTPUT and OFF
  for(int num=0;num<3;num++){ pinMode(layer[num],  OUTPUT); digitalWrite(layer[num],  LOW); }  // Set all layers  to OUTPUT and OFF
  blinkLED(D14,Time3); // Middle LED blinks for 1000ms
}

void All(int State) {
  for(int num=0;num<9;num++){ digitalWrite(column[num], State); }   // Set all columns to picked State
  for(int num=0;num<3;num++){ digitalWrite(layer[num],  State); }   // Set all layers  to picked State
}

void blinkLED(int LedArray[],int delayTime) { // Blinks 1 Led for seletected delayTime
  digitalWrite(LedArray[0], HIGH);
  digitalWrite(LedArray[1], HIGH);
  delay(delayTime);
  All(LOW);
}

void blinkSide(int Led1,int Led2, int Led3, int fullDuration, int LedDuration) { // Blinks 3 Leds in a loop
  for(int rep=fullDuration;rep>=0;rep -= LedDuration*3) {
    blinkLED(Led1,LedDuration);
    blinkLED(Led2,LedDuration);
    blinkLED(Led3,LedDuration);
    }
}

void loop() {
  blinkSide(D1,D11,D21,Time2,Time);  // A Side blinks for 500ms
  blinkSide(D9,D17,D25,Time2,Time);  // B Side blinks for 500ms
  blinkSide(D7,D13,D19,Time2,Time);  // C Side blinks for 500ms
  blinkSide(D3,D15,D27,Time2,Time);  // D Side blinks for 500ms
  blinkSide(D19,D23,D27,Time2,Time); // E Side blinks for 500ms
  blinkSide(D3,D5,D7,Time2,Time);    // F Side blinks for 500ms
}
