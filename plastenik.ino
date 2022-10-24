
int crveniLed = 2;
int zeleniLed = 3;



void setup(){
    Serial.begin(9600);
    pinMode(crveniLed,INPUT);
    pinMode(zeleniLed,INPUT);
}

void loop(){
    int sensorValue = analogRead(A0); //citaj senzor(velicine od 0-1023)
    float voltage = sensorValue * (5.0 / 1023.0); //konvertovanje diskretne velicine u napon
    float tmp = 20*voltage - 10; //formula koju dobijemo sa slike zadatka za temperaturu
    Serial.println(tmp); //ispisem temperaturu na serijskom monitoru
    if(tmp >= 30) digitalWrite(zeleniLed, HIGH); //ako je temp veca od 30 ukljuci ventilator
    if(tmp <= 25) digitalWrite(zeleniLed, LOW); //ako se temp smanji na 25 iskljuci ventilator
    if(tmp <= 20) digitalWrite(crveniLed, HIGH); //ako je temp manja od 20 ukljuci grejanje
    if(tmp >= 25) digitalWrite(crveniLed, LOW); //ako je temp veca od 25 iskljuci grejanje

    delay(50);
}

 