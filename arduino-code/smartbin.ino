#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define trigPin1 6   // Ultrasonic trigger
#define echoPin1 7   // Ultrasonic echo
#define buzzer 4     // Buzzer output

long duration, distance;
float level = 0;

void setup() 
{
  Serial.begin(115200); // Serial monitor
  lcd.begin(16, 2);
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Smart Dustbin");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring");

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() 
{
  ultrasensor(trigPin1, echoPin1); // Read distance
  float maxDistance = 8.7;
  float minDistance = 1.0;
  
  // Calculate fill percentage
  level = ((maxDistance - distance) / (maxDistance - minDistance)) * 100;
  level = constrain(level, 0, 100);

  // Display on Serial and LCD
  Serial.print("Level: "); Serial.print(level); Serial.println(" %");
  lcd.clear();
  lcd.setCursor(3, 0); lcd.print("Level:");
  lcd.setCursor(3, 1); lcd.print(level); lcd.print("%");

  // Buzzer alert if bin >80%
  digitalWrite(buzzer, level > 80 ? HIGH : LOW);

  delay(1000);
}

// Function to measure distance using ultrasonic sensor
void ultrasensor(int trigPin, int echoPin)
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Convert to cm
}
