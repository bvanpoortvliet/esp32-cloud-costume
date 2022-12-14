void setup_mdns(){
      if (!MDNS.begin("cloud")) {
        while(1) {
            delay(1000);
        }
    }
    MDNS.addService("http", "tcp", 80);
} //end void setup_mdns()
