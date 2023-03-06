float feedback, h_set, e, ekm1, ekm2, uk, ukm1, ukm2, BN;
bool SampleTimeLog;
long TStart, TEnd;
void setup() {
  for (int i; i <= 7; i++) {
    pinMode(i, OUTPUT);
  };
  pinMode(13, OUTPUT);
}

void loop() {
  TStart = millis();
  feedback = analogRead(A5) * 5.0 / 1023.0;
  h_set = analogRead(A0) * 5.0 * 10.0 / 1023;
  e = h_set - feedback;
  uk = 0.129635 * ekm1 - 0.126689 * ekm2 + 1.83974 * ukm1 - 0.85097 * ukm2;
  BN = uk * 255.0 / 5.0/7.0;
  PORTD = BN;
  ekm2 = ekm1;
  ekm1 = e;
  ukm2 = ukm1;
  ukm1 = uk;
  SampleTimeLog = !SampleTimeLog;
  digitalWrite(13, SampleTimeLog);
  TEnd = millis();
  delay(100 - (TEnd - TStart));
}
