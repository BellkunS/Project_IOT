const int sensorPin = A0; 
const int speakerPin = 9; 

void setup() {
 
  Serial.begin(9600);

 
  pinMode(speakerPin, OUTPUT);
}

void loop() {
 
  int sensorValue = analogRead(sensorPin);


  float pH = mapFloat(sensorValue, 0, 1023, 0, 14);

  
  Serial.print("pH: ");
  Serial.println(pH);

  if (pH > 8.4) {
    
    tone(speakerPin, 264); 
    delay(1000); 
    noTone(speakerPin); 
  } else if (pH < 3.5) {
    tone(speakerPin, 528);
    delay(1000);
    noTone(speakerPin);
  }

 
  delay(1000);
}

float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
