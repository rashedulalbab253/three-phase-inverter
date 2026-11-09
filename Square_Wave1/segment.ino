// Binary representation for 0-9 on a 7-segment display
// Inverted binary representation for 0-9 on a 7-segment display (common cathode)
int dataArray[10] = {0B11111100, 0B01100000, 0B11011010, 0B11110010, 0B01100110,
                     0B10110110, 0B10111110, 0B11100000, 0B11111110, 0B11110110};

// Function to send data using shiftOut at register level
void shiftOutRegister(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t value) {
  for (uint8_t i = 0; i < 8; i++) {
    // Write the bit to the data pin
    if (bitOrder == LSBFIRST) {
      if (value & (1 << i)) {
        PORTC |= (1 << dataPin);
      } else {
        PORTC &= ~(1 << dataPin);
      }
    } else { // MSBFIRST
      if (value & (1 << (7 - i))) {
        PORTC |= (1 << dataPin);
      } else {
        PORTC &= ~(1 << dataPin);
      }
    }

    // Pulse the clock pin
    PORTC |= (1 << clockPin);
    PORTC &= ~(1 << clockPin);
  }
}

// Function to display a number on the 7-segment display
void digit(int number) {
  int Units = number % 10;      // Units digit
  int Tens = (number / 10) % 10; // Tens digit

  if (Units >= 0 && Units <= 9) {
    PORTC &= ~(1 << LATCH0); // LATCH LOW
    shiftOutRegister(DATA0, CLOCK0, MSBFIRST, dataArray[Units]);
    PORTC |= (1 << LATCH0);  // LATCH HIGH
  }
  if (Tens >= 0 && Tens <= 9) {
    PORTC &= ~(1 << LATCH1); // LATCH LOW
    shiftOutRegister(DATA1, CLOCK1, MSBFIRST, dataArray[Tens]);
    PORTC |= (1 << LATCH1);  // LATCH HIGH
  }
}
