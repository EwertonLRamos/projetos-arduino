const uint8_t trig_pin = 6;
const uint8_t echo_pin = 7;
uint32_t print_timer;

void setup() {
  Serial.begin(9600);
  
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  digitalWrite(trig_pin, LOW);
}
void loop() {
  if (millis() - print_timer > 500) {
    print_timer = millis();
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(11);
    digitalWrite(trig_pin, LOW);
    uint32_t pulse_time = pulseIn(echo_pin, HIGH);
    double distance = 0.01715 * pulse_time;

    Serial.print(distance);
    Serial.println(" cm");
  }
}
