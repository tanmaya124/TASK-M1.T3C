const int pirSensorPin1 = 3; 
const int pirSensorPin2 = 2;
const int BuzzorPin1 = 6;
const int BuzzorPin2 = 7;

volatile bool motionDetected1 = false;
volatile bool motionDetected2 = false;

void setup() {
  pinMode(pirSensorPin1, INPUT);
  pinMode(pirSensorPin2, INPUT);
  pinMode(BuzzorPin1, OUTPUT);
  pinMode(BuzzorPin2, OUTPUT);
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(pirSensorPin1), PirSensor1ISR, RISING);
  attachInterrupt(digitalPinToInterrupt(pirSensorPin2), PirSensor2ISR, RISING);
}

void loop() {
  if (motionDetected1) {
    digitalWrite(BuzzorPin1, HIGH);
    Serial.println("Motion has been detected on Buzzor 1");
    delay(1000);
    digitalWrite(BuzzorPin1, LOW);
    motionDetected1 = false;
  }

  if (motionDetected2) {
    digitalWrite(BuzzorPin2, HIGH);
    Serial.println("Motion has been detected on Buzzor 2");
    delay(1000);
    digitalWrite(BuzzorPin2, LOW);
    motionDetected2 = false;
  }

  Serial.println("CODE WORKING");
  delay(2000);
}

void PirSensor1ISR() {
  motionDetected1 = true;
}

void PirSensor2ISR() {
  motionDetected2 = true;
}
