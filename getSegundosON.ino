void getSegundosON(){
  String stip;
  for (int i = 0; i < 7; ++i)
  {
  stip += char(EEPROM.read(i));
  }
  segundosON = stip.toInt()*1000;
}
