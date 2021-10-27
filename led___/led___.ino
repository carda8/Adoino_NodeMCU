int ledPin1 = D1;
int ledPin2 = D2;
int ledPin3 = D3;
int ledPin_default = LED_BUILTIN;
int ledPin_default2 = D0;

const int analPin = A0;

void setup() {
    Serial.begin(115200);
    pinMode(ledPin2, OUTPUT);
    
//  pinMode(ledPin2, OUTPUT);
//  pinMode(ledPin3, OUTPUT);
//  pinMode(ledPin_default, OUTPUT);
//  pinMode(ledPin_default2, OUTPUT);
}

void loop() {
  int val = analogRead(analPin);
  int light = map(val, 0, 1023, 0, 255);
  analogWrite(ledPin2, light);
  Serial.println(val);

//  delay(20);
//  digitalWrite(ledPin1, HIGH);
//  delay(1000);
//  digitalWrite(ledPin1, LOW);
//  delay(1000);
//    digitalWrite(ledPin1, HIGH);
//    delay(50);
//    digitalWrite(ledPin1, LOW);
//    delay(50);
//  
//  digitalWrite(ledPin3, HIGH);
//  delay(50);
//  digitalWrite(ledPin3, LOW);
//  delay(50);
//
//  digitalWrite(ledPin_default, LOW);
//  delay(50);
//  digitalWrite(ledPin_default, HIGH);
//  delay(50);
//
//  digitalWrite(ledPin_default2, LOW);
//  delay(50);
//  digitalWrite(ledPin_default2, HIGH);
//  delay(50);
  
}
