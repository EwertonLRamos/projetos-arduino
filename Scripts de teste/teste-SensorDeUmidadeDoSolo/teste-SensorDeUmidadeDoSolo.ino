#define sensor1 A2
#define sensor2 A3

int val1 = 0;
int val2 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val2 = analogRead(sensor2);
  Serial.print(val2);
  Serial.print(" | ");
  val1 = analogRead(sensor1);
  Serial.println(val1);
}
