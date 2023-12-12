// For Ultrasonic sensors
int ultrasonic1_ECHO = 0;
int ultrasonic1_TRIG = 1;

int ultrasonic2_ECHO = 2;
int ultrasonic2_TRIG = 3;

// For motors
int enA = 9;  // speed control pin for motor A
int in1 = 8;
int in2 = 7;

int enB = 10;  // speed control pin for motor B
int in3 = 11;
int in4 = 12;

void setup() {
  // Ultrasonic sensors Setup
  pinMode(ultrasonic1_ECHO, INPUT); // receiving sound
  pinMode(ultrasonic1_TRIG, OUTPUT); // sending sound
  
  pinMode(ultrasonic2_ECHO, INPUT); // receiving sound
  pinMode(ultrasonic2_TRIG, OUTPUT); // sending sound

  // Motors Setup
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Car movement test
  Car_Forward(1500);  // Move forward for 1.5 seconds

  Car_Stop(500);  // STOP for 0.5 seconds

  Car_Backward(1500);  // Move backward for 1.5 seconds

  Car_Stop(500);  // STOP for 0.5 seconds

  Car_Right(1000);  // turn right around itself for 1 second

  Car_Left(1000);  // turn left around itself for 1 second
}

void loop() {
  // Get distance from Ultrasonic 1
  int Distance1 = Ultr1_GetDistance();

  // Get distance from Ultrasonic 2
  int Distance2 = Ultr2_GetDistance();
}

void Car_Forward(int duration) {
  // Move motor A forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);

  // Move motor B forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);

  delay(duration);
}

void Car_Backward(int duration) {
  // Move motor A backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);

  // Move motor B backward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);

  delay(duration);
}

void Car_Right(int duration) {
  // Move motor A backward
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 255);

  // Move motor B forward
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);

  delay(duration);
}

void Car_Left(int duration) {
  // Move motor A forward
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);

  // Move motor B backward
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);

  delay(duration);
}

void Car_Stop(int duration) {
  // stop motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);

  // stop motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);

  delay(duration);
}

int Ultr1_GetDistance(void) {
    digitalWrite(ultrasonic1_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(ultrasonic1_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultrasonic1_TRIG, LOW);

    int duration = pulseIn(ultrasonic1_ECHO, HIGH);
    int distance = duration * 0.034 / 2;

    return distance;
}

int Ultr2_GetDistance(void) {
    digitalWrite(ultrasonic2_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(ultrasonic2_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(ultrasonic2_TRIG, LOW);

    int duration = pulseIn(ultrasonic2_ECHO, HIGH);
    int distance = duration * 0.034 / 2;
    
    return distance;
}