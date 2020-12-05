#define lverde 7
#define lrojo 13
int tx = 1;
int rx = 0;
String recepcion = "";
void setup()
{
  Serial.begin(9600);
  pinMode(lverde, OUTPUT);
  pinMode(lrojo, OUTPUT);
  pinMode(tx, OUTPUT);
  pinMode(rx, INPUT);
  digitalWrite(lrojo, HIGH);
}

void leer()
{
  if(Serial.available()){
    while(Serial.available()){
      char dato = Serial.read();
      recepcion += dato;
    }
    if(recepcion == "a"){
      digitalWrite(lverde, HIGH);
      digitalWrite(lrojo, LOW);
    } else if(recepcion == "c"){
      digitalWrite(lrojo, HIGH);
      digitalWrite(lverde, LOW);
    }
  }
  recepcion = "";
}

void loop()
{
  leer();
  delay(1000);
}
