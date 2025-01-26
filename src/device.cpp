//
// Created by Elli Furedy on 1/25/2025.
//
#include "../include/device.hpp"

Device::Device() : display(U8G2_R0, displayCS, displayDC, displayRST) {
    pinMode(displayCS, OUTPUT);
    pinMode(displayDC, OUTPUT);
    digitalWrite(displayCS, 0);
    digitalWrite(displayDC, 0);

    display.begin();
    display.clearBuffer();
    display.setContrast(CONTRAST);
}

void Device::onStateChange() {
}