const int SCKpin  = 6; // PORTD.6 for Uno

void setup() {
  // put your setup code here, to run once:
  pinMode(SCKpin,  INPUT);  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int sck = digitalRead(SCKpin);
  unsigned long currtime = micros();

  if (sck == 0)
  {
    Serial.print("STROBE LOW at : ");
    Serial.println(currtime);
  }
}

