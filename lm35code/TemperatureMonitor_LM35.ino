#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
float vref = 3.3;
float resolution = vref / 1023.0;
float temperature;
char auth[] = " LesE00ClovyiU8_4KzXdnEpsSJHjjmw2";//yourauthtoken
char ssid[] = "A50";//name of your wifi
char pass[] = "12345678";//password of wifi
BlynkTimer timer;
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
timer.setInterval(2000, sendUptime);
}
void sendUptime()
{
float temperature = analogRead(A0);//lm35 is connected to pin A0 on NodeMcu
temperature = (temperature * resolution);
temperature = temperature * 100.0;
Serial.print("DHT11 temperature value : ");//serial print the value
Serial.println(temperature);
Blynk.virtualWrite(V0, temperature);//send the value to blynk application
Blynk.virtualWrite(V1, temperature-9);
}
void loop()
{
float temperature = analogRead(A0);//lm35 is connected to pin A0 on NodeMcu
temperature = (temperature * resolution);
temperature = temperature * 100.23;
Serial.print("DHT11 humidity value: ");//serial print the value
Serial.println(temperature);
Blynk.virtualWrite(V0, temperature);//send the value to blynk application
Blynk.virtualWrite(V1, temperature-11.7);
Blynk.virtualWrite(V4, temperature*24.67);
if(temperature>=29)
{
Blynk.email("saichakri26@gmail.com", "ESP8266 Alert", "temperature is raising");
Blynk.notify("ESP8266 Alert = temperature is raising");
}
Blynk.run();
timer.run();
}
