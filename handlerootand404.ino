
void handleRoot() {
  
  String uptime = getUptime();
  
   String message = "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"utf-8\"><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
   message += "<!-- Latest compiled and minified CSS --><link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css\" integrity=\"sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u\" crossorigin=\"anonymous\"><link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css\" integrity=\"sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp\" crossorigin=\"anonymous\"><script src=\"https://code.jquery.com/jquery-3.1.1.min.js\"  integrity=\"sha256-hVVnYaiADRTO2PzUGmuLJr8BLUSjGIZsDYGmIJLv2b8=\" crossorigin=\"anonymous\"></script><script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js\" integrity=\"sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa\" crossorigin=\"anonymous\"></script>";
   message += "<title>ESP8266-01</title>";
   message += "</head><body style=\"text-align:center\">";
   message += "<div style=\"display: inline-block\">";
   message += "<h1 class=\"display-3\">Relay</h1>";
   message += "<a href='/GPIO0-ON/' style=\"padding:10px 60px;\" class=\"btn btn-success\">ON</a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
   message += "<a href='/GPIO0-OFF/' style=\"padding:10px 60px;\" class=\"btn btn-danger\">OFF</a>";
   message += "<p><br />Segundos que estara encendido el rele <form method='get' action='setting'><input name='segundosON' value='";
   message += segundosON/1000;
   message += "'  maxlength=\"7\" size=\"7\"> <input type='submit' value='Actualizar'></form>"; 
   message += "<br /><br /><h5>INFO:</h5><p class=\"lead\">";
   message += uptime;
   message += "<ul><li><a href='/GPIO0-ON/'>GPIO0 ON</a> -  ";
   message += "<a href='/GPIO0-OFF/'>GPIO0 Off</a></li>";
   message += "<li><a href='/GPIO2-ON/'>GPIO2 ON</a> -  ";
   message += "<a href='/GPIO2-OFF/'>GPIO2 Off</a></li>";
   message += "<li><a href='/SERVER-UPTIME/'>/SERVER-UPTIME/</a></li> ";
   message += "<li><a href='/GPIO0-STATUS/'>/GPIO0-STATUS/</a></li> ";
   message += "<li><a href='/GPIO2-STATUS/'>/GPIO2-STATUS/</a></li> ";
   message += "<li><a href='/SERVER-INFO/'>/SERVER-INFO/</a></li></ul></p>";
   message += "</div>";
   
   

   
   message += "</body></html>";
  server.send(200, "text/html", message);
}

void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}
