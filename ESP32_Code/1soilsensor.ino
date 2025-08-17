// Define the pin for the soil moisture sensor
int sensorPin = 27;  // GPIO pin for the analog input (choose any ADC-capable pin on ESP32)
int sensorValue = 0; // Variable to store the sensor value

void setup() {
  // Initialize the serial communication
  Serial.begin(115200); // Higher baud rate for ESP32

  // Optionally configure the ADC width and attenuation
  // adcAttachPin(sensorPin);
  // analogSetWidth(12); // Default width is 12 bits (0-4095)
  // analogSetAttenuation(ADC_11db); // Default attenuation for 0-3.3V range
}

void loop() {
  // Read the analog value from the sensor
  sensorValue = analogRead(sensorPin);

  // Map the sensor value to a percentage (0% to 100%)
  int moistureLevel = map(sensorValue, 0, 4095, 100, 0);  // 100% is wet, 0% is dry

  // Print the moisture level to the Serial Monitor
  Serial.print("Soil Moisture Level: ");
  Serial.print(moistureLevel);
  Serial.println("%");

  // Delay before taking the next reading
  delay(1000);
}

