#include <Servo.h>
int a  = 2;
int b = 5;
int c  = 6;
int d  = 4;
int e = 7;
int f = 8;
int g = 3;
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
    delay(1000);
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
  displaynumber(voltagemesurate/10,5,10);
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
    displaynumber(voltagemesurate/10,5,10);
  }
 }
  if (digitalRead(shoot) == HIGH && loaded == true) {
    loaded = false;
  }
  // put your main code here, to run repeatedly:

}

void offnumber() {
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
void zero() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
}
void un() {
 digitalWrite(b,HIGH);
 digitalWrite(c,HIGH); 
}
void deux() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(d,HIGH);
}
void trois() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
}
void quatre() {
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
}
void cinq() {
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
}
void six() {
  digitalWrite(a,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
}
void sept() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
}
void huit() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void neuf() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
}
void displaydigit(int number) {
  if (number == 0) {
    zero();
  }
  if (number == 1) {
    un();
  }
  if (number == 2) {
    deux();
  }
  if (number == 3) {
    trois();
  }
  if (number == 4) {
    quatre();
  }
  if (number == 5) {
    cinq();
  }
  if (number == 6) {
    six();
  }
  if (number == 7) {
    sept();
  }
  if (number == 8) {
    huit();
  }
  if (number == 9) {
    neuf();
  }
}
void displaynumber(int value,int timenumber,int turnnumber) {
  int dizainedisplay = (value-(value%10))/10;
  int unitedisplay = value%10;
  for(int i = 0;i < 20;i++) {
  digitalWrite(unite,HIGH);
  displaydigit(unitedisplay);
  delay(timenumber);
  offnumber();
  digitalWrite(unite,LOW);
  digitalWrite(dizaine,HIGH);
  displaydigit(dizainedisplay);
  delay(timenumber);
  offnumber();
  digitalWrite(dizaine,LOW);
  }
  }
