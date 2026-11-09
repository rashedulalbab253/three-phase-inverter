void ext_int_init() {
  EICRA = 0b00000011;
  EIMSK = 0b00000001;

  //Pin Change Interrupts for freq -- and seq change
  PCICR |= 0b00000101; // Enables Ports B and D Pin Change Interrupts
  PCMSK0 |= 0b00010001; // PCINT4=pb4=d12 for run and PCINT0=pb0=d8 for stop
  PCMSK2 |= 0b00010000; // PCINT20=pd4=d4 for freq neg
  sei();
}
//freq + external interrupt
ISR(INT0_vect) {
  while (PIND & (1 << PD2)){
    setPinsLow();
  }
  if (!(PIND & (1 << PD2)) &&(millis()-(t))>Debounce_delay) {
    freq_f = freq_f + 1;
    if (freq_f > max_freq)freq_f = max_freq;
    if (old_freq != freq_f) adjust_freq();
    old_freq = freq_f;
    t=millis();
  }
}
//freq - external interrupt
ISR(PCINT2_vect)
{
  if (PIND & (1 << PD4)) {
    while (PIND & (1 << PD4)) setPinsLow();
    if (!(PIND & (1 << PD4)) &&(millis()-(t))>Debounce_delay) {
      freq_f = freq_f - 1;
      if (freq_f < min_freq)freq_f = min_freq;
      if (old_freq != freq_f) adjust_freq();
      old_freq = freq_f;
      t=millis();
    }
  }
}
//run and stop btn
ISR(PCINT0_vect)
{
  //run btn
  if (PINB & (1 << PB4)) {
    while (PINB & (1 << PB4)) setPinsLow();
    _delay_us(Debounce_delay);
    if (!(PINB & (1 << PB4))) {
      PORTB |= (1 << PORTB5);
      PORTD &= ~(1 << PORTD7);
      run_inverter = true;
    }
  }
  //stop btn
  else if (PINB & (1 << PB0)) {
    while (PINB & (1 << PB0)) setPinsLow();
    _delay_us(Debounce_delay);
    if (!(PINB & (1 << PB0))) {
      PORTB &= ~(1 << PORTB5);
      PORTD |= (1 << PORTD7);
      run_inverter = false;
    }
  }
}
