int fsrPin[4] = {0, 1, 2, 3};   // the FSRs are connected to analog inputs A0, A1, A2, and A3
int fsrReading[4];    // the analog reading from the FSR resistor divider

// Constants for calculating pressure in newtons
const float fsrVoltage = 5.0;   // The voltage supplied to the FSR sensor (in this case, 5V from the Arduino Uno)
const float fsrResistance = 10000.0;   // The resistance of the 10K resistor in the FSR circuit
const float fsrSensitivity[4] = {0.0048828125, 0.0048828125, 0.0048828125, 0.0048828125};   // The sensitivity of the FSR sensors (found in the datasheet)

void setup(void) {
  Serial.begin(9600);  
}

void loop(void) {
  for (int i = 0; i < 4; i++) {
    fsrReading[i] = analogRead(fsrPin[i]);  

    float voltage = fsrReading[i] * (fsrVoltage / 1023.0);   // Convert the analog reading to voltage
    float resistance = fsrResistance * (1.0 - (fsrReading[i] / 1023.0));   // Calculate the resistance of the FSR sensor
    float pressure = fsrSensitivity[i] * pow(resistance, 2.0);   // Calculate the pressure in newtons
    
    Serial.print("FSR ");
    Serial.print(i);
    Serial.print(" reading = ");
    Serial.print(fsrReading[i]);
    Serial.print(", Voltage = ");
    Serial.print(voltage);
    Serial.print(" V, Resistance = ");
    Serial.print(resistance);
    Serial.print(" Ohms, Pressure = ");
    Serial.print(pressure/1000);
    Serial.println(" N");
  }
  
  delay(1000);
}
