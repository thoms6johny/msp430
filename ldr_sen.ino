int sensorPin = A0; 
int sensorValue = 0;
#define MAX_ADC_READING           1023
#define ADC_REF_VOLTAGE           3.3
#define REF_RESISTANCE            2900  // measure this for best results and put the value according to what is connected to the ldr in series
#define LUX_CALC_SCALAR           1251893100
#define LUX_CALC_EXPONENT         -1.4059

const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average



void setup() {
 Serial.begin(9600);
   // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;

  }
}


void loop(){
  int ldrRawData;
  float resistorVoltage, ldrVoltage;
  float ldrResistance;
  float ldrLux;
  Serial.print("Lux1:");
  Serial.println(fun_ldr(sensorPin));
  }

float fun_ldr(int pin)
{
  int readIndex = 0;
  int ldrRawData;
  float resistorVoltage, ldrVoltage;
  float ldrResistance;
  float ldrLux;
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(pin);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  // send it to the computer as ASCII digits
  //Serial.println(average);
  delay(1); 
  ldrRawData = average;
  resistorVoltage = ((float)ldrRawData / MAX_ADC_READING) * ADC_REF_VOLTAGE;
  ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage;
  ldrResistance = ldrVoltage/resistorVoltage * REF_RESISTANCE;
  ldrLux = LUX_CALC_SCALAR * powf(ldrResistance, LUX_CALC_EXPONENT); 
  return (ldrLux); //prints the values coming from the sensor on the screen   
  }
