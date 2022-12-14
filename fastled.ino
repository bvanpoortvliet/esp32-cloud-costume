void setup_fastled() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical
  FastLED.setBrightness(100);  //was 75, had approx 11hrs of colorfade uptime //apparently can go to 255, 200 did 4.5 hours so staying at 100.
}//END void setup_fastled()

