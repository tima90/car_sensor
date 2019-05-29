int echoPin = 7; 
int trigPin = 6; 
int greenLed = 5; 
int yellowLed = 4; 
int redLed = 3; 
int buzzerPin = 9; 

void setup() 
{ 
  Serial.begin(9600); 
  pinMode(greenLed, OUTPUT); 
  pinMode(yellowLed, OUTPUT); 
  pinMode(redLed, OUTPUT); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(buzzerPin, OUTPUT); 
}

void loop() 
{ 
  
  digitalWrite(greenLed, LOW); 
  digitalWrite(yellowLed, LOW); 
  digitalWrite(redLed, LOW);
  
  long duration, inches, cm;     

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 

  duration = pulseIn(echoPin, HIGH); 
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);  

    Serial.println(cm); 
    Serial.println();   
   
  if (cm > 15) 
  { 
    digitalWrite(greenLed, HIGH); 
    digitalWrite(yellowLed, LOW); 
    digitalWrite(redLed, LOW); 

  } 
  else if (cm > 10) 
  { 
    digitalWrite(greenLed, LOW); 
    digitalWrite(yellowLed, HIGH); 
    digitalWrite(redLed, LOW); 
    digitalWrite(buzzerPin, HIGH); 
    delay(100); 
    digitalWrite(buzzerPin, LOW); 
    delay(100); 
    digitalWrite(buzzerPin, HIGH); 
    delay(100); 
    digitalWrite(buzzerPin, LOW); 
    delay(100); 
    digitalWrite(buzzerPin, HIGH); 
    delay(100); 
    digitalWrite(buzzerPin, LOW); 
    delay(100); 

  } 
  else if (cm > 5) 
  { 
    digitalWrite(greenLed, LOW); 
    digitalWrite(yellowLed, LOW); 
    digitalWrite(redLed, HIGH); 
    digitalWrite(buzzerPin, HIGH); 
    delay(50); 
    digitalWrite(buzzerPin, LOW); 
    delay(50); 
    digitalWrite(buzzerPin, HIGH); 
    delay(50); 
    digitalWrite(buzzerPin, LOW); 
    delay(50); 
    digitalWrite(buzzerPin, HIGH); 
    delay(50); 
    digitalWrite(buzzerPin, LOW); 
    delay(50);

  }


  delay(1000); 
} 


long microsecondsToInches(long microseconds)
{
  return microseconds/74/2;
}

//Converts the Microseconds Reading to Centimeters
long microsecondsToCentimeters(long microseconds)
{
  return microseconds/29/2; 
} 


