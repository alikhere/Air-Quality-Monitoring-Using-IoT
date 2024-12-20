/*
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  int mQ135;
  int mQ3;
  int mQ9;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

// Define the pins for the sensors
const int MQ135_PIN = 35;
const int MQ3_PIN = 34;
const int MQ9_PIN = 33;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  
  // Read the analog values from the sensors
  int sensorValueMQ135 = analogRead(MQ135_PIN);
  int sensorValueMQ3 = analogRead(MQ3_PIN);
  int sensorValueMQ9 = analogRead(MQ9_PIN);
  
  // Convert the analog readings (0-1023) to voltages (0-5V)
  float voltageMQ135 = sensorValueMQ135 * (5.0 / 1023.0);
  float voltageMQ3 = sensorValueMQ3 * (5.0 / 1023.0);
  float voltageMQ9 = sensorValueMQ9 * (5.0 / 1023.0);
  
  // Print the analog values and voltages to the Serial Monitor
  Serial.print("MQ135 Sensor Value: ");
  Serial.print(sensorValueMQ135);
  Serial.print(" | Voltage: ");
  Serial.println(voltageMQ135);
  
  Serial.print("MQ3 Sensor Value: ");
  Serial.print(sensorValueMQ3);
  Serial.print(" | Voltage: ");
  Serial.println(voltageMQ3);

  Serial.print("MQ9 Sensor Value: ");
  Serial.print(sensorValueMQ9);
  Serial.print(" | Voltage: ");
  Serial.println(voltageMQ9);
  
  // Update the cloud variables with the sensor values
  mQ135 = sensorValueMQ135;
  mQ3 = sensorValueMQ3;
  mQ9 = sensorValueMQ9;

  // Add a delay for stability
  delay(1000);
}

/*
  Since the variables are READ_WRITE, onChange functions are
  executed every time a new value is received from the IoT Cloud.
*/
void onMQ135Change()  {
  // Add your code here to act upon MQ135 change
}

void onMQ3Change()  {
  // Add your code here to act upon MQ3 change
}

void onMQ9Change()  {
  // Add your code here to act upon MQ9 change
}
