const int SSpin   = 3; // PORTD.3 for Uno
const int SCKpin  = 6; // PORTD.6 for Uno
const int MISOpin = 7; // PORTD.7 for Uno
const int MOSIpin = 8; // PORTB.0 for Uno

unsigned long nextsec = micros()+1000000UL;

int toggle = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(SCKpin,  INPUT);
  pinMode(SSpin,   INPUT);
  pinMode(MOSIpin, INPUT);
  pinMode(MISOpin, OUTPUT);
  digitalWrite(MISOpin, LOW);
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  int sck = digitalRead(SCKpin);
  int ss = digitalRead(SSpin);
  int mosi = digitalRead(MOSIpin);
  unsigned long currtime = micros();
  
  Serial.print("Currtime: ");
  Serial.print(currtime);
  Serial.print(" Nexttime: ");
  Serial.print(nextsec);
  Serial.print(" Strobe: ");
  Serial.print(sck);
  Serial.print(" AN1: ");
  Serial.print(ss);
  Serial.print(" AN0: ");
  Serial.print(mosi);
  Serial.print(" PB0: ");
  Serial.println(toggle);
  
  if (currtime > nextsec)
  {
    if (toggle == 0)
    {
      digitalWrite(MISOpin, HIGH);
      toggle = 1;
    } 
    else
    {
      digitalWrite(MISOpin, LOW);
      toggle = 0;
    }
    nextsec = currtime+1000000UL;
  }

}
