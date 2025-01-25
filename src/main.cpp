#include <Arduino.h>
#include <epd2in13_V4.h>
#include "epdpaint.h"
#include "imagedata.h"

#define COLORED     0
#define UNCOLORED   1


unsigned char image[1050];
Paint paint(image, 0, 0);
Epd epd;


void setup() {
  epd.Init(FULL);
  Paint paint(image, epd.bufwidth*8, epd.bufheight);    //width should be the multiple of 8

  paint.Clear(UNCOLORED);
  epd.Display1(image);//1

  paint.Clear(UNCOLORED);
  paint.DrawRectangle(2,2,50,50,COLORED);
  paint.DrawLine(2,2,50,50,COLORED);
  paint.DrawLine(2,50,50,2,COLORED);
  paint.DrawFilledRectangle(52,2,100,50,COLORED);
  paint.DrawLine(52,2,100,50,UNCOLORED);
  paint.DrawLine(100,2,52,50,UNCOLORED);
  epd.Display1(image);//2
  
  paint.Clear(UNCOLORED);
  paint.DrawCircle(25,25,20,COLORED);
  paint.DrawFilledCircle(75,25,20,COLORED);
  epd.Display1(image);//3
  
  paint.Clear(UNCOLORED);
  epd.Display1(image);//4

  delay(2000);

  epd.Clear();

}

void loop() {

  // delay(2000);
  // epd.Display_Fast(IMAGE_DATA);


}
