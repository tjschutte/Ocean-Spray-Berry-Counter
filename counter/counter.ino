 
#define LEDPIN 13

 
#define SENSORPIN 4
 
int sensorState = 0, lastState = 0;
int count = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(LEDPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  
  Serial.begin(9600);
}
 
void loop(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);
  /*
  if (sensorState && !lastState) {
    Serial.println("Unbroken");
  } 
  */
  if (!sensorState && lastState) {
    //Serial.println("Broken");
    count++;
    Serial.println(count, DEC);
  }
  lastState = sensorState;
}
