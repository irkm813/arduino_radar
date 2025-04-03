#Include <Servo.h>

const int TRIGGER_PIN = 9;  
const int ECHO_PIN = 10; 
const int SERVO_PIN = 3;
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 0;
const float SOUND_SPEED = 0.0343;

bool isIncreasing = true;
float duration, distance;
int currentAngle = 0;

Servo myservo;

void setup(){

  myservo.attach(SERVO_PIN);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Serial.begin(115200);
}

void loop() {

  myservo.write(currentAngle);

  distance = measureDistance();

  printData();

  if (currentAngle <= 0){
    isIncreasing = true;
  }else if (currentAngle >= 180){
    isIncreasing == false
  }

  currentAngle += isIncreasing ? 1 : -1;

}

float measureDistance() {
  // Send ultrasonic pulse
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  // Measure echo duration and calculate distance
  float duration = pulseIn(ECHO_PIN, HIGH);
  return (duration * SOUND_SPEED) / 2;
}

void printData(){
  Serial.print(currentAngle);
  Serial.print(",");
  Serial.println(distance);
}