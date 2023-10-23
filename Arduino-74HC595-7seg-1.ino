#define LATCH_pin 8 // (8) ST_CP [RCK] on 74HC595
#define CLCOK_pin 12     // (12) SH_CP [SCK] on 74HC595
#define DATA_pin 11    // (11) DS [S1] on 74HC595

unsigned char binary_pattern[] = {
    0b11101110,
    0b11111010,
    0b11111110,
    0b00111110,
    0b10011100, 
    0b00011010,  
    0b11111100,
    0b01111010,
    0b10011110,
    0b11011110,
    0b10001110,
    0b11001100,
    0b10111110,
    0b11110110,
    0b01101110,
    0b00101110,
    0b00001100,
    0b10001000,
    0b01111000,
    0b10101110,
    0b00011100,
    0b10101000,
    0b00101010,
    0b11111110,
    0b11001110,
    0b11100110,
    0b00001010,
    0b10110110,
    0b10001100,
    0b01111100,
    0b00111000,
    0b01010110,
    0b01100110,
    0b11011010,
};
unsigned int counter=0;

void clock_signal(void){
   digitalWrite(CLCOK_pin, HIGH);
    delayMicroseconds(500);
   digitalWrite(CLCOK_pin, LOW);
    delayMicroseconds(500);
}
void latch_enable(void)
   {
    digitalWrite(LATCH_pin, HIGH);
    delayMicroseconds(500);
    digitalWrite(LATCH_pin, LOW);
    }
void send_data(unsigned int data_out)
{
    int i;
    unsigned hold;
    for (i=0 ; i<8 ; i++)
    {
        if ((data_out >> i) & (0x01))
        digitalWrite(DATA_pin,HIGH); 
        else
        digitalWrite(DATA_pin,LOW); 
        
        clock_signal();
    }
    latch_enable(); // Data finally submitted
}

void setup() 
{
  pinMode(LATCH_pin , OUTPUT);
  pinMode(DATA_pin , OUTPUT);  
  pinMode(CLCOK_pin , OUTPUT);
  digitalWrite(LATCH_pin, LOW);      // (11) ST_CP [RCK] on 74HC595
  digitalWrite(CLCOK_pin, LOW);      // (9) SH_CP [SCK] on 74HC595
  digitalWrite(DATA_pin, LOW);     // (12) DS [S1] on 74HC595
  Serial.begin(9600);
}

void loop() 
{
  
       send_data(binary_pattern[counter]);
       counter++;
       if(counter>34)
       counter =0;
        delay(1000);
        Serial.println(counter);
}
