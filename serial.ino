//Treba da saljemo dva stringa preko serijskog monitora
//Ako posaljemo ON, onda se ukljuci dioda
//Ako posaljemo OFF, onda se dioda iskljuci

const int led = 2;
String text = "";

void setup(){
    Serial.begin(9600);
    pinMode(led,INPUT);
}

void loop(){
    while(Serial.available() > 0){ //ako imamo nesto na raspolaganju da citamo iz serijskog porta 
        text = Serial.readString(); //procitaj String
        text.trim(); //obrisemo sva nepotrebna prazna mesta na pocetku i kraju stringa
    }

    if(text == "ON"){ // ako smo poslali ON ukljuci led
        digitalWrite(led,HIGH);
    }
    if(text == "OFF"){// ako smo poslali OFF iskljuci led
        digitalWrite(led,HIGH);
    }

    delay(30);
}