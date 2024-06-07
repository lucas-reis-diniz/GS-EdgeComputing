#define PIN_TRIG 26
#define PIN_ECHO 25
#define LOWLED 18
#define MIDLED 19
#define HIGHLED 17
#define MOTOR 27

void setup() {
  Serial.begin(115200);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() {
  pinMode(LOWLED, OUTPUT);
  pinMode(MIDLED, OUTPUT);
  pinMode(HIGHLED, OUTPUT);
  pinMode(MOTOR, OUTPUT);
  digitalWrite(LOWLED, HIGH);
  digitalWrite(MIDLED, HIGH);
  digitalWrite(HIGHLED, HIGH);
  digitalWrite(MOTOR, LOW);

  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  int duration = pulseIn(PIN_ECHO, HIGH);
  Serial.print("Distancia em CM: ");
  Serial.println(duration / 58);
  
  int level = duration / 58;

  if (level < 100)
  {

        digitalWrite(LOWLED,LOW);
        digitalWrite(MOTOR,HIGH);
        digitalWrite(HIGHLED,HIGH);
        digitalWrite(MIDLED,HIGH);

  }
  else if ((level > 100) && (level <300))
  {
        digitalWrite(LOWLED,HIGH);
        digitalWrite(HIGHLED,HIGH);
        digitalWrite(MIDLED,LOW);

  }
  else if (level >= 300 )
  {
        digitalWrite(HIGHLED,LOW);
        digitalWrite(MIDLED,HIGH);
        digitalWrite(LOWLED,HIGH);
        digitalWrite(MOTOR,LOW);

  }
  delay(1000);
}

