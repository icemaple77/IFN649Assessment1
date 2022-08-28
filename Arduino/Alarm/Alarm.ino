// Defining frequency of each music note
#include "pitches.h"
const int led = LED_BUILTIN;
const int ledRed=1;
const int ledYellow=2;
const int ledGreen=3;
const int ledRed_s=12;
const int ledYellow_s=13;
const int ledGreen_s=14;
const int speaker=4;
const int ledPin = 11;
const float songSpeed = 1.0;

int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4, NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_G4, NOTE_F4
};


//note durations: 4 = quarter note, 8 = eight note, etc.
int noteDurations[] = {
  8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 2, 8, 8, 4, 4, 4, 4, 4, 8, 8, 4, 4, 4, 2, 
};


int arrivingdatabyte; 
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600); // Default communication rate of the Bluetooth module
  pinMode(led, OUTPUT);
  pinMode(ledRed,OUTPUT);
  pinMode(ledYellow,OUTPUT);
  pinMode(ledGreen,OUTPUT);
  pinMode(ledRed_s,OUTPUT);
  pinMode(ledYellow_s,OUTPUT);
  pinMode(ledGreen_s,OUTPUT);
  pinMode(speaker,OUTPUT);
  pinMode(ledPin, OUTPUT);
}

int songState=1;
int order;
void getOrder(){
  order=0;
  if (Serial.available()>0){
    order=Serial.read();}
  if (Serial1.available()>0){
    order=Serial1.read(); 
    }
   Serial1.println(order);
  }
  
void loop() {
  powerStatue();
  getOrder();
  switch (order) {
    case 49 :
      turnOffLED(ledGreen_s);
      turnOnLED(ledRed_s);
      Serial.println("Warning!RED！");
      Serial1.println("Warning!");
      delay(500);
      break;
    case 50:
      turnOffLED(ledGreen_s);
      turnOnLED(ledYellow_s);
      Serial.println("Warning!YELLOW！");
      Serial1.println("Warning!");
      delay(500);
      break;
    case 51:
      playSongChristmas(1);
      delay(100);
      break;
    default:
      turnOnLED(ledGreen_s);
      turnOffLED(ledYellow_s);
      turnOffLED(ledRed_s);
      Serial.println("there is no order for now");
      Serial1.println("there is no order for now");
      delay(100);
      break;
   }
  powerStatue();
}
void powerStatue(){
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(100);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(100);                  // wait for a second
  }
void turnOnLED(int LEDName){
  digitalWrite(LEDName, HIGH);
  delay(100);
  }
void turnOffLED(int LEDName){
  digitalWrite(LEDName, LOW);
  delay(100);
  }
void blink(int LEDName){
  turnOnLED(LEDName);
  delay(1000);
  turnOffLED(LEDName);
  delay(1000);
  }




























void playSongChristmas(int playState){

if (playState == 1) {

for (int thisNote = 0 ; thisNote < 25 ; thisNote++) { 
    int randomLight1 = random(1, 4);
    int randomLight2 = random(1, 4);
    int randomLight3 = random(1, 4);
     
    delay(100);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    
    digitalWrite (randomLight1, HIGH);
    digitalWrite (randomLight2, HIGH);
    
    digitalWrite (randomLight3, LOW);
    //digitalWrite (random(1, 4), LOW);
    
    
    int noteDuration = 1130/noteDurations[thisNote];
    tone (speaker, melody[thisNote], noteDuration);
    
    int pause = noteDuration * 1.275;
    delay (pause);
    
    noTone(speaker);

    }
}
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
}
