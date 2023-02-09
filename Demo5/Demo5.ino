/* 
Date    : 1 decembre 2022
Titre   : TP3 - Cube de DELs 3D - Demo 5
*/

// Pins
const int column[] = {4,8,13,2,9,12,3,10,11}; 
const int layer[]  = {7,6,5};
// Times
int _2ms = 2;
int _25ms = 25;
int _150ms = 150;
int _250ms = 250;
int _500ms = 500;
int _1000ms = 1000;
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

void setup() {
  Serial.begin(9600);
  for(int num=0;num<9;num++){ pinMode(column[num], OUTPUT); digitalWrite(column[num], LOW); }  // Set all columns to OUTPUT and OFF
  for(int num=0;num<3;num++){ pinMode(layer[num],  OUTPUT); digitalWrite(layer[num],  LOW); }  // Set all layers  to OUTPUT and OFF
}

void All(int State) { AllColumns(State); AllLayers(State); } // Set all columns/layers  to picked State

void AllColumns(int State) { for(int num=0;num<9;num++) { digitalWrite(column[num], State); } } // Set all columns to picked State

void AllLayers(int State)  { for(int num=0;num<3;num++) { digitalWrite(layer[num],  State); } } // Set all layers  to picked State

void blinkLED(int LedArray[],int delayTime) { // Blinks 1 Column for selected delayTime 
  AllLayers(HIGH);
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

void LayerSpin(int SpinTime) { // Does 1 full clockwise rotation while all layers are active
  blinkSide(D8,D5,D2,SpinTime,_2ms);
  blinkSide(D9,D5,D1,SpinTime,_2ms);
  blinkSide(D4,D5,D6,SpinTime,_2ms);
  blinkSide(D7,D5,D3,SpinTime,_2ms);
}

void loop() { 
  Serial.println("Restarting.."); All(LOW); delay(_25ms);
  // Animation 1--------------------------------------------------------------------------------------------------------
  Serial.println("Animation 1");
  
  for(int num=0;num<3;num++){ 
    digitalWrite(layer[num], HIGH);
    for(int num=0;num<9;num++){ digitalWrite(column[num], HIGH); delay(_25ms); digitalWrite(column[num], LOW); } // blinks LEDs individually for each layers
    digitalWrite(layer[num], LOW);
    }
    
  // Animation 2--------------------------------------------------------------------------------------------------------
  Serial.println("Animation 2");
  AllColumns(HIGH); 
  AllLayers(LOW);

  for(int num=0;num<=1;num++){ // Does animation for 2 times
    for(int num=0;num<=2;num++){                              // Blinks layer from 1 to 3 for 150ms each
      digitalWrite(layer[num], HIGH);
      if (num == 2) { delay(_150ms/2); } else { delay(_150ms); } 
      digitalWrite(layer[num], LOW); 
      }
    for(int num=2;num>=0;num--){                              // Blinks layer from 3 to 1 for 150ms each
      digitalWrite(layer[num], HIGH);
      if (num == 0) { delay(_150ms/2); } else { delay(_150ms); } 
      digitalWrite(layer[num], LOW);
    }
  }

  // Animation 3--------------------------------------------------------------------------------------------------------
  Serial.println("Animation 3");
  AllLayers(LOW);
  AllColumns(HIGH);
  
  for(int num=0;num<3;num++){ digitalWrite(layer[num], HIGH); delay(_250ms); }     // Blinks layer from 1 to 3 for 250ms each while all Column are ON
  for(int num=0;num<9;num++){ digitalWrite(column[num], LOW); delay(_250ms-150); } // OFF all column with 100ms intervals
  delay(_250ms);

  // Animation 4--------------------------------------------------------------------------------------------------------
  Serial.println("Animation 4");
  
    for(int rep=0;rep<=1;rep++){ // Does animation for 2 times
    digitalWrite(layer[0], HIGH);
    for(int num=0;num<9;num++){ digitalWrite(column[num], HIGH); delay(_25ms); } // ON  all column with 25ms intervals on Layer 1 only
    for(int num=0;num<9;num++){ digitalWrite(column[num], LOW);  delay(_25ms); } // OFF all column with 25ms intervals on Layer 1 only
    digitalWrite(layer[0], LOW);
    digitalWrite(layer[1], HIGH);
    for(int num=9;num>0;num--){ digitalWrite(column[num], HIGH); delay(_25ms); } // ON  all column with 25ms intervals on Layer 2 only
    for(int num=9;num>0;num--){ digitalWrite(column[num], LOW);  delay(_25ms); } // OFF all column with 25ms intervals on Layer 2 only
    digitalWrite(layer[1], LOW);
    digitalWrite(layer[2], HIGH);
    for(int num=0;num<9;num++){ digitalWrite(column[num], HIGH); delay(_25ms); } // ON  all column with 25ms intervals on Layer 3 only
    for(int num=0;num<9;num++){ digitalWrite(column[num], LOW);  delay(_25ms); } // OFF all column with 25ms intervals on Layer 4 only
    digitalWrite(layer[2], LOW);
  }
  
  // Animation 5--------------------------------------------------------------------------------------------------------
  Serial.println("Animation 5");

  for(int rep=0;rep<=3;rep++){ // Does animation for 4 times
    LayerSpin(_150ms);
  }
  blinkSide(D8,D5,D2,_150ms,_2ms);
}
