
#include <Servo.h>

int Ultra_Der;

int Ultra_Izq;

//sensor de ultrasonido
long u_tiempo(int trigger_pin, int echo_pin) {
    digitalWrite(trigger_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin, LOW);
    long microseconds = pulseIn(echo_pin ,HIGH);
    return microseconds;
}

long u_distancia(int trigger_pin, int echo_pin) {
    long microseconds = u_tiempo(trigger_pin, echo_pin);
    long u_distancia;
    u_distancia = microseconds/29/2;
    if (u_distancia == 0){
        u_distancia = 999;
    }
    return u_distancia;
}

Servo servo_12;

void setup()
{
  Ultra_Der=0;

  Ultra_Izq=0;


  pinMode( 6 , INPUT );

  pinMode( 7 , OUTPUT );

  pinMode( 9 , INPUT );

  pinMode( 8 , OUTPUT );

  servo_12.attach(12);
}


void loop()
{


        Ultra_Der = u_distancia(7,6);
    Ultra_Izq = u_distancia(8,9);
    if ((Ultra_Der <= 80) && (Ultra_Izq <= 80)) {
      servo_12.write(70);

    }
    if ((Ultra_Der >= 80) && (Ultra_Izq <= 80)) {
      servo_12.write(180);

    }
    if ((Ultra_Izq >= 80) && (Ultra_Der <= 80)) {
      servo_12.write(0);

    }


}
