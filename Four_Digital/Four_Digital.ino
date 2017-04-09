int latch=11;  //74HC595  pin 12 STCP
int clock=10; //74HC595  pin 11 SHCP
int data=12;   //74HC595  pin 14 DS

int DigitPins[] = {8, 7, 3, 2};

int DigitOff = HIGH;
int DigitOn = LOW;
int numberOfDigits =4;

unsigned char table[]=
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c
,0x39,0x5e,0x79,0x71,0x00};

void setup() {
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);
  Serial.begin(115200); //Start Serial at 115200bps
  for (byte digit = 0 ; digit < numberOfDigits ; digit++)
  {
    pinMode(DigitPins[digit], OUTPUT);
    digitalWrite(DigitPins[digit], DigitOff);
  }

}
void Display(unsigned char num)
{

  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,table[num]);
  digitalWrite(latch,HIGH);
  
}
void loop() {
     // delay(1000);

    //displayDigit(115);

    for (int i = 20; i < 1100; i++){
      displayDigit(i);
      delay(10);

    }       

    delay(1000);

}

void displayDigit( int num){
     //Serial.println(num );

    for (int digit = 3  ; digit >= 0  ; digit--)
      {

      for (int digit2 = 3  ; digit2 >= 0  ; digit2--)
        {
          if (digit2 != digit){
            digitalWrite(DigitPins[digit2], DigitOff);
          }
         
        }         
          Display( num % 10 );
         num= num / 10;
         digitalWrite(DigitPins[digit], DigitOn);


  
        delay(3);
        
     
  }

}
