String msg = "Hello, what color pin would you like me to light up?";
int numPin2 = 2;
int numPin3 = 3;
int numPin4 = 4;
int numPin5 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(numPin2, OUTPUT);
  pinMode(numPin3, OUTPUT);
  pinMode(numPin4, OUTPUT);
  pinMode(numPin5, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(msg);

  while (Serial.available() == 0) {
    // Wait for input
  }

  String str = Serial.readString();
  str.toLowerCase(); // Convert the input string to lowercase
  str.trim();
  if (str == "blue") {
    digitalWrite(numPin2, HIGH);
    delay(1500);
    digitalWrite(numPin2, LOW);
  } else if (str == "green") {
    digitalWrite(numPin3, HIGH);
    delay(1500);
    digitalWrite(numPin3, LOW);
  } else if (str == "yellow") {
    digitalWrite(numPin4, HIGH);
    delay(1500);
    digitalWrite(numPin4, LOW);
  } else if (str == "red") {
    digitalWrite(numPin5, HIGH);
    delay(1500);
    digitalWrite(numPin5, LOW);
  } else {
    Serial.println("Invalid color entered.");
  }

  delay(1500); // Add a delay to prevent spamming the loop
}
//Serial.parseInt()
//Serial.readString()
