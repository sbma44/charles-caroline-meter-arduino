#define INC_PIN 2
#define SET_PIN 3
#define PWM_PIN 9

unsigned int val = 0;
long lastSet = -1;

void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  pinMode(PWM_PIN, OUTPUT);
  analogWrite(PWM_PIN, 255);
  attachInterrupt(digitalPinToInterrupt(INC_PIN), inc, CHANGE);  
  attachInterrupt(digitalPinToInterrupt(SET_PIN), set, RISING);  
  Serial.begin(115200);
}

void inc() {
  //Serial.print("x");
  val = min(255, (val + 1));
}

void set() {
  analogWrite(PWM_PIN, val);
  val = 0;
  digitalWrite(13, HIGH);
  lastSet = millis();
}

void loop() {
  if ((lastSet > 0) && (millis() - lastSet > 500)) {
    digitalWrite(13, LOW);
  }
}
