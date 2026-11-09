void square() {
    // 0 to 60 degrees
    delayMicroseconds(deadtime);
    PORTB |= (1 << PORTB1); // RH = HIGH
    PORTD |= (1 << PORTD6); // BH = HIGH
    PORTD |= (1 << PORTD3); // YL = HIGH
    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);

    // 60 to 180 degrees
    // RH, YL remain HIGH
    PORTD &= ~(1 << PORTD6); // BH = LOW
    delayMicroseconds(deadtime);

    PORTD |= (1 << PORTD5); // BL = HIGH
    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);

    // 180 to 240 degrees
    PORTD &= ~(1 << PORTD3); // YL = LOW
    delayMicroseconds(deadtime);
    PORTB |= (1 << PORTB3);  // YH = HIGH
    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);

    PORTB &= ~(1 << PORTB1); // RH = LOW
    delayMicroseconds(deadtime);

    PORTB |= (1 << PORTB2); // RL = HIGH
    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);

    PORTD &= ~(1 << PORTD5); // BL = LOW
    delayMicroseconds(deadtime);
    PORTD |= (1 << PORTD6);  // BH = HIGH
    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);

    PORTB &= ~(1 << PORTB3); // YH = LOW
    delayMicroseconds(deadtime);

    PORTD |= (1 << PORTD3); // YL = HIGH
    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);

    PORTB &= ~(1 << PORTB2); // RL = LOW
}
