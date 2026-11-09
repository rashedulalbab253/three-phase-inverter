void setPinsLow() {
  // Set each of the defined pins to LOW by clearing the corresponding PORT bit
  PORTB &= ~((1 << RH) | (1 << RL) | (1 << YH));
  PORTD &= ~((1 << YL) | (1 << BH) | (1 << BL));
}
