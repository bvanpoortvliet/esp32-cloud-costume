/*                          LAYOUT OF LEDS
*                             46   - 47
*
*                         45   - 44  - 43
*
*                  37  - 38   - 39  - 40  - 41  - 42
*
*                  36  - 35   - 34  - 33  - 32  - 31                 
*
*                24  - 25  - 26  - 27  - 28  - 29  - 30
*
* 23  - 22  - 21  - 20  - 19  - 18  - 17  - 16  - 15  - 14  - 13  - 12
*
* 0   - 1  - 2   - 3   - 4   - 5   - 6   - 7   - 8   - 9  - 10  - 11
* https://github.com/marmilicious/FastLED_examples
*/

//Scenes
// 1 = Colorbumps
// 2 = Christmas Tree
// 3 = Stars
// 4 = Strobe
// 5 = Chase 1
// 6 = Chase 2
// 7 = Chase 3
// 8 = Rainbow Wave
// 9 = Nightrider
// 10 = Artnet Mode
// 11 = All OFF

void get_scene() {
  if (webserver_message == "1" ||UDPread == "1") {
    FastLED.clear();
     scene1();
     }
  else if (webserver_message == "2" ||UDPread == "2") {
    FastLED.clear();
    scene2();
  }
  else if (webserver_message == "3" ||UDPread == "3") {
    FastLED.clear();
    scene3();
  }
  else if (webserver_message == "4" || UDPread == "4") {
    FastLED.clear();
    scene4();
  }
  else if (webserver_message == "5" || UDPread == "5") {
    FastLED.clear();
    chase1();
  }
  else if (webserver_message == "6" || UDPread == "6") {
    FastLED.clear();
    chase2();
  }
  else if (webserver_message == "7" || UDPread == "7") {
    FastLED.clear();
    chase3();
  }
  else if (webserver_message == "8" || UDPread == "8") {
    FastLED.clear();
    rainbowwave();
  }
  else if (webserver_message == "9" || UDPread == "9") {
    FastLED.clear();
    nightrider();
  }
  else if (webserver_message == "10" || UDPread == "10") {
    artnet.read();
 }
  else if (webserver_message == "11" || UDPread == "11") {
    off_reset();
 }
}//END get_scenes()

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } }


void scene1() { //Colorbumps
FastLED.setBrightness(100); 

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;
    FastLED.show();
    delay(2.5);
  }
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Green;
    FastLED.show();
    delay(2.5);
  }
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(2.5);
  }
    for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(2.5);
  }
}//END void scene1

void scene2() { //Christmastree
FastLED.setBrightness(100); 

int christmastree_outterleds[12] = {0, 11, 13, 22, 25, 29, 32, 35, 39, 40, 44};
int christmastree_innerleds[25] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 14, 15, 16, 17, 18, 19, 20, 21, 26, 27, 28, 33, 34};

int i, j;
for (int i = 0; i < 12; i++) {
    leds[christmastree_outterleds[i]].r = 56;
    leds[christmastree_outterleds[i]].g = 133;
    leds[christmastree_outterleds[i]].b = 53;      
}

for (int j = 0; j < 25; j++) {
    leds[christmastree_innerleds[j]].r = 15;
    leds[christmastree_innerleds[j]].g = 237;
    leds[christmastree_innerleds[j]].b = 7;
}
FastLED.show();
}//END void scene2 christmastree()

void scene3() { //Stars
sparkles(random8(80,240), 255, 100);
FastLED.show();
}//END void scene3

void scene4() { //STROBE
FastLED.setBrightness(100); 
for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White;
    }
    EVERY_N_MILLISECONDS(200) {
    FastLED.show();
    }
for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    }
    EVERY_N_MILLISECONDS(200) {
    FastLED.show();
    }
}//END void scene4

void chase1() { //outward pattern per dot

FastLED.setBrightness(100); 
    #define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))
  const uint8_t line1left[] =  {5,4,3,2,1,0};
  const uint8_t line1right[] = {6,7,8,9,10,11};
  const uint8_t line2left[] =  {18,19,20,21,22,23};
  const uint8_t line2right[] = {17,16,15,14,13,12};
  const uint8_t line3left[] =  {26,25,24};
  const uint8_t line3right[] = {28,29,30};
  const uint8_t line4left[] =  {34,35,36};
  const uint8_t line4right[] = {33,32,31};
  const uint8_t line5left[] =  {39,38,37};
  const uint8_t line5right[] = {40,41,42};
  const uint8_t line6left[] = {45};
  const uint8_t line6right[] = {43};
  const uint8_t line7left[] = {46};
  const uint8_t line7right[] = {47};
  const uint8_t line1leftSize = sizeof(line1left);
  const uint8_t line1rightSize = sizeof(line1right);
  const uint8_t line2leftSize = sizeof(line2left);
  const uint8_t line2rightSize = sizeof(line2right);
  const uint8_t line3leftSize = sizeof(line3left);
  const uint8_t line3rightSize = sizeof(line3right);
  const uint8_t line4leftSize = sizeof(line4left);
  const uint8_t line4rightSize = sizeof(line4right);
  const uint8_t line5leftSize = sizeof(line5left);
  const uint8_t line5rightSize = sizeof(line5right);
  const uint8_t line6leftSize = sizeof(line6left);
  const uint8_t line6rightSize = sizeof(line6right);
  const uint8_t line7leftSize = sizeof(line7left);
  const uint8_t line7rightSize = sizeof(line7right);

  for(int i = 0; i < line1leftSize; i++){
    leds[line1left[i]] = CRGB::Red;
    leds[line1right[i]] = CRGB::Green;
  delay(50);
  FastLED.show();
  }
  for(int i = 0; i < line2leftSize; i++){
    leds[line2left[i]] = CRGB::Green;
    leds[line2right[i]] = CRGB::Red;
  delay(50);
  FastLED.show();
  }
  for(int i = 0; i < line3leftSize; i++){
    leds[line3left[i]] = CRGB::Red;
    leds[line3right[i]] = CRGB::Green;
    delay(50);
  FastLED.show();
  }
  for(int i = 0; i < line4leftSize; i++){
    leds[line4left[i]] = CRGB::Red;
    leds[line4right[i]] = CRGB::Green;
  delay(100);
  FastLED.show();
  }
  for(int i = 0; i < line5leftSize; i++){
    leds[line5left[i]] = CRGB::Green;
    leds[line5right[i]] = CRGB::Red;
  delay(100);
  FastLED.show();
  }
  for(int i = 0; i < line6leftSize; i++){
    leds[line6left[i]] = CRGB::Red;
    leds[line6right[i]] = CRGB::Green;
  delay(200);
  FastLED.show();
  }
  for(int i = 0; i < line7leftSize; i++){
    leds[line7left[i]] = CRGB::Green;
    leds[line7right[i]] = CRGB::Red;
  delay(200);
  FastLED.show();
  }
  for(signed int i = line7leftSize -1; i >= 0; i--){
    leds[line7left[i]] = CRGB::Black;
    leds[line7right[i]] = CRGB::Black;
  delay(200);
  FastLED.show();
  } 
  for(signed int i = line6leftSize -1; i >= 0; i--){
    leds[line6left[i]] = CRGB::Black;
    leds[line6right[i]] = CRGB::Black;
  delay(200);
  FastLED.show();
  } 
  for(signed int i = line5leftSize -1; i >= 0; i--){
    leds[line5left[i]] = CRGB::Black;
    leds[line5right[i]] = CRGB::Black;
  delay(100);
  FastLED.show();
  }
  for(signed int i = line4leftSize -1; i >= 0; i--){
    leds[line4left[i]] = CRGB::Black;
    leds[line4right[i]] = CRGB::Black;
  delay(100);
  FastLED.show();
  }
  for(signed int i = line3leftSize -1; i >= 0; i--){
    leds[line3left[i]] = CRGB::Black;
    leds[line3right[i]] = CRGB::Black;
  delay(50);
  FastLED.show();
  }
  for(signed int i = line2leftSize -1; i >= 0; i--){
    leds[line2left[i]] = CRGB::Black;
    leds[line2right[i]] = CRGB::Black;
  delay(50);
  FastLED.show();
  }
  for(signed int i = line1leftSize -1; i >= 0; i--){
    leds[line1left[i]] = CRGB::Black;
    leds[line1right[i]] = CRGB::Black;
  delay(50);
  FastLED.show();
  }
}//END void chase1


signed int hue;
void chase2() { //outward pattern by row
for (int brightness = 0; brightness < 100; brightness+=5) {
FastLED.setBrightness(brightness); 
FastLED.show();
delay(5);
}

leds[5].setHue(hue++);               
  leds[18].setHue(hue++);   
    leds[26].setHue(hue++);    
      leds[34].setHue(hue++);    
        leds[39].setHue(hue++);    
          leds[45].setHue(hue++);    
            leds[46].setHue(hue++);
              leds[27].setHue(hue++);
leds[6].setHue(hue++);  
  leds[17].setHue(hue++);  
    leds[28].setHue(hue++);  
      leds[33].setHue(hue++);  
        leds[40].setHue(hue++);  
          leds[43].setHue(hue++);  
            leds[47].setHue(hue++);   
              leds[44].setHue(hue++);
FastLED.show();
delay(100);

leds[4].setHue(hue++);  
  leds[19].setHue(hue++);  
    leds[25].setHue(hue++);  
      leds[35].setHue(hue++);  
        leds[38].setHue(hue++);  
leds[7].setHue(hue++);  
  leds[16].setHue(hue++);  
    leds[29].setHue(hue++);  
      leds[32].setHue(hue++);  
        leds[41].setHue(hue++);  
FastLED.show();
delay(100);

leds[3].setHue(hue++);  
  leds[20].setHue(hue++);  
    leds[24].setHue(hue++);  
      leds[36].setHue(hue++);  
        leds[37].setHue(hue++);  
leds[8].setHue(hue++);  
  leds[15].setHue(hue++);  
    leds[30].setHue(hue++);  
      leds[31].setHue(hue++);  
        leds[42].setHue(hue++);  
FastLED.show();
delay(100);

leds[2].setHue(hue++);  
  leds[21].setHue(hue++);  
leds[9].setHue(hue++);  
  leds[14].setHue(hue++);  
FastLED.show();
delay(100);

leds[1].setHue(hue++);  
  leds[22].setHue(hue++);  
leds[10].setHue(hue++);  
  leds[13].setHue(hue++);  
FastLED.show();
delay(100);

leds[0].setHue(hue++);  
  leds[23].setHue(hue++);  
leds[1].setHue(hue++);  
  leds[12].setHue(hue++);  
FastLED.show();
delay(100);

//TO BLACK
leds[0] = CRGB::Black;
  leds[23] = CRGB::Black;
leds[1] = CRGB::Black;
  leds[12] = CRGB::Black;
FastLED.show();
delay(100);

leds[1] = CRGB::Black;
  leds[22] = CRGB::Black;
leds[10] = CRGB::Black;
  leds[13] = CRGB::Black;
FastLED.show();
delay(100);

leds[2] = CRGB::Black;
  leds[21] = CRGB::Black;
leds[9] = CRGB::Black;
  leds[14] = CRGB::Black;
FastLED.show();
delay(100);

leds[3] = CRGB::Black;
  leds[20] = CRGB::Black;
    leds[24] = CRGB::Black;
      leds[36] = CRGB::Black;
        leds[37] = CRGB::Black;
leds[8] = CRGB::Black;
  leds[15] = CRGB::Black;
    leds[30] = CRGB::Black;
      leds[31] = CRGB::Black;
        leds[42] = CRGB::Black;
FastLED.show();
delay(100);

leds[4] = CRGB::Black;
  leds[19] = CRGB::Black;
    leds[25] = CRGB::Black;
      leds[35] = CRGB::Black;
        leds[38] = CRGB::Black;
leds[7] = CRGB::Black;
  leds[16] = CRGB::Black;
    leds[29] = CRGB::Black;
      leds[32] = CRGB::Black;
        leds[41] = CRGB::Black;
FastLED.show();
delay(100);

for (int brightness = 100; brightness > 0; brightness-=5) {
  FastLED.setBrightness(brightness); 
  FastLED.show();
  delay(5); 
}
if ( hue > 255) {
  hue = 0;
  }
}//END void chase2


void chase3() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].setHue(hue);
  }
    hue+=10;
    EVERY_N_MILLISECONDS(100) {
    FastLED.show();
    }
    // FastLED.show();
    // delay(10);

    for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    EVERY_N_MILLISECONDS(100) {
    FastLED.show();
    }
    // FastLED.show();
    // delay(10);
  }
  if ( hue > 255) {
  hue = 0;
  }
}//END void chase3



void rainbowwave() {
FastLED.setBrightness(100); 
static uint8_t hue = 0; 
	for(int i = 0; i < NUM_LEDS; i++) { // First slide the led in one direction
		leds[i] = CHSV(hue++, 255, 255); // Set the i'th led to red 
		FastLED.show(); // Show the leds
    // leds[i] = CRGB::Black; // now that we've shown the leds, reset the i'th led to black
		fadeall();
		delay(10);	// Wait a little bit before we loop around and do it again
	}
  
  for(int i = (NUM_LEDS)-1; i >= 0; i--) {// Now go in the other direction.  
    leds[i] = CHSV(hue++, 255, 255); // Set the i'th led to red 
    FastLED.show(); // Show the leds
    // leds[i] = CRGB::Black; // now that we've shown the leds, reset the i'th led to black
    fadeall();  
    delay(10);// Wait a little bit before we loop around and do it again
  }
}//END void rainbowwave

void nightrider() {
  knightRiderAnimation(255, 0, 0, 5, 10, 50);
  // knightRiderAnimation(0, 255, 0, 5, 10, 50);
  // knightRiderAnimation(0, 0, 255, 5, 10, 50);
}//END void nightrider

void sparkles(uint8_t sparkel_duration, uint8_t sparkel_amount, uint8_t sparkel_spread) {
  static uint8_t sparkle_pixel;
  EVERY_N_MILLISECONDS_I( timingObj, 1) {
    timingObj.setPeriod(sparkel_duration);
    leds[sparkle_pixel] = CRGB::Black;
    uint8_t previous_pixel = sparkle_pixel;
    while (previous_pixel == sparkle_pixel) {  // pixel can't repeat
      sparkle_pixel = random8(NUM_LEDS);
    }
    if (random8(100) < sparkel_amount) {
      //leds[sparkle_pixel] = CRGB(random8(), random8(), random8());
      leds[sparkle_pixel] = CRGB::White; //CHSV(random8(), random8(20,200), random8(50,255));
    }
  }
  EVERY_N_MILLISECONDS(50) {
    fadeToBlackBy(leds, NUM_LEDS, 1);  // fade out a bit over time
    blur1d(leds, NUM_LEDS, sparkel_spread);  // spreads and fades out color over time
  }
}// end void sparkles()

void knightRiderAnimation(int red, int green, int blue, int ridingWidth, int delayDuration, int returnDelayDuration){
  for(int i = 0; i < (NUM_LEDS - ridingWidth - 2); i++) {
    FastLED.clear();
    FastLED.show();
    leds[i].setRGB(red/10, green/10, blue/10);
    for(int j = 1; j <= ridingWidth; j++) {
      leds[i + j].setRGB(red, green, blue);
    }
    leds[i + ridingWidth + 1].setRGB(red/10, green/10, blue/10);
    FastLED.show();
    delay(delayDuration);
  }
  delay(returnDelayDuration);

  for(int i = (NUM_LEDS - ridingWidth - 2); i > 0; i--) {
    FastLED.clear();
    FastLED.show();
    leds[i].setRGB(red/10, green/10, blue/10);
    for(int j = 1; j <= ridingWidth; j++) {
      leds[i + j].setRGB(red, green, blue);
    }
    leds[i + ridingWidth + 1].setRGB(red/10, green/10, blue/10);
    FastLED.show();
    delay(delayDuration);
  }
  delay(returnDelayDuration);
}//END void nightriderAnimation()

//MAINTENANCE SEQUENCES
void scene_preset() {
  for (int i = 0 ; i < NUM_LEDS ; i++) {
    leds[i] = CRGB(127, 0, 0);
  }
  FastLED.show();
  delay(500);

  for (int i = 0 ; i < NUM_LEDS ; i++){
    leds[i] = CRGB(0, 127, 0);
  }
  FastLED.show();
  delay(500);

  for (int i = 0 ; i < NUM_LEDS ; i++){
    leds[i] = CRGB(0, 0, 127);
  }
  FastLED.show();
  delay(500);

  for (int i = 0 ; i < NUM_LEDS ; i++){
    leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();
}//END void scene_preset

void off_reset() {
  Serial.println("off/reset");

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }
    FastLED.show();
    webserver_message = "";
    UDPread = "";
    check_wifi_conn();
    return;
}//END void blinkrgb
