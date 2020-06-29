//@gabzxth code v0.1
#include "RTClib.h"
#include <LiquidCrystal.h>
//initializing stuff before setup
LiquidCrystal lcd(8,9,4,5,6,7);
RTC_DS1307 rtc;
char username = 'gabz';
int IN1 = 13;
void setup() {
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    pinMode(IN1, OUTPUT);
    digitalWrite(IN1, HIGH);
  Serial.begin(9600);
  //setup lcd
  lcd.begin(16, 2); 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
  //setup RTC
  if (! rtc.begin()) // se o RTC não foi inicializado
{
  Serial.println("RTC nao pode ser encontrado!"); // imprime mensagem
  lcd.clear();
  lcd.setCursor(0, 0);
lcd.print("RTC 404"); // imprime mensagem

}
if (! rtc.isrunning()) // se o RTC não estiver rodando
{
Serial.println("RTC nao esta funcionando!"); // imprime mensagem
rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); // ajusta relógio com o relógio do seu PC
}
  greet();
}

void loop() {
  // put your main code here, to run repeatedly:
  updateTime();
  DateTime now = rtc.now();
  int hora = now.hour();
  int minuto = now.minute();
  if((hora == 14)&&(minuto == 49)){
    makeCoffee();
    
 
  }
}
void makeCoffee(){
    lcd.setCursor(0, 1);
    lcd.print("Running"); 
    digitalWrite(IN1, LOW);
    delay(120000);
    digitalWrite(IN1, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Done!");
  }
void greet(){
  lcd.setCursor(0, 0);
  lcd.print("Hello, Gabz");
  }
void updateTime(){ //this function keeps time on lcd display
DateTime now = rtc.now(); // faz a leitura dos dados do RTC
lcd.setCursor(11, 0);
lcd.print(now.hour(), DEC); // imprime horas
lcd.print(':');
lcd.print(now.minute(), DEC); // imprime minutos
delay(2000); // atraso de 2 segundos

}
