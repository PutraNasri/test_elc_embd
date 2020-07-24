#include <ESP8266WiFi.h> //sesuaikan dengan jenis esp yang digunakan
#include <SD.h>
#define CS_PIN  15 //pin CS

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
    File dataFile = SD.open("LOG.txt", FILE_WRITE); //membuka file .txt
    if (dataFile) {
      dataFile.println(data); //menyimpan data ke dalam file
      dataFile.close(); //menutup file
    }
    else {
    Serial.println("Gagal membuka file LOG.txt");
    }
  }
}
