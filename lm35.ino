void setup()
{
  Serial.begin(9600);   // opens serial port, sets data rate to 9600 bps  
}

void loop()
{
  Serial.print("Temps:");
  Serial.print(temp_sen(A0));
  Serial.println(" C");
  delay(500);
 
}
int temp_sen (int pin)
{
  int value=0;            //initializing variables
  float volts=0.0;      
  float temp=0.0;
  value=analogRead(pin);
  volts=(value/1024.0)*3.3;      //conversion to volts
  temp= volts*100.0;             //conversion to temp Celsius
  return temp;
  
 }  
