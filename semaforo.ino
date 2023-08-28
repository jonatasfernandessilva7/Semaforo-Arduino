#define pinLEDvermelho 5
#define pinLEDamarelo 3
#define pinLEDverde 4
#define pinBOTAO_DE_INTERRUPCAO 2

void lancarAlarme();

void setup() {
  // put your setup code here, to run once:
  //declarando pinos como saída
  pinMode(pinLEDvermelho, OUTPUT); 
  pinMode(pinLEDamarelo, OUTPUT);   
  pinMode(pinLEDverde, OUTPUT);
  pinMode(pinBOTAO_DE_INTERRUPCAO, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(pinBOTAO_DE_INTERRUPCAO), lancarAlarme, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:

  noInterrupts();

  digitalWrite(pinLEDvermelho, HIGH);
  digitalWrite(pinLEDamarelo, LOW);
  digitalWrite(pinLEDverde, LOW);

  delay(600);

  interrupts();

  digitalWrite(pinLEDvermelho, LOW);
  digitalWrite(pinLEDamarelo, HIGH);
  digitalWrite(pinLEDverde, LOW);

  delay(20000);

  digitalWrite(pinLEDvermelho, LOW);
  digitalWrite(pinLEDamarelo, LOW);
  digitalWrite(pinLEDverde, HIGH);

  delay(60000);
  
}

void lancarAlarme(){
static bool estado = LOW;
static unsigned long delayDoEstado;

  if ((millis() - delayDoEstado)> 100){
    estado != estado;
    delayDoEstado = millis();
  }

  digitalWrite(pinLEDvermelho, estado);

}