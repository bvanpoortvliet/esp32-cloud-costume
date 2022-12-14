void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data){
  sendFrame = 1;
  
  if (universe == 15){                        // set brightness of the whole strip
    FastLED.setBrightness(data[0]);
    FastLED.show();
  }

  if (universe < startUniverse){              // range check
    return;
  }
  uint8_t index = universe - startUniverse;
  if (index >= maxUniverses){
    return;
  }

  universesReceived[index] = true;             // Store which universe has got in

  for (int i = 0 ; i < maxUniverses ; i++){
    if (!universesReceived[i]){
      sendFrame = 0;
      break;
    }
  }

  for (int i = 0; i < length / 3; i++){         // read universe and put into the right part of the display buffer
    int led = i + (index * 170);
    if (led < NUM_LEDS){
      leds[led] = CRGB(data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
    }
  }

  if (sendFrame) {
    FastLED.show();
    memset(universesReceived, 0, maxUniverses);  // Reset universeReceived to 0
  }
}

void setup_artnet() {
    artnet.begin();
    memset(universesReceived, 0, maxUniverses);
    artnet.setArtDmxCallback(onDmxFrame); // this will be called for each packet received
}
