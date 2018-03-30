//  Display "Hellow Nano" on an Arduino Nano using one of those supersmall OLED displays from ALIEXPRESS.
//  This works on 128x32 displays.  If you have another OLED display that works on the SSD1306 chip, it should be in the library.
//  The required library to support this is called U8G2 and can be found in the manage libraries section of the Arduino IDE
//  The library is under Copyright (c) 2016, olikraus@gmail.com
//  Using this to set up an initial github repository only
//  This display library is fantastic - but even this small program manages to use 55% of the NANOs 2K RAM. 
//  Attach the OLED display VCC to a NANO 3.3V pin, GND to a NANO GND pin, SCL to NANO A5 and SDA to NANO A4
//  Some displays can take a 5V VCC but why chance it?
//  The program will also display the serial pins you need to use if you aren't using a NANO in the serial monitor.
//  Kim Tyson - kimtyson450@gmail.com

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// change this line to match your display - see examples loaded from the U8G2 library install.
U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   

void setup(void) {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.println(SDA);
  Serial.println(SCL);
  u8g2.begin();
}

void loop(void) {
  u8g2.clearBuffer();					          // clear the OLED display
  u8g2.setFont(u8g2_font_ncenB08_tr);	  // pick a font
  u8g2.drawStr(0,10,"Hello Nano");	    // write the message over and over to arduino memory
  u8g2.sendBuffer();					          // transfer the arduino memory to the OLED
  delay(1000);  
}

