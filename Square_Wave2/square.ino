void square() {
    // 0 to 60 degrees
    delayMicroseconds(deadtime);
    PORTB |= (1 << RH);
    PORTD |= (1 << BH) | (1 << YL);
    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);

    // 60 to 180 degrees
    // RH, YL remain HIGH
    PORTD &= ~(1 << BH); // BH = LOW
    delayMicroseconds(deadtime);

    PORTD |= (1 << BL); // BL = HIGH
    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);

    // 180 to 240 degrees
    PORTD &= ~(1 << YL); // YL = LOW
    delayMicroseconds(deadtime);
    PORTB |= (1 << YH);  // YH = HIGH
    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);

    PORTB &= ~(1 << RH); // RH = LOW
    delayMicroseconds(deadtime);

    PORTB |= (1 << RL); // RL = HIGH
    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);

    PORTD &= ~(1 << BL); // BL = LOW
    delayMicroseconds(deadtime);
    PORTD |= (1 << BH);  // BH = HIGH
    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);

    PORTB &= ~(1 << YH); // YH = LOW
    delayMicroseconds(deadtime);

    PORTD |= (1 << YL); // YL = HIGH
    Delay_and_DisplayTime(); //delayMicroseconds(delayWithoutDead);

    // Finally, RL LOW (complete the cycle)
    PORTB &= ~(1 << RL); // RL = LOW
}
