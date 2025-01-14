#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens


  // Try to initialize!
  if (!mpu.begin()) {
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  mpu.setGyroRange(MPU6050_RANGE_500_DEG);


  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  delay(100);

}
void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  a.acceleration.x = a.acceleration.x + 0.61;
  a.acceleration.y = a.acceleration.y -0.16;

  g.gyro.x = g.gyro.x - 0.03;
  g.gyro.z = g .gyro.z + 0.01;
    /* Print out the values */
  //Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", ");
  Serial.print(a.acceleration.y);
  Serial.print(", ");
  Serial.print(a.acceleration.z);
  Serial.print(", ");

  //Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", ");
  Serial.print(g.gyro.y);
  Serial.print(", ");
  Serial.print(g.gyro.z);
  Serial.print(", ");

  //Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  //Serial.println(" degC");

  Serial.println("");
  delay(500);
}