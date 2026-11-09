void adjust_freq(){
  delay60degree=1000000/(6*freq_f);
  delayWithoutDead=delay60degree - deadtime;
  digit(freq_f);
}
