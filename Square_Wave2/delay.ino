void Delay_and_DisplayTime() {
  currentMeasure();
  delayMicroseconds(delayWithoutDead-micros()+CT_time);
}
