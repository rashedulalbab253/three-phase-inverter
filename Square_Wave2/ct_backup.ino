//float S=0,E=36.525;
//int analogValue;
//void A7_init(){
//      ADMUX  = (1 << REFS0) | (1 << MUX2) | (1 << MUX1) | (1 << MUX0);  
//    // REFS0 = 1 -> AVCC as reference
//    // MUX[3:0] = 0111 -> ADC7 (A7 pin)
//    
//    ADCSRA = (1 << ADEN)  | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);  
//    // ADEN = 1 -> Enable ADC
//    // ADPS[2:0] = 111 -> Prescaler 128 (16MHz/128 = 125kHz ADC clock)
//}
//
//uint16_t readADC() {
//    ADCSRA |= (1 << ADSC);  // Start conversion
//    while (ADCSRA & (1 << ADSC));  // Wait until conversion completes
//    return ADC;  // Return ADC result (10-bit value)
//}
//
//void currentMeasure() {
//  // Read analog value from A0 pin (you can change this pin if needed)
//  CT_time=micros();
//  current=0;
//  for(int i=0;i<10;i++){
//    analogValue = readADC();//Read A7
//    current += (float)((analogValue-S)/(1023-S))* E;
//    delayMicroseconds(2);
//  }
//  current=abs(current/10);
//  if (displayF) digit(freq_f);
//  else digit((int)current);
//  if(current>=maxCurrent && maxCurrentPass==false && usedCT==true) {
//    PORTD &= ~(1 << PORTD7); // initialy low relay
//    run_inverter = false;
//    maxCurrentPass=true;
//  }
//  // Map the analog value to the range 0-26 using floating-point arithmetic
////  unsigned long t2=micros();
//
////  // Print both the raw analog value and the mapped floating-point value
////  Serial.print("R: ");
////  Serial.print(analogValue);
////  Serial.print("  C: ");
////  Serial.print(mappedValue);
////  Serial.print("  T: ");
////  Serial.println(t2-t1);
////
////  if(mappedValue>=1.5) digitalWrite(13,HIGH);
////  delay(500);
//}
