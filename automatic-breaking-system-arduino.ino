// Arduino Based Automatic Breaking System //

// ---------- Pin Definitions ----------
#define ENA 11
#define ENB 3
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define TRIG 9
#define ECHO 10
#define BUZZER 2 
const int stopDistance = 35; // cm
void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int distance = readUltrasonicCM();
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance > 0 && distance < stopDistance) {
    stopMotors();
    digitalWrite(BUZZER, HIGH); // buzzer ON
  } else {
    moveForward();
    digitalWrite(BUZZER, LOW); // buzzer OFF
  }
  delay(50);
}
// ---------- Functions ----------
int readUltrasonicCM() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH);
  if (duration == 0) return -1;
  int cm = duration * 0.034 / 2;
  return cm;
}
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); // right motors inverted
  digitalWrite(IN4, HIGH);
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}
void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

