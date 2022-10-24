//Imate dva tastera kad pritisnete prvi intenzitet svetlosti na ledu se pojacava
//Kad pritisnete drugi onda se smanjuje
//Ne sme de sa povecava kad se drzi taster, samo jednom se menja kad se pritisne.


int led = 9;          
int brightness = 0;    
int fadeAmount = 5;    
bool rlsUp = true;
bool buttonStatusUp;
bool buttonPinUp = 2;
bool rlsDown = true;
bool buttonStatusDown;
bool buttonPinDown = 2;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
    //citamo tastere
    buttonStatusUp = digitalRead(buttonPinUp);
    buttonStatusDown = digitalRead(buttonPinDown);

    //ako je taster bio pusten i sad je pritisnut promeni intenzitet za neku kolicinu
    //u slucaju Up tastera povecaj u slucaju Down tastera smanji
    if(buttonStatusUp == HIGH && rlsUp == true){
        brightness = brightness + fadeAmount;
        rlsUp= false;
        delay(200);
    }

    if(buttonStatusDown == HIGH && rlsDown == true){
        brightness = brightness - fadeAmount;
        rlsDown = false;
        delay(200);
    }

    if(buttonStatusUp == LOW){
        rlsUp == true;
        delay(100);
    }

    if(buttonStatusDown == LOW){
        rlsDown = true;
        delay(100);
    }

    //limitiramo vrednosti na 0 i 255, ne pustamo da izadje iz granice 0-255
    if(brightness < 0) brightness == 0;
    if(brightness > 255) brightness == 255;

    analogWrite(led, brightness); //upisemo intenzitet na led
}