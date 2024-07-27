#include <ESP32Servo.h>
#include <Ps3Controller.h>

Servo capitnt;
Servo capitkanan;
Servo capitkiri;
Servo capitasal;

int enkanan = 32;
int enkiri = 18;

int inkanan1 = 25;
int inkanan2 = 14;

int inkiri1 = 2;
int inkiri2 = 4;

int pinnt = 33;
int pinkanan = 26; 
int pinkiri = 27;
int pinasal = 21;
 

void setup() {
  Serial.begin(115200);

  capitkiri.attach(pinkiri);
  capitkanan.attach(pinkanan);
  capitnt.attach(pinnt);
  capitasal.attach(pinasal);
 
//  capitnt.setPeriodHertz(50);    // standard 50 hz servo
//  capitnt.attach(pinnt, 544, 2000); // attaches the servo on pin 18 to the servo object

//  capitkiri.setPeriodHertz(50);    // standard 50 hz servo
//  capitkiri.attach(pinkiri, 544, 2000); // attaches the servo on pin 18 to the servo object
  
//  capitkanan.setPeriodHertz(50);    // standard 50 hz servo
//  capitkanan.attach(pinkanan, 544, 2000); // attaches the servo on pin 18 to the servo object
    
  pinMode(enkanan, OUTPUT);
  pinMode(enkiri, OUTPUT);
  pinMode(inkanan1, OUTPUT);
  pinMode(inkanan2, OUTPUT);
  pinMode(inkiri1, OUTPUT);
  pinMode(inkiri2, OUTPUT);

  Ps3.begin("cc:7b:5c:26:c5:66");
  Ps3.attach(notify);
}

void loop() {
  
//    Serial.println("l2 tertekan");
//  else(
//    berhenti();
//}
}

void notify(){
  if( Ps3.event.button_down.up ){
    maju();
  }
  else if (Ps3.event.button_up.up){
    berhenti();
  }
  else if (Ps3.event.button_down.down){
    mundur();
  }
  else if (Ps3.event.button_up.down){
    berhenti();
  }
  else if (Ps3.event.button_down.right){
    majukanan();
  }
  else if (Ps3.event.button_up.right){
    berhenti();
  }
  else if (Ps3.event.button_down.left){
    majukiri();
  }
  else if(Ps3.event.button_up.left){
    berhenti();
  }
  else if (Ps3.event.button_down.cross){
    berhenti();
  }
  else if (Ps3.event.button_up.cross){
    Serial.println("x lepas");
  }
  else if (Ps3.event.button_down.l1){
    capitnaik();
    Serial.println("l1 tertekan");
  }
  else if (Ps3.event.button_up.l1){
    Serial.println("l1 lepas");
  }
  else if (Ps3.event.button_down.l2){
    capitturun();
    Serial.println("l2 tertekan");
    }
  else if (Ps3.event.button_up.l2){
    Serial.println("l2 lepas");
  }
  else if (Ps3.event.button_down.square){
    capittutup();
    }
   else if (Ps3.event.button_up.square){
    Serial.println("kotak lepas");
   }
  else if (Ps3.event.button_down.triangle){
    capitbuka();
  }
  else if (Ps3.event.button_up.triangle){
    Serial.println("Segitiga lepas");
  }
}


void capitbuka(){
  capitkiri.write(180);
  capitkanan.write(0);
  Serial.println("buka");
//  delay(1000);
}

void capittutup(){
  capitkiri.write(90);
  capitkanan.write(90);
  Serial.println("tutup");
//  delay(1000);
}

void capitnaik(){
  capitnt.write(90);
//  delay(1000);
}

void capitturun(){
  capitnt.write(0);
//  delay(1000);
}

//void kanan(){
//  digitalWrite(inkanan1, HIGH);
//  digitalWrite(inkanan2, LOW);
//  digitalWrite(inkiri1, HIGH);
//  digitalWrite(inkiri2, LOW);
//
//  analogWrite(enkanan, 1000);
//  analogWrite(enkiri, 1000);
//}
//
//void kiri(){
//  digitalWrite(inkanan1, LOW);
//  digitalWrite(inkanan2, HIGH);
//  digitalWrite(inkiri1, LOW);
//  digitalWrite(inkiri2, HIGH);
//
//  analogWrite(enkanan, 1000);
//  analogWrite(enkiri, 1000);
//}

void maju(){
  digitalWrite(inkanan1, HIGH);
  digitalWrite(inkanan2, LOW);
  digitalWrite(inkiri1, HIGH);
  digitalWrite(inkiri2, LOW);

  analogWrite(enkanan, 240);
  analogWrite(enkiri, 240);
}

void mundur(){
  digitalWrite(inkanan1, LOW);
  digitalWrite(inkanan2, HIGH);
  digitalWrite(inkiri1, LOW);
  digitalWrite(inkiri2, HIGH);

  analogWrite(enkanan, 240);
  analogWrite(enkiri, 240);
}

void majukiri(){
  digitalWrite(inkanan1, LOW);
  digitalWrite(inkanan2, HIGH);
  digitalWrite(inkiri1, HIGH);
  digitalWrite(inkiri2, LOW);

  analogWrite(enkanan, 240);
  analogWrite(enkiri, 240);
}

void majukanan(){
  digitalWrite(inkanan1, HIGH);
  digitalWrite(inkanan2, LOW);
  digitalWrite(inkiri1, LOW);
  digitalWrite(inkiri2, HIGH);

  analogWrite(enkanan, 240);
  analogWrite(enkiri, 240);
}

void berhenti(){
  analogWrite(enkanan, 0);
  analogWrite(enkiri, 0);
  digitalWrite(inkanan1, HIGH);
  digitalWrite(inkanan2, HIGH);
  digitalWrite(inkiri1, HIGH);
  digitalWrite(inkiri2, HIGH);
  delay(50);
  analogWrite(enkanan, 0);
  analogWrite(enkiri, 0);
  digitalWrite(inkanan1, LOW);
  digitalWrite(inkanan2, LOW);
  digitalWrite(inkiri1, LOW);
  digitalWrite(inkiri2, LOW);
}
