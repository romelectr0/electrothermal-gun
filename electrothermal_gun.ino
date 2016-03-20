#include <Servo.h>
int number[][10] = {{2,4,5,6,7,8},{5,6},{2,5,3,7,4},{2,5,3,6,4},{8,3,5,6},{2,8,3,6,4},{2,8,3,7,6,4},{2,5,6},{2,2,4,5,6,7,8},{2,3,5,8,6,4}}; 
int mesureinput = A3;
int dizaine = A1;
int unite = A2;
int load = 11;
int mod = 13;
int voltageselect = A0;
int shoot = 12;
int loader = 10;
int unload = 9;
boolean semiauto = false;
boolean loaded = false;
boolean servo = true;
int voltagetoload;
int voltagemesurate;
int resistor1;
int resistor2;
void setup() {
  // put your setup code here, to run once:
  for(int i = 0;i<12;i++) {
    if(i<9) {
    pinMode(i+2,OUTPUT);
    }
    else {
    pinMode(i+2,INPUT);  
    } 
  }
  pinMode(dizaine,OUTPUT);
  pinMode(unite,OUTPUT);
 }
void loop() {
  voltagemesurate = ((analogRead(mesureinput)*5)/1024)/(resistor2/(resistor1+resistor2));
  displaynumber(voltagemesurate/10,40,80);
  if (digitalRead(mod) == HIGH) {
    semiauto = !semiauto;
  }
  if ((semiauto == true && loaded == false)|| (digitalRead(load) == HIGH && semiauto == false)) {
    digitalWrite(loader,HIGH);
   while(true) {    
   if (voltagemesurate >= voltagetoload) {
      digitalWrite(loader,LOW);
      loaded = true;
      break;
   }
    voltagemesurate = ((analogRead(mesureinput)*5)/1024)/(resistor2/(resistor1+resistor2));
    displaynumber(voltagemesurate/10,40,80);
  }
 }
  if (digitalRead(shoot) == HIGH && loaded == true) {
    loaded = false;
  }
  // put your main code here, to run repeatedly:

}
void displaynumber(int value,int timenumber,int timedisplay) {
  int dizainedisplay = (value-(value%10))/10;
  int unitedisplay = value%10;
  int actualtime = millis();
  while(true) {
  digitalWrite(dizaine,HIGH);
  for(int y  = 0;y < timenumber;y++) {
  for(int i = 0;i < sizeof(number[dizainedisplay]);i++) {
    digitalWrite(number[dizainedisplay][i],HIGH);
  }
  delay(1);
  }
  offnumber();
  digitalWrite(dizaine,LOW);
  digitalWrite(unite,HIGH);
  for(int y = 0;y < timenumber;y++) {
  for(int i = 0;i < sizeof(number[unite]);i++) {
    digitalWrite(number[unite][i],HIGH);
  }
  delay(1);
  }
  offnumber();
  digitalWrite(unite,LOW);  
  if (actualtime == timedisplay) {
    offnumber();
    digitalWrite(unite,LOW);
    digitalWrite(dizaine,LOW);
    break;
  }
 }
}

void offnumber() {
  for(int i = 0;i<7;i++) {
    digitalWrite(i+2,LOW);
  }
}
