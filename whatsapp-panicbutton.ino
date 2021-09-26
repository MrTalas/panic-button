#include <ESP8266WiFi.h>
#include <ThingESP.h> //Gerekli kütüphaneyi dahil ediyoruz.
#define voltajpin D5
ThingESP8266 thing("username","project-name","no");

//www.github.com/RootTalas
//https://www.instagram.com/p/CUSDTIPjd7-/


void setup() {
  pinMode(voltajpin,INPUT);
  Serial.begin(9600); //Seri haberleşmeyi başlatıyoruz.
  thing.SetWiFi("ssid","password"); //Wi-Fi bilgilerimizi giriyoruz.

  thing.initDevice();
} 



void loop() {
  int deger = digitalRead(voltajpin);
    if(deger == HIGH) //Eğer butona basıldıysa
    {
      Serial.println("+"); //Kontrol amaçlı Seri ekrana "+" yazıyor.
    }

    if (deger == HIGH)//Eğer butona basıldıysa
    {
    String msg = "Done: Panik Butonu Aktif Hemen 112'yi Arayınız ! "; //Whatsapp'dan bize gönderilen mesaj.
    
    thing.sendMsg("+905XXXXXXXXXX", msg); //Numaraya belirtilen mesajı gönder.
 
    }
   thing.Handle(); 
}
