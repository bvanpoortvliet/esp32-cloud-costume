#define LED_BUILTIN 5

uint32_t chipId = 0;
String get_info;

AsyncUDP udp;
String webserver_message;
String UDPread;
char udpBuf[100];

//Webserver variables
AsyncWebServer server(80);
const char *PARAM_MESSAGE = "trigger";

//Fastled variables
#define NUM_LEDS 48
#define DATA_PIN 2
CRGB leds[NUM_LEDS];

//Artnet variables
const int numberOfChannels = NUM_LEDS * 3;  // Total number of channels you want to receive (1 led = 3 channels)
ArtnetWifi artnet;
const int startUniverse = 0;  // CHANGE FOR YOUR SETUP most software this is 1, some software send out artnet first universe as 0.
const int maxUniverses = numberOfChannels / 512 + ((numberOfChannels % 512) ? 1 : 0);
bool universesReceived[maxUniverses];
bool sendFrame = 1;


void initleds(){
  FastLED.clear();
  Serial.println("Clearing LEDS");
    for (int i = 0 ; i < NUM_LEDS ; i++){
    leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();
}//END void initleds()

