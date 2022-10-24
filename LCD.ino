//Treba text na LCD displeju da ide sa leve na desnu stranu pa da se odbije sa strane i vrati se nazad

#include <Wire.h> 
#include <LiquidCrystal_I2C.h> //biblioteka za LCD


int lcd_length = 16; //broj karaktera koji moze da stane u jednom redu
int lcd_rows = 2; //broj reda
LiquidCrystal_I2C lcd(0x27,lcd_length,lcd_rows);  //napravimo lcd objekat, koji se nalazi na adresu 0x27, sa duzinom karaktera od 16, i sa dva reda.
String text = "hello"; // text koji ce da se ispise
int position = 0; //trenutna pozicija teksta
int change = 1; //korak po kom se pozicija menja
void setup()
{
  lcd.init();    //inicializacija lcd-a                  
  lcd.backlight(); //ukljuci pozadinsko osvetljenje

}


void loop()
{   
    lcd.clear(); //obrisi sve sto je na LCDu
    lcd.setCursor(position, 0); //stavi pocetak teksta na odredjenju poziciju
    lcd.print(text); //ispisi tekst
    position += change; //promeni poziciju 
    //ako je text stigao do kraja ili do pocetka onda menjaj stranu na koju ce da nastavi putanju
    if(position == (lcd_length - text.length()) || position = 0)
        change = -change;
}