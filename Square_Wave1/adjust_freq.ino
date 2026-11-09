void adjust_freq(){
  delay60degree=1000000/(6*freq_f);
  delayWithoutDead=delay60degree - deadtime;
  if (displayF) digit(freq_f);
  else digit((int)current);
}
