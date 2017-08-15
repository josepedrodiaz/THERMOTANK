void processURLs(){

  server.on("/GPIO0-STATUS/", [](){
     String pinstatus = String(digitalRead(gpio0));
    server.send(200, "text/html", pinstatus);
  });
  
  server.on("/GPIO2-STATUS/", [](){
     String pinstatus = String(digitalRead(gpio2));
    server.send(200, "text/html", pinstatus);
  });

  server.on("/SERVER-INFO/", [](){
    String uptime = getUptime();
    String pin0status = String(digitalRead(gpio0));
    String pin2status = String(digitalRead(gpio2));
    String message =  "{\"uptime\":\"" + uptime + "\",";
    message +=  "\"pin0status\":\"" + pin0status + "\",";
    message +=  "\"pin2status\":\"" + pin2status + "\"";
    if(lastON != 0){
    message +=  "\",pin0TimeOut:\"" + String((segundosON - (millis() - lastON))) + "\"";
    }
    message +=  "}"; 
    server.send(200, "application/json", message);
  });
  
  server.on("/SERVER-INFO-JSON/", [](){
    String uptime = getUptime();
     String message =  uptime;
    server.send(200, "text/html", message);
  });
  
  server.on("/GPIO0-ON/", [](){
    digitalWrite(gpio0, HIGH);
    if(lastON <= 0){
      lastON = millis();
    }
    server.send(200, "text/html", "Led ON  <script>function vuelve() {window.location.href='/';}setTimeout(vuelve, 1000)</script>");
  });
  
  server.on("/GPIO0-OFF/", [](){
    digitalWrite(gpio0, LOW);
    lastON = 0;
    server.send(200, "text/html", "Led OFF <script>function vuelve() {window.location.href='/';}setTimeout(vuelve, 1000)</script>");
  });
   
  server.on("/GPIO2-ON/", [](){
    digitalWrite(gpio2, HIGH);
    server.send(200, "text/html", "Led ON  <script>function vuelve() {window.location.href='/';}setTimeout(vuelve, 1000)</script>");
  });
  
  server.on("/GPIO2-OFF/", [](){
    digitalWrite(gpio2, LOW);
    server.send(200, "text/html", "Led OFF <script>function vuelve() {window.location.href='/';}setTimeout(vuelve, 1000)</script>");
  });
  
   
   server.on("/setTimeout", []() {
      String stip = server.arg("segundosON");
      if (stip.length() > 0 ) {
        for (int i = 0; i < 7; ++i) {
          EEPROM.write(i, 0); //clearing
        }
        EEPROM.commit();
        
        for (int i = 0; i < 7 ; ++i)
        {
          EEPROM.write(i, stip[i]);
        }
        EEPROM.commit();
        
        server.send(200, "text/html", "Actualizada la rom - <script>function vuelve() {window.location.href='/';}setTimeout(vuelve, 1000)</script>");
      }
   });



}
