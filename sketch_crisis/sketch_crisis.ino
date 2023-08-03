uint8_t i2cAddress = BMP384_I2C_ADDRESS_DEFAULT; // 0x77
//uint8_t i2cAddress = BMP384_I2C_ADDRESS_SECONDARY; // 0x76

while(pressureSensor.beginI2C(i2cAddress) != BMP3_OK)
{
    // Not connected, inform user
    Serial.println("Error: BMP384 not connected, check wiring and I2C address!");

    // Wait a bit to see if connection is established
    delay(1000);
}

void setup() {
  // put your setup code here, to run once:

}

void loop()
{
    // Get measurements from the sensor
    bmp3_data data = {0};
    int8_t err = pressureSensor.getSensorData(&data);

    // Check whether data was acquired successfully
    if(err == BMP3_OK)
    {
        // Acquisistion succeeded, print temperature and pressure
        Serial.print("Temperature (C): ");
        Serial.print(data.temperature);
        Serial.print("\t\t");
        Serial.print("Pressure (Pa): ");
        Serial.println(data.pressure);
    }
    else
    {
        // Acquisition failed, most likely a communication error (code -2)
        Serial.print("Error getting data from sensor! Error code: ");
        Serial.println(err);
    }

    // Only print every second
    delay(1000);
}

