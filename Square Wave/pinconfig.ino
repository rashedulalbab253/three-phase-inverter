void pinconfig() {
  //  DDRB=0b00101110;
  //  DDRD=0b11101000;

  // Set pins 2, 4, 8, and 12 as input
  DDRD &= ~((1 << PD2));  // Pin 2 as input, for increase freq
  DDRD &= ~((1 << PD4));  // Pin 4 as input, for decrease freq
  DDRB &= ~((1 << PB0));  // Pin 8 as input, for stop
  DDRB &= ~((1 << PB4));  // Pin 12 as input, for run

  // Enable internal pull-up resistors for pins 2, 4, 8, and 12
  //  PORTD |= (1 << PD2);    // Enable pull-up for pin 2
  //  PORTD |= (1 << PD4);    // Enable pull-up for pin 4
  //  PORTB |= (1 << PB0);    // Enable pull-up for pin 8
  //  PORTB |= (1 << PB4);    // Enable pull-up for pin 12


  // Set the pins as outputs for indicator
  DDRB |= (1 << PB5); //run indicator
  DDRD |= (1 << PD7); //stop indicator

  // Set the pins as outputs for pwm
  DDRB |= (1 << PB1); //R
  DDRB |= (1 << PB2); //R
  DDRB |= (1 << PB3); //Y
  DDRD |= (1 << PD3); //Y
  DDRD |= (1 << PD5); //B
  DDRD |= (1 << PD6); //B

  // Set the pins as outputs using DDRC register
  DDRC |= (1 << DATA0) | (1 << LATCH0) | (1 << CLOCK0) |
          (1 << DATA1) | (1 << LATCH1) | (1 << CLOCK1);
}
