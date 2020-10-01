const int trigPin_l = 9;
const int echoPin_l= 10;
const int trigPin_f = 7;
const int echoPin_f= 8;
const int trigPin_r= 3;
const int echoPin_r= 4;
const int relay_l=5;
const int relay_r=6;

// defines variables

long duration_l,duration_r,duration_f;
int distance_l,distance_r,distance_f;
void setup() {
pinMode(trigPin_l, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin_l, INPUT); // Sets the echoPin as an Input
pinMode(trigPin_r, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin_r, INPUT); // Sets the echoPin as an Input
pinMode(trigPin_f, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin_f, INPUT); // Sets the echoPin as an Input
pinMode(relay_l, OUTPUT);
pinMode(relay_r, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
void loop() {

digitalWrite(trigPin_l, LOW);
delayMicroseconds(2);

digitalWrite(trigPin_l, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_l, LOW);

duration_l = pulseIn(echoPin_l, HIGH);

distance_l= duration_l*0.034/2;

Serial.print("Distance_l: ");
Serial.print(distance_l);


// ultrasonic right


digitalWrite(trigPin_r, LOW);
delayMicroseconds(2);

digitalWrite(trigPin_r, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_r, LOW);

duration_r = pulseIn(echoPin_r, HIGH);

distance_r= duration_r*0.034/2;

Serial.print("Distance_r: ");
Serial.print(distance_r);


// ultrasonic front


digitalWrite(trigPin_f, LOW);
delayMicroseconds(2);

digitalWrite(trigPin_f, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_f, LOW);

duration_f = pulseIn(echoPin_f, HIGH);

distance_f= duration_f*0.034/2;

Serial.print("Distance_f: ");
Serial.println(distance_f);

if (distance_l<=5)
  {
    digitalWrite(relay_l, HIGH);
    delay(800);
   digitalWrite(relay_l, LOW);
  }
else
{
   digitalWrite(relay_l, LOW); 
 }  
if (distance_r<=5)
  {
    digitalWrite(relay_r, HIGH);
   delay(800);
   digitalWrite(relay_r, LOW);
  }
 else
 {
   digitalWrite(relay_r, LOW);
  }
}
