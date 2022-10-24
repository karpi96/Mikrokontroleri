//Kad pritisnes taster, treba da izgenerises neki broj od 1 do 6, kao da si bacio kocku.
//Rezultat treba da ispises na LCD displeju
//Jedan klik je jedan izgenerisan broj, znaci da taster treba da radi kao switch.


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

bool pusten = true; //taster je pusten na pocetku
bool buttonStatus;
bool buttonPin = 2;

int lcd_length = 16; // sirina je 16 karaktera
int lcd_rows = 2; //ima dva reda
LiquidCrystal_I2C lcd(0x27,lcd_length,lcd_rows);   //napravimo lcd objekat, koji ima adresu 0x27, i rezoluciju 16x2


void setup()
{
    pinMode(buttonPin,OUTPUT);

    lcd.init();  //inicijalizacija displeja                    
    lcd.backlight(); //ukljuci osvetljenje na lcdu

}

void loop(){
    buttonStatus = digitalRead(buttonPin); //citamo taster
    //ako je taster bio pusten i ako je sad pritisnut, onda izgenerisi broj i ispisi
    if(buttonStatus == HIGH && pusten == true){
        int broj = random(1,7);
        lcd.clear();
        lcd.print(broj);
        pusten = false; //sad kako smo pritisnuli taster vise nije pusten nego pritisnut
        delay(200); //treba delay zbog odskakanja
    }
    //ako pustimo taster onda treba da setujemo promenljivu pusten na true opet
    if(buttonStatus == LOW){
        pusten = true;
        delay(100);
    }
}