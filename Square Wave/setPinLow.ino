void setPinsLow() {
  // Set each of the defined pins to LOW by clearing the corresponding PORT bit
  PORTB &= ~(1 << PB1);  // Pin 9 (RH) to LOW
  PORTB &= ~(1 << PB2);  // Pin 10 (RL) to LOW
  PORTB &= ~(1 << PB3);  // Pin 11 (YH) to LOW
  PORTD &= ~(1 << PD3);  // Pin 3 (YL) to LOW
  PORTD &= ~(1 << PD6);  // Pin 6 (BH) to LOW
  PORTD &= ~(1 << PD5);  // Pin 5 (BL) to LOW
}
