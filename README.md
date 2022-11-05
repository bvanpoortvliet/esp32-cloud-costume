# esp32-cloud-costume
ESP32 based cloud costume with leds


### This is a glorified todo list, code will appear later.

#### Parts:
MCU:	ESP32
PSU:	18650
LEDS:	WS2812B

## Description:
3 ESP32 MCU's in a mesh network that spawn one AP
Upon connection to the AP a captive portal is served
The captive portal serves a page on which you can trigger lightsequences
Per trigger (ajax functie or get parameter) broadcasts over UDP/Mesh to all nodes
Every scene has it's own trigger
If there's enough time we'd like to implement artnet

## Scenes:
1. Rainbow/CMY chase
2. R -> G -> B Blink alle
3. Per led follow sequence
4. Buiten naar binnen, nightrider
5. 
6.
7.
8.
9.
10.

## Led division
Total of 144 Leds
144 /3 costumes = 48 leds per costume
48 /4 = 12 leds per row

X - X - X - X - X - X - X - X - X - X - X

X - X - X - X - X - X - X - X - X - X - X

X - X - X - X - X - X - X - X - X - X - X

X - X - X - X - X - X - X - X - X - X - X

## TODO Option:
Als extra optie artnet node inbouwen die als slave van een QLC of OLA instance met de lichttafel mee kan doen op dmx in.
I THINK WE NEED THIS:
https://github.com/rstephan/ArtnetWifi/blob/master/examples/ArtnetWifiFastLED/ArtnetWifiFastLED.ino

## Resources:
[LED Library:]    (https://www.arduino.cc/reference/en/libraries/freenove-ws2812-lib-for-esp32)
[LED Alternative] (https://github.com/FastLED/FastLED)
[Mesh Library] 	  (https://github.com/gmag11/painlessMesh)
[Artnet Library]  (https://github.com/rstephan/ArtnetWifi)
[Captive portal]  (https://github.com/espressif/arduino-esp32/blob/master/libraries/DNSServer/examples/CaptivePortal/CaptivePortal.ino)
[Webserver]       (https://github.com/me-no-dev/ESPAsyncWebServer) needs [this] (https://github.com/me-no-dev/AsyncTCP)

## Docs:
[Mesh]            (https://randomnerdtutorials.com/esp-mesh-esp32-esp8266-painlessmesh/#2)
[Captive portal]  (https://iotespresso.com/create-captive-portal-using-esp32/)

## To test:
- [ ] Duration of 18650
- [ ] Which led library to use
- [ ] Wifi mesh
- [ ] Captive portal to control page
- [ ] UDP broadcast to mesh/mesh messages
- [ ] ArtnetWifi and Fastled
- [ ] 
