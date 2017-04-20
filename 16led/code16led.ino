int latchPin = 11;
int clockPin = 10;
int dataPin = 12;
const int HC595_COUNT = 2;
byte ledStatus[HC595_COUNT]= {0}; 
void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void fillValueToArray(byte value) {
  for (int i = 0;i < HC595_COUNT; i += 1) {
    ledStatus[i] = value;
  }
}
void shiftOutHC595(int dataPin, int clockPin, byte ledStatus[]) {
  digitalWrite(latchPin, LOW);
  
  for (int i = 0; i < HC595_COUNT; i++) {
    shiftOut(dataPin,clockPin,LSBFIRST,ledStatus[i]);
  }
  digitalWrite(latchPin, HIGH);
}
void loop() { 
  //Sáng tuần tự phải qua trái
 
 
   fillValueToArray(0);
  for (int i = 0; i < HC595_COUNT; i++) {
    for (byte j = 0;j<8;j ++) {
      ledStatus[i] |= 1 << j;
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(150);
    }
  }
    for (int i = HC595_COUNT - 1; i >= 0; i--) {
    for (int j = 8;j >= 0;j --) {
      ledStatus[i] &= ~(1 << j);
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(150);
    }
  }
  //Sáng tuần tự trái qua phải
  fillValueToArray(0);
   for (int i = HC595_COUNT - 1; i >= 0; i--) {
    for (int j = 8;j >= 0;j --) {
      ledStatus[i] |= 1 << j;
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(150);
    }
  }
  for (int i = 0; i < HC595_COUNT; i++) {
    for (byte j = 0;j<8;j ++) {
      ledStatus[i] &= ~(1 << j);
      shiftOutHC595(dataPin,clockPin,ledStatus);
      delay(150);
    }
  }
}

