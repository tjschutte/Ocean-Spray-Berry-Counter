#define SENSORPIN 2

int count = 0;

void setup() {    
  pinMode(SENSORPIN, INPUT_PULLUP);     
  attachInterrupt(digitalPinToInterrupt(SENSORPIN), increment, FALLING | RISING);
  Serial.begin(115200);
}
 
void loop(){
  Serial.println(count, DEC);
}

void increment() {
  count++;
}

