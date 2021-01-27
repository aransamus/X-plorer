#include <Wire.h>
#include <Adafruit_BMP085.h>

/***************************************************
Codigo Original retirado do site
https://github.com/jarzebski/Arduino-BMP085-BMP180/blob/master/Processing/BMP085_processing/BMP085_processing.pde
http://www.jarzebski.pl/arduino/czujniki-i-sensory/czujniki-cisnienia-bmp085-bmp180.html

Sensor
https://www.adafruit.com/product/391

Esse codigo se comunica direto com o processing exibindo um grafico dos dados coletados. 


***************************************************/
 
Adafruit_BMP085 bmp;
 
float sealevelPressure; //Pressão relativa ao mar
 
void setup()
{
  Serial.begin(9600); //Comunicação com o arduino
 
  if (!bmp.begin())
  {
    Serial.println("Sensor não encontrado BMP085 / BMP180");
    while (1) {}
  }
}
 
void loop()
{
    // Leitura de temperatura e pressão
    float temp = bmp.readTemperature();  //Leitura da temperatura
    float pressure = bmp.readPressure(); //Leitura da da pressão
    
    // Nós próprios calculamos a altura
    sealevelPressure = 101325;
    float altitude = 44330 * (1.0 - pow(pressure / sealevelPressure, 0.1903));
    
    // Leitura da porta serial
    Serial.print("D:");
    Serial.print(temp);
    Serial.print(":");
    Serial.print(pressure);
    Serial.print(":");
    Serial.print(altitude);
    Serial.println();
    delay(60000);//Delay de 1 minuto
    //delay(6000);//Delay de 1 minuto
}
