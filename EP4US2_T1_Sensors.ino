/* Your second assignment is to write a program that obtains sensor 
data from the DHT 11, DS18B20 and Ambient Light Sensor. Your
program must obtain Temperature C, Temperature F, Humidity % from the DHT11.
Temperature C and Temperature F from the DS18B20. Ambient light voltage from
the photoresistor and it must be output on the Serial Monitor in a neat and
clear output form
*/

// Include the libraries
//#include <OneWire.h> 
//#include <DallasTemperature.h>
#include <String.h> //generic library
#include <DHT.h> //DHT-11 sensor library

/********************************************************************/
// Macro Definitions
#define DHTPIN 4 //define the pin that the DHT sensor's signal is connected to
#define DHTTYPE DHT11 //define the type of DHT sensor
#define ONE_WIRE_BUS 16 // DS18B20 GPIO pin 
#define AMBIENT_LIGHT 0

/********************************************************************/
//Declaring Objects

DHT dht(DHTPIN, DHTTYPE); //object declaration constructor
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
//OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
//DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:

  //Serial Monitor initialization
  //The serial monitor is the built in output form, similar to a console.
  //Use "Serial.println("")" to print strings and sensor data to the serial monitor
  Serial.begin(115200); //baud rate of 115200Hz


  // Start up the library 
 //sensors.begin(); 

  //DHT-11 Initialization
  Serial.println("Temp Routine starts now");
  dht.begin(); //function that starts the sensor during the initial setup
}

void loop() {
  //DHT-11 Sensor Data Extraction
  // Read humidity as percentage
  float h = dht.readHumidity();

  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Ambient Light Sensor
  float ambientLight = float(analogRead(AMBIENT_LIGHT)) / 4096 * 5;
  
  //Display Sensor data on the Serial Monitor
  Serial.println("Humidity: " + String(h)); 
  Serial.println("Temperature C: " + String(t));
  Serial.println("Temperature F: " + String(f));
  Serial.println("Ambient Light Sensor (V): " + String(ambientLight));
  delay(1000);
}
