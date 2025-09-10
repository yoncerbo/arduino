#include <Servo.h>

#define SERVO 9
#define BTN 2

Servo servo;

int pos = 0;

static bool btn_pressed = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  servo.attach(SERVO);

  pinMode(BTN, INPUT);
}

void loop() {

  for (pos = 0; pos <= 180; pos += 1) {
    while (digitalRead(BTN) == LOW);
    servo.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    while (digitalRead(BTN) == LOW);
    servo.write(pos);
    delay(15);
  }
}
