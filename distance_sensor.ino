int trigPin = 12;               
  int echoPin = 11;                          // Mesafe sensörü bağlantıları
    long duration, cm, inches;               // Cmm-İnc belirlemek
       int tolerans = 4;
void setup() {

    Serial.begin (9600);
      
       pinMode(trigPin, OUTPUT);
         pinMode(echoPin, INPUT);
             pinMode(8, OUTPUT);
}
 
void loop() {

     digitalWrite(trigPin, LOW);
         delayMicroseconds(5);               // Mesafe sensörü temel ayarları
            digitalWrite(trigPin, HIGH);
              delayMicroseconds(10);
                  digitalWrite(trigPin, LOW);
 

    pinMode(echoPin, INPUT);         
       duration = pulseIn(echoPin, HIGH);
 
             cm = (duration/2) / 29.1;     

 
    if(cm + tolerans >= 25 & cm - tolerans<= 30) 
    { 
      digitalWrite(8 , HIGH);
      }    // 25 ile 30cm arası ledi yakması için komut
    
            else  {digitalWrite(8, LOW); }

  delay(500); // Gecikme hızı
}
