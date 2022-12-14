# ESP32 Cloud Costume
[LilyGO T-Energy ESp-32](http://www.lilygo.cn/prod_view.aspx?TypeId=50033&Id=1170&FId=t3:50033:3) based cloud costume with WS2812B LEDs.

#### This is a glorified todo list, code will appear later.

#### Parts:
- MCU:	ESP32
- PSU:	18650
- LEDS:	WS2812B

## Description:
3 ESP32 MCU's that spawn a softAP mesh. Via MDNS you can navigate to cloud.local which serves a page on which you can trigger lightsequences.
Per trigger from webserver the node broadcasts over UDP/Mesh to all nodes, which in their turn listen to these messages and also trigger their sequences creating a "sync" - ish. Every scene has it's own trigger. Plus, Artnet control over the leds.

## Scenes:
1. Colorbumps  
2. Christmas Tree  
3. Stars  
4. Strobe  
5. Chase 1  
6. Chase 2  
7. Chase 3  
8. Rainbow Wave  
9. Nightrider  
10. Artnet Mode  
11. All OFF/Reset Wireless comms  

## Led division
- Total of 144 Leds
- 144 /3 costumes = 48 leds per costume
- 48 /4 = 12 leds per row

##### Physical layout
X - X - X - X - X - X - X - X - X - X - X - X

X - X - X - X - X - X - X - X - X - X - X - X

X - X - X - X - X - X - X - X - X - X - X - X

X - X - X - X - X - X - X - X - X - X - X - X

## Resources:
- [Serial Drivers](https://github.com/WCHSoftGroup/ch34xser_macos)
- [Webserver](https://github.com/me-no-dev/ESPAsyncWebServer) requires [this library](https://github.com/me-no-dev/AsyncTCP)
- [LED Library](https://github.com/FastLED/FastLED)
- [Mesh Library](https://github.com/gmag11/painlessMesh) requires [this library](https://github.com/me-no-dev/AsyncTCP)
- [Artnet Library](https://github.com/rstephan/ArtnetWifi)
- [ArtnetWifiFastled](https://github.com/rstephan/ArtnetWifi/blob/master/examples/ArtnetWifiFastLED/ArtnetWifiFastLED.ino)
- [Captive portal](https://github.com/espressif/arduino-esp32/blob/master/libraries/DNSServer/examples/CaptivePortal/CaptivePortal.ino)

## Docs:
- [Mesh](https://randomnerdtutorials.com/esp-mesh-esp32-esp8266-painlessmesh/#2)
- [Captive portal](https://iotespresso.com/create-captive-portal-using-esp32/)

## Tests
| Status           | Test | Comment   |
|----------------|---------------|---------------|
| <ul><li>- [x] </li></ul>   | Duration of 18650                    | 11 hrs on 100 brightness, 4.5 on 255 brightness |
| <ul><li>- [x] </li></ul>   | Which led library to use             | FastLED for sure | 
| <ul><li>- [x] </li></ul>   | Wifi mesh vs UDP                     | UDP, mesh kills Artnet compatibility | 
| <ul><li>- [x] </li></ul>   | ArtnetWifi and Fastled               | Works as expected | 
| <ul><li>- [x] </li></ul>   | MDNS                                 | Works as expected | 
| <ul><li>- [x] </li></ul>   | Captive portal serving control page  | Cannot read GET request on portal page, try with different server X failed! | 
