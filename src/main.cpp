#include <Arduino.h>

#include "device.hpp"
#include "nametag-app.hpp"

Device* nameTag;
NameTagApp nameTagApp = NameTagApp(nameTag);

void setup() {

}

void loop() {
    nameTagApp.loop();
}
