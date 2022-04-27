 const int sensorPin = A0; //analog input
 const float baselineTemp = 15.0; // holds baseline temperature
 // for every 2 degrees above baseline, an LED luminates
  
void setup() 
{
   Serial.begin(9600); 
  // allows user to see values from analog input
  // '9600' is the speed the Arduino will communicate to computer, (9600 bits per second)

  for(int pinNumber = 2; pinNumber < 5; pinNumber++)
  //sets pins as output
  //for() loop will run through pins 2-4 sequentially
   {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
   }
}

void loop() // reads the temperature sensor
{
  int sensorVal = analogRead(sensorPin);
  //'sensorVal' will store reading from sensor
  //'analogRead' gets the value from the sensor (i.e.takes the voltage reading from a pin)
  
  Serial.print("Sensor Value : ");
  Serial.print(sensorVal);

  //converts sensor reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print(" , Volts: ");
  Serial.print(voltage);

  Serial.print(" , degrees C: ");
  //convert the voltage to temperature in degrees
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  if (temperature < baselineTemp+2)
  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+6)
  {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
