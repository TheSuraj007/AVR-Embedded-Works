#define trigPin1 7
#define echoPin1 8

#define trigPin2 9
#define echoPin2 10

#define Buzzer 2

long duration_R,duration_L, distance_R,distance_L, RightSensor,BackSensor,FrontSensor,LeftSensor;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);

pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);


pinMode(Buzzer,OUTPUT);
}

void loop() {
SonarSensor_R(trigPin1, echoPin1);
RightSensor = distance_R;

SonarSensor_L(trigPin2, echoPin2);
LeftSensor = distance_L;


Serial.print(LeftSensor);
Serial.print(" - ");
Serial.println(RightSensor);
delay(50);
buzzerCall(LeftSensor,RightSensor);
delay(200);
}

void SonarSensor_R(int trigPin_R,int echoPin_R)
{
digitalWrite(trigPin_R, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_R, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_R, LOW);
duration_R = pulseIn(echoPin_R, HIGH);
distance_R = (duration_R/2) / 29.1;
}

void SonarSensor_L(int trigPin_L,int echoPin_L)
{
digitalWrite(trigPin_L, LOW);
delayMicroseconds(2);
digitalWrite(trigPin_L, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin_L, LOW);
duration_L = pulseIn(echoPin_L, HIGH);

// Determine distance from duration
// Use 343 metres per second as speed of sound
distance_L = (duration_L/2)* 0.0343;
}

void buzzerCall(int dist_R, int dist_L)
{
  if((dist_R < dist_L) & (dist_R <1000))
  {
    digitalWrite(Buzzer, HIGH); 
    delay(dist_R*5);
    digitalWrite(Buzzer, LOW);
    }
    
  else if((dist_R > dist_L) & (dist_L <1000))
  {
    digitalWrite(Buzzer, HIGH); 
    delay(dist_L*5);
    digitalWrite(Buzzer, LOW);
    }
    
}
