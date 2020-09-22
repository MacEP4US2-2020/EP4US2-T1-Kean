// Define GPIO Pins for LEDs
#define LED_6 5
#define LED_7 18
#define LED_8 19

//Declare global variables
int i = 0;

//function prototype for the LED Sequence
void LED_sequence();

// Main setup and loop functions
void setup() {
  // Initialize GPIO Pins for Output
  pinMode(LED_6,OUTPUT); //IO 5 Output
  pinMode(LED_7,OUTPUT); //IO 6 Output 
  pinMode(LED_8,OUTPUT); //IO 7 Output
}

void loop() {
  // Use global variabl to run run the LED sequence four times
  if (i < 4 ) {
    LED_sequence();
    i++;
  }
}


void LED_sequence() {
  // Alternate through LED 6, 7, 8
  digitalWrite(LED_6,HIGH); //turn ON led
  delay(2000); //wait 2000 ms or 2 seconds
  digitalWrite(LED_6,LOW); //turn OFF led

  digitalWrite(LED_7,HIGH); //turn ON led
  delay(2000); //wait 2000 ms or 2 seconds
  digitalWrite(LED_7,LOW); //turn OFF led
  
  digitalWrite(LED_8,HIGH); //turn ON led
  delay(2000); //wait 2000 ms or 2 seconds
  digitalWrite(LED_8,LOW); //turn OFF led

  // Flash LED 6, 7, 8 simutaenously
  digitalWrite(LED_6,HIGH); //turn ON led
  digitalWrite(LED_7,HIGH); //turn ON led
  digitalWrite(LED_8,HIGH); //turn ON led
  delay(1000); //wait 1000 ms or 1 second
  digitalWrite(LED_6,LOW); //turn OFF led
  digitalWrite(LED_7,LOW); //turn OFF led
  digitalWrite(LED_8,LOW); //turn OFF led
}
