// connect to wifi – returns true if successful or false if not
bool ConnectWifi(void){
  #define   STATION_SSID     "AP"
  #define   STATION_PASSWORD "PASSWORD"

  bool state = true;
  int i = 0;

  WiFi.begin(STATION_SSID, STATION_PASSWORD);

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    if (i > 20){
      state = false;
      break;
    }
    i++;
  }
  if (state) {
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(STATION_SSID);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("");
    Serial.println("Connection failed.");
  }
  return state;
}

void check_wifi_conn() {
  if ((WiFi.status() != WL_CONNECTED)) {
    WiFi.disconnect();
    WiFi.reconnect();
    }
  }//END void check_wifi_conn()
