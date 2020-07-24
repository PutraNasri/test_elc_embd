
#include <Thread.h>

const int btn_1 = 2; //pin ADC arduino (pc2 pin #25 atmega)
const int btn_2 = 3; //pin ADC arduino (pc3 pin #26 atmega)
const int btn_3 = 4; //pin ADC arduino (pc4 pin #27 atmega)
const int btn_4 = 5; //pin ADC arduino (pc5 pin #28 atmega)

#define pwm_signal_motor 9 //pin digital pwm arduino (pb1 pin 15 atmega)

String Data_btn = "nan";

Thread Thread1 = Thread();
Thread Thread2 = Thread();
Thread Thread3 = Thread();


void setup() {
  
  Serial.begin(115200);
  
  pinMode(btn_1,INPUT);
  pinMode(btn_2,INPUT);
  pinMode(btn_3,INPUT);
  pinMode(btn_4,INPUT);

  pinMode(pwm_signal_motor,OUTPUT);

  Thread1.onRun(button_handle);
  Thread1.setInterval(500); //set interval masing2 thread (*)
  Thread2.onRun(motor_handle); 
  Thread2.setInterval(500); // *
  Thread3.onRun(serial_handle);
  Thread3.setInterval(500); // *

}

void loop() {
  
  if(Thread1.shouldRun())
    Thread1.run();
  if(Thread2.shouldRun())
    Thread2.run();
  if(Thread3.shouldRun())
    Thread3.run();
  int x = 0;
  x = 1 + 2;
  
}


void button_handle(){

  if(digitalRead(btn_1)==HIGH){
    Data_btn="btn_1_push";
  }
  else if(digitalRead(btn_2)==HIGH){
    Data_btn="btn_2_push";
  }
  else if(digitalRead(btn_3)==HIGH){
    Data_btn="btn_3_push";
  }
  else if(digitalRead(btn_4)==HIGH){
    Data_btn="btn_4_push";
  }
  
}

void motor_handle(){
  int val_motor = 1023 ; //berikan nilai speed (silahkan di sesuaikan)
  analogWrite(pwm_signal_motor, val_motor); //send data pwm for speed motor
}

void serial_handle(){
  
  if(Data_btn != "nan"){
    Serial.println(Data_btn); //send data to serial
    Data_btn="nan"; //reset data after send to serial
  }
 
}
