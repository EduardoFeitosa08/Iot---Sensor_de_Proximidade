const int PINO_TRIGGER = 26;
const int PINO_ECHO = 25;
const int PINO_LED_OBJETO_PERTO = 18;
const int PINO_LED_SEM_OBJETO = 19;

void setup() {
  pinMode(PINO_TRIGGER, OUTPUT);
  pinMode(PINO_ECHO, INPUT);
  pinMode(PINO_LED_OBJETO_PERTO, OUTPUT);
  pinMode(PINO_LED_SEM_OBJETO, OUTPUT);


  digitalWrite(PINO_TRIGGER, LOW);
}

void loop() {

  digitalWrite(PINO_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIGGER, LOW);

  long duracao = pulseIn(PINO_ECHO, HIGH, 30000);

  float distancia = (duracao /2.0) * 0.0343;

  if(distancia > 0 && distancia <= 10){
    digitalWrite(PINO_LED_OBJETO_PERTO, HIGH);
    digitalWrite(PINO_LED_SEM_OBJETO, LOW);
    delay(1000);
  }else{
    digitalWrite(PINO_LED_OBJETO_PERTO, LOW);
    digitalWrite(PINO_LED_SEM_OBJETO, HIGH);
  }
}