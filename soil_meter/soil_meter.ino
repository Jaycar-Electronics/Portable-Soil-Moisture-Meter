#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(0);

#define BATTERY_WIDTH 10

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(3);
  display.setCursor(30,0);
  display.println("Soil");
  
  display.setTextSize(1);
  display.setCursor(30,display.height()-8);
  display.println("Meter");
  display.display();
  delay(3000);
  display.setTextSize(4);
}

void loop() {
  // put your main code here, to run repeatedly:
  int battery_level = analogRead(A6);
  battery_level = (battery_level / 1024) * 32; //as a percentage of screen height
  int sensor_reading = analogRead(A7);
  
  display.clearDisplay();

  //draw a battery bar to show the amount of charge left.
  display.fillRect(0,battery_level,BATTERY_WIDTH,display.height(),WHITE);
  
  //sensor reading takes up most of the display
  display.setCursor(30,0);
  display.println(sensor_reading,DEC);
  
  display.display();
  delay(1000);
}
