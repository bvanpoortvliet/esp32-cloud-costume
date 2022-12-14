void notFound(AsyncWebServerRequest *request) {  //404
  request->send(404, "text/html", "<h1>Not found, try again sucka!</h1>");
}

String HTML = "<!DOCTYPE html> \
<html>\
<head>\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\
<style>\
* {\
  box-sizing: border-box;\
}\
.main {\
  background-color: #f1f1f1;\
  padding: 5px;\
  float: left;\
  width: 100%; /* The width is 60%, by default */\
}\
body {\
    background-color: #FBFBFB;\
    padding: 0;\
    margin: 0;\
    font-family: Arial, Helvetica, sans-serif;\
}\
h3{\
    font-size: 26px;\
}\
h4{\
    font-size: 25px;\
}\
h5{\
    font-size: 20px;\
}\
.btn-group button {\
    width: 100%;\
    padding: 20px 20;\
    text-align: center;\
    background-color: grey;\
    color: white;\
    cursor: pointer;\
    display: block;\
    align-items: left;\
    justify-content: center;\
    border-radius: 5px;\
}\
.btn-group:after {\
  content: "";\
  clear: both;\
  display: table;\
}\
.btn-group button:not(:last-child) {\
  border-right: 0; /* Prevent double borders */\
}\
.btn-group button:hover {\
  background-color: #323732;\
}\
@media screen and (max-width: 800px) {\
  .left, .main, .right {\
    width: 100%; \
  }\
}\
</style>\
</head>\
<body>\
<div class=\"main\">\
 <h3>Trigger a scene.</h3>\
  <div class=\"btn-group\">\
  <form action=\"/\">\
    <button name=\"trigger\" value=\"1\"><h5>Colorbumps</h5></button>\
    <button name=\"trigger\" value=\"2\"><h5>Christmas Tree</h5></button>\
    <button name=\"trigger\" value=\"3\"><h5>Stars</h5></button>\
    <button name=\"trigger\" value=\"4\"><h5>Strobe</h5></button>\
    <button name=\"trigger\" value=\"5\"><h5>Chase 1</h5></button>\
    <button name=\"trigger\" value=\"6\"><h5>Chase 2</h5></button>\
    <button name=\"trigger\" value=\"7\"><h5>Chase 3</h5></button>\
    <button name=\"trigger\" value=\"8\"><h5>Rainbow Wave</h5></button>\
    <button name=\"trigger\" value=\"9\"><h5>Nightrider</h5></button>\
    <button name=\"trigger\" value=\"10\"><h5>Artnet Mode</h5></button>\
    <button name=\"trigger\" value=\"11\" style=\"color:red;\"><h5>RESET</h5></button>\
  </form>\
  </div>\
</div>\
</body>\
</html>";
