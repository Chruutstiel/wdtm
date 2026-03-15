#include <Adafruit_BNO08x.h>

#define SDA_PIN 23
#define SCL_PIN 19

Adafruit_BNO08x bno;
sh2_SensorValue_t sensorValue;

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);

  if (!bno.begin_I2C()) {
    Serial.println("BNO085 not found!");
    while (1);
  }
  Serial.println("BNO085 found!");

  bno.enableReport(SH2_ARVR_STABILIZED_RV);
}

void loop() {
  if (bno.getSensorEvent(&sensorValue)) {
    float yaw  = sensorValue.un.arvrStabilizedRV.real;
    float pitch = sensorValue.un.arvrStabilizedRV.i;
    float roll   = sensorValue.un.arvrStabilizedRV.j;

    Serial.print("Yaw (point left): "); Serial.print(yaw);  // point left
    Serial.print(" Pitch (nose up): "); Serial.print(pitch); // nose up
    Serial.print(" Roll (screw in): "); Serial.println(roll); // screw in
  }
  delay(100);
}