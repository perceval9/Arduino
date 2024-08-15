int readPin = A3;
float V2 = 0;
int delay_time = 500;


void setup() {
  // put your setup code here, to run once:
  pinMode(readPin, INPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  V2 = analogRead(readPin);
  //returns a number between 0 and 1023 from 0 to 5 V
  Serial.println(String(V2 * (5.0 / 1023.0)) + " Volts");
  delay(delay_time);


}
