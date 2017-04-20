byte ledPin[] = {0,1,2,3,4,5,6,7};
byte pinCount;
void setup() {
  pinCount = sizeof(ledPin);  //Xem thêm thông tin về hàm sizeof tại http://arduino.vn/reference/sizeof
  for (int i=0;i<pinCount;i++) {
    pinMode(ledPin[i],OUTPUT);  //Các chân LED là OUTPUT
    digitalWrite(ledPin[i],LOW); //Mặc định các đèn LED sẽ tắt
  }
}
void loop() {

  for (int i=0; i <= pinCount; i++) {
    digitalWrite(ledPin[i],HIGH); 
    delay(500); 
    digitalWrite(ledPin[i],LOW);
    delay(500);  
  }

  for (int i = pinCount ;i >= 0; i--) {
    digitalWrite(ledPin[i],HIGH); 
    delay(500); 
    digitalWrite(ledPin[i],LOW);
    delay(500);  
  }
}
