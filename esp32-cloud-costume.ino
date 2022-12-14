#include <ArtnetWifi.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <ESPmDNS.h>
#include <FastLED.h>
#include "webpage.h"
#include "vars.h"

void setup() {
  Serial.begin(9600);
  delay(1000);  //give serial a moment to start
  pinMode(LED_BUILTIN, OUTPUT);  //Blue led just in case we'd wanna use it.

  setup_fastled();
  WiFi.softAP("Cloud Control", "");
  ConnectWifi();               //must be called before artnet and mesh begin
  run_udp();
  setup_artnet();

  //WEBSERVER SETUP
  //Start server and route /
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {  //index
    if (request->hasParam(PARAM_MESSAGE)) {
      webserver_message = request->getParam(PARAM_MESSAGE)->value();
      udp.broadcast(webserver_message.c_str());  //Send to other nodes via udp broadcast
    }
    request->send(200, "text/html", HTML);  //Serve HTML from webpage.h
  });

  server.on("/info", HTTP_GET, [](AsyncWebServerRequest *request) {  //create shoddy info page
    for (int i = 0; i < 17; i = i + 8) {
      chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
    }

    uint8_t uptime = millis();
    String localip = String() + WiFi.localIP()[0] + "." + WiFi.localIP()[1] + "." + WiFi.localIP()[2] + "." + WiFi.localIP()[3];
    String apip = String() + WiFi.softAPIP()[0] + "." + WiFi.softAPIP()[1] + "." + WiFi.softAPIP()[2] + "." + WiFi.softAPIP()[3];

    get_info = "<body style=\"background-color: #FBFBFB; padding: 0; margin: 0; font-family: Arial, Helvetica, sans-serif;\"> <h1>Info:</h1><h2> ESP32 AccessPoint IP: " + apip + " <br> ESP32 LocalClient IP: " + localip + " <br> <br>Chip ID: " + String(chipId) + " <br>Chip model: " + ESP.getChipModel() + ESP.getChipRevision() + " <br>Amount of Cores: " + ESP.getChipCores() + "<br><br> <a href=\"https://github.com/bvanpoortvliet/esp32-cloud-costume\">View       this project on GitHub</a></h2></body>";
    request->send(200, "text/html", get_info);
  });

  //serve 404 when no page can be served due to 404
  server.onNotFound(notFound);  //check notFound callback func above

  server.begin();
  setup_mdns();
  scene_preset();
}

void loop() {
  get_scene();
} //END void loop()
