#include <ESP8266WiFi.h>
#include <SD.h>
#define CS_PIN  15

void setup() {
  Serial.begin(115200);
  
  if (!SD.begin(CS_PIN)) {
    Serial.println("Gagal, periksa apakah kartunya ada.");
    return;
  }
  
  Serial.println("Kartu diinisialisasi.");
  
}

void loop() {
  if(Serial.available()){
    String data = Serial.readStringUntil('\n');
    //char data = Serial.read();
    File dataFile = SD.open("LOG.txt", FILE_WRITE);
    if (dataFile) {
      dataFile.println(data);
      dataFile.close();
    }
    else {
    Serial.println("Gagal membuka file LOG.txt");
    }
  }
}
