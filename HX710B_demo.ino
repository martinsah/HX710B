#define sck D3
#define din D2
void setup() {
  // put your setup code here, to run once:
  delay(100);
  Serial.begin(115200);
  delay(100);
  Serial.println("Hello");
  pinMode(sck,OUTPUT);
  pinMode(din,INPUT);
  digitalWrite(sck,HIGH);
  sread(25);
}

uint32_t sread(int p)
{
  uint32_t rval=0;
  int x=0;
  for(x=0;x<p;x++){
    digitalWrite(sck,HIGH);
    delayMicroseconds(10);
    if(x<24){
      rval <<= 1;
      rval |= (digitalRead(din)?1:0);
    }
    digitalWrite(sck,LOW);
    delayMicroseconds(10);
  }
  return rval;
}

void loop() {
  uint32_t val = 0;
  
  delay(50);
  // put your main code here, to run repeatedly:
  if(digitalRead(din)==LOW)
  {
    val = sread(25);
    Serial.printf("\n%08X",val);
  }
  delay(50);
}
