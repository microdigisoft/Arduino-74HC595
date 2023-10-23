int latchPin = 5; // Intialize 74HC595 latch pin with Arduino pin5
int clkPin = 6; // Intialize 74HC595 clock pin with Arduino pin6
int dataPin = 4;// Intialize 74HC595 data pin with Arduino pin4
byte LED = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT); //Define 74HC595 latch pin as output
  pinMode(dataPin, OUTPUT);//Define 74HC595 data pin as output
  pinMode(clkPin, OUTPUT);//Define 74HC595 clock pin as output
}

void loop()
{
  int i = 0;
  LED = 0;
  shiftLED(); // Function to handle 74HC595 shift register to drive LED
  delay(500);
  for (i = 0; i < 8; i++)
  {
    bitSet(LED, i);
    Serial.println(LED);
    shiftLED();
    delay(500);
  }
}

// Function to handle 74HC595 shift register to drive LED
void shiftLED()
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clkPin, MSBFIRST, LED);
  digitalWrite(latchPin, HIGH);
}
