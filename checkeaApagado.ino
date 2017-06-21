void checkeaApagado(){
  if(lastON != 0){
    if((millis() - lastON) >= (segundosON)){
      digitalWrite(gpio0, LOW);
      lastON = 0;
    }
  }
}

