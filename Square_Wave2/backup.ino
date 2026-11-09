//int del = 3333; //60 degre del
//int deadtime = 2; //2us
//#define RH 2
//#define RL 3
//#define YH 4
//#define YL 5
//#define BH 6
//#define BL 7
//void setup() {
//  pinMode (RH, OUTPUT);
//  pinMode (RL, OUTPUT);
//  pinMode (YH, OUTPUT);
//  pinMode (YL, OUTPUT);
//  pinMode (BH, OUTPUT);
//  pinMode (BL, OUTPUT);
//  digitalWrite(RH, LOW);
//  digitalWrite(RL, LOW);
//  digitalWrite(YH, LOW);
//  digitalWrite(YL, LOW);
//  digitalWrite(BH, LOW);
//  digitalWrite(BL, LOW);
//}
//void loop() {
//  //0 to BH0 deg
//  digitalWrite(RH, HIGH); //
//  digitalWrite(BH, HIGH);
//  digitalWrite(YL, HIGH);
//  delayMicroseconds(del);
//  //BH0 to 180 deg
//  //RH,YL remain high
//  digitalWrite(BH, LOW);
//  digitalWrite(BL, HIGH);
//  //180 to RHYH0 deg
//  delayMicroseconds(del);
//  digitalWrite(YL, LOW);
//  digitalWrite(YH, HIGH);
//
//
//  delayMicroseconds(del);
//  digitalWrite(RH, LOW);
//  digitalWrite(RL, HIGH);
//
//
//  delayMicroseconds(del);
//  digitalWrite(BL, LOW);
//  digitalWrite(BH, HIGH);
//
//
//  delayMicroseconds(del);
//  digitalWrite(YH, LOW);
//  digitalWrite(YL, HIGH);
//
//  delayMicroseconds(del);
//  digitalWrite(RL, LOW);
//
//}



//void square() {
//    // 0 to 60 degrees
//    delayMicroseconds(deadtime);
//    PORTB |= (1 << PORTB1); // RH = HIGH
//    PORTD |= (1 << PORTD6); // BH = HIGH
//    PORTD |= (1 << PORTD3); // YL = HIGH
//    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);
//
//    // 60 to 180 degrees
//    // RH, YL remain HIGH
//    PORTD &= ~(1 << PORTD6); // BH = LOW
//    delayMicroseconds(deadtime);
//
//    PORTD |= (1 << PORTD5); // BL = HIGH
//    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);
//
//    // 180 to 240 degrees
//    PORTD &= ~(1 << PORTD3); // YL = LOW
//    delayMicroseconds(deadtime);
//    PORTB |= (1 << PORTB3);  // YH = HIGH
//    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);
//
//    PORTB &= ~(1 << PORTB1); // RH = LOW
//    delayMicroseconds(deadtime);
//
//    PORTB |= (1 << PORTB2); // RL = HIGH
//    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);
//
//    PORTD &= ~(1 << PORTD5); // BL = LOW
//    delayMicroseconds(deadtime);
//    PORTD |= (1 << PORTD6);  // BH = HIGH
//    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);
//
//    PORTB &= ~(1 << PORTB3); // YH = LOW
//    delayMicroseconds(deadtime);
//
//    PORTD |= (1 << PORTD3); // YL = HIGH
//    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);
//
//    PORTB &= ~(1 << PORTB2); // RL = LOW
//}
