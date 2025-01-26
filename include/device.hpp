//
// Created by Elli Furedy on 1/25/2025.
//
#pragma once
#include <../.pio/libdeps/esp32-s3-devkitc-1/U8g2/src/U8g2lib.h>



class Device {

public:
    Device();
    U8G2_SSD1309_128X64_NONAME0_F_4W_HW_SPI display;
    void onStateChange();

private:


    const int displayCS = 10;
    const int displayDC = 9;
    const int displayRST = 14;

    const int CONTRAST = 155;
};
