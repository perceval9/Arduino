int pin2 = 2;
int pin3 = 3;
int pin4 = 4;
int pin5 = 5;

int counter = 0;

int bright = 10;  // Brightness level for PWM pins (0 to 255)

void setup() {
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
}

void loop() {
  while (counter < 16) {
    // Turn all pins off initially
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    digitalWrite(pin5, LOW);
    delay(1000);  // Wait 1 second

    int count = counter;

    // Set pin2 based on the highest bit (8's place)
    if (count / 8 == 1) {
      digitalWrite(pin2, HIGH);
      count %= 8;
    }

    // Set pin3 based on the 4's place using PWM
    if (count / 4 == 1) {
      analogWrite(pin3, bright);
      count %= 4;
    }

    // Set pin4 based on the 2's place
    if (count / 2 == 1) {
      digitalWrite(pin4, HIGH);
      count %= 2;
    }

    // Set pin5 based on the 1's place using PWM
    if (count == 1) {
      analogWrite(pin5, bright);
    }

    delay(2000);  // Hold the current state for 2 seconds

    counter += 1;  // Increment the counter
  }

  counter = 0;  // Reset the counter to repeat the loop
}