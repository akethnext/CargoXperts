// Η βιβλιοθήκη για το ESP8266
#include "WiFiEsp.h"
// Δημιουργία ενός αντικειμένου Ethernet client
WiFiEspClient client;
#include <Servo.h>

Servo myservo;  
Servo myservo2; 
#define echoPin1 12 
#define trigPin1 11 
#define echoPin2 10 
#define trigPin2 9 
#define echoPin3 21 
#define trigPin3 40 
#define echoPin4 39 
#define trigPin4 38
#define echoPin5 36 
#define trigPin5 35
#define echoPin6 25 
#define trigPin6 24
#define echoPin7 27 
#define trigPin7 26

unsigned long currentTime;
unsigned long previousTime = 0;
unsigned long motorTime1 = 0;
unsigned long motorTime2 = 0;
long duration1; 
int distance1; 
long duration2; 
int distance2; 
long duration3; 
int distance3; 
long duration4; 
int distance4; 
long duration5; 
int distance5; 
long duration6; 
int distance6; 
long duration7; 
int distance7; 

int pos = 0;    
int movement=90;
int movement2=150;
float d1=0.8;
float d2=0.7;
float d3=0.6;
float d4=0.5;
float d5=0.4;
float d6=0.4;
float d7=0.65;
float d8=0.9;
// Κωδικοί WiFi
char ssid[] = "Redmi George";     // WiFi SSID (name)
char pass[] = "12345678";        // WiFi password
int status = WL_IDLE_STATUS;     // the WiFi radio's status

// IP του thingspeak.com
char server[] = "184.106.153.149";
// Write API Key του λογαριασμού στο thingspeak
char writeKey[] = "HH8A9G9GTA0QARZZ";

void setup()
{
  // αρχικοποίηση σειριακή θύρας για σύνδεση με ESP module
  Serial.begin(115200);
 // Serial.begin(9600);
  Serial.println("hi!!!");
  // initialize ESP module
  WiFi.init(&Serial);
  delay(5000);

  // check for the presence of the ESP
  if( WiFi.status() == WL_NO_SHIELD )
  {
 
    // stop
    while(true);
  }

  // attempt to connect to WiFi network
  while( status != WL_CONNECTED )
  {

    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
  }                                                    
//  delay(2000);
  pinMode(trigPin1, OUTPUT); 
  pinMode(echoPin1, INPUT); 
  pinMode(trigPin2, OUTPUT); 
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT); 
  pinMode(echoPin3, INPUT); 
  pinMode(trigPin4, OUTPUT); 
  pinMode(echoPin4, INPUT);
  pinMode(trigPin5, OUTPUT); 
  pinMode(echoPin5, INPUT); 
  pinMode(trigPin6, OUTPUT); 
  pinMode(echoPin6, INPUT); 
  pinMode(trigPin7, OUTPUT); 
  pinMode(echoPin7, INPUT);  
   
  myservo.attach(8);  
  myservo.write(pos);
  myservo2.attach(37);  
  myservo2.write(pos);
}


void loop()
{

  currentTime = millis();
 //kados1
  //Arxikopoihsh panw aisthithra
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2; 

  //Arxikopoihsh mesaiou aisthithra
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2 * 0.034 / 2; 

  //kados2
  //Arxikopoihsh panw aisthithra
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = duration3 * 0.034 / 2; 
  
  //Arxikopoihsh mesaiou aisthithra
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  distance4 = duration4 * 0.034 / 2; 
  
  //kados3 - Arxikopoihsh  aisthithra
  digitalWrite(trigPin5, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin5, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin5, LOW);
  duration5 = pulseIn(echoPin5, HIGH);
  distance5 = duration5 * 0.034 / 2; 

  //kados4 - Arxikopoihsh  aisthithra
  digitalWrite(trigPin6, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin6, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin6, LOW);
  duration6 = pulseIn(echoPin6, HIGH);
  distance6 = duration6 * 0.034 / 2; 

  //kados5 - Arxikopoihsh  aisthithra
  digitalWrite(trigPin7, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin7, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin7, LOW);
  duration7 = pulseIn(echoPin7, HIGH);
  distance7 = duration7 * 0.034 / 2; 
  /*
  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.println(" cm");
  

  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  Serial.print("Distance3: ");
  Serial.print(distance3);
  Serial.println(" cm");

  Serial.print("Distance4: ");
  Serial.print(distance4);
  Serial.println(" cm");
  
  Serial.print("Distance5: ");
  Serial.print(distance5);
  Serial.println(" cm");
  
  Serial.print("Distance6: ");
  Serial.print(distance6);
  Serial.println(" cm");
  
  Serial.print("Distance7: ");
  Serial.print(distance7);*/
 //ANOIGMA KAPAKI
  if (distance2>15)
  {     
         if ( currentTime - motorTime1 >= 3000 )
        myservo.write(pos);
  } 
  else
  {
    myservo.write(movement);
    motorTime1=currentTime;
  }
    //ANOIGA KAPAKI KADOS2
  if (distance4>15)
  {
    if ( currentTime - motorTime2 >= 3000 )
     myservo2.write(pos);
  }
  else
  {
    myservo2.write(movement);
    motorTime2=currentTime;
  }
  //delay (500); 

 
  // if there are incoming bytes available
  // from the server, read them and print them
  while( client.available() )
  {
    char c = client.read();
    Serial.write(c);
  }


  delay(200);

  // close any connection before send a new request
  // this will free the socket on the WiFi shield
  client.stop();
  
 
  if( currentTime - previousTime >= 16000 )
  {
      if( client.connect(server, 80) )
      {
    
         delay(2000);                     
        calcdatad1();
        calcdatad2();
        calcdatad3();
        calcdatad4();
        calcdatad5();
     //   Make an HTTP request
        String request= "GET /update?key=";
    
        request += writeKey; 
        request += "&field1=";    // field 1 for parking1erature
        request += String(d1);
        request += "&field2=";    // field 2 for parking2idity
        request += String(d2);
        request += "&field3=";    // field 2 for parking2idity
        request += String(d3);
      
            request += "&field4=";    // field 2 for parking2idity
        request += String(d4);
            request += "&field5=";    // field 2 for parking2idity
        request += String(d5);
            request += "&field6=";    // field 2 for parking2idity
        request += String(d6);
            request += "&field7=";    // field 2 for parking2idity
        request += String(d7);
            request += "&field8=";    // field 2 for parking2idity
        request += String(d8);
          request += String("\r\n");
         // Serial.println(request); 
        client.println(request);
        //client.println("Host: 184.106.153.149");
        client.println("Connection: close");
        client.println();
        previousTime = currentTime;
        delay(1000);//5000);
      }
      //else
      //{
       // delay(5000);
     // }   
     
  }
/*
  Serial.print("D1: ");
  Serial.println(d1);
    Serial.print("D2: ");
  Serial.println(d2);
    Serial.print("D3: ");
  Serial.println(d3);
    Serial.print("D4: ");
  Serial.println(d4);
    Serial.print("D5: ");
  Serial.println(d5);
  */

     
}

void calcdatad1()
{
   if (distance1<3)
     d1=1.0;
   else if (distance1<4)
     d1=0.8;
   else if (distance1<5)
     d1=0.6;
   else if (distance1<6)
     d1=0.4;
   else if (distance1<7)
     d1=0.2;
   else
     d1=0.0;       
}
void calcdatad2()
{
   if (distance3<3)
     d2=1.0;
   else if (distance3<4)
     d2=0.8;
   else if (distance3<5)
     d2=0.6;
   else if (distance3<6)
     d2=0.4;
   else if (distance3<7)
     d2=0.2;
   else
     d2=0.0;       
}
void calcdatad3()
{
   if (distance5<3)
     d3=1.0;
   else if (distance5<4)
     d3=0.8;
   else if (distance5<5)
     d3=0.6;
   else if (distance5<6)
     d3=0.4;
   else if (distance5<7)
     d3=0.2;
   else
     d3=0.0;       
}
void calcdatad4()
{
   if (distance6<3)
     d4=1.0;
   else if (distance6<4)
     d4=0.8;
   else if (distance6<5)
     d4=0.6;
   else if (distance6<6)
     d4=0.4;
   else if (distance6<7)
     d4=0.2;
   else
     d4=0.0;       
}
void calcdatad5()
{
   if (distance7<3)
     d5=1.0;
   else if (distance7<4)
     d5=0.8;
   else if (distance7<5)
     d5=0.6;
   else if (distance7<6)
     d5=0.4;
   else if (distance7<7)
     d5=0.2;
   else
     d5=0.0;       
}
