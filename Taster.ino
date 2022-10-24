//rad osnovnog tastera

bool pusten = true; //taster je pusten na pocetku
bool buttonStatus;
bool buttonPin = 2;

void setup(){
    pinMode(buttonPin,OUTPUT);
}

void loop(){
    buttonStatus = digitalRead(buttonPin);//citamo taster
    //ako je taster bio pusten i ako je sad pritisnut, onda mozemo da radimo sta treba
    if(buttonStatus == HIGH && pusten == true){
        //radi to sto treba
        pusten = false;//sad kako smo pritisnuli taster vise nije pusten nego pritisnut
        delay(200); // treba delay zbog odskakanja
    }
    //ako pustimo taster onda treba da setujemo promenljivu pusten na true opet

    if(buttonStatus == LOW){
        pusten = true;
        delay(100);
    }
}