#include "vector.h"

Vect<int16_t> v1 = Vect(1023, 665, 2637);
Vect<int16_t> v2 = Vect(10, -50, 100);

Vect<float> v3;
Vect<float> v4;

void setup(){
	Serial.begin(115200);

	v3.set(10, 10, 10);
	v4.set(1, 2, 3);
}

void loop(){
//	v1.add(v2);
//	Serial.printf("x%i\ty%i\tz%i\n", v1.x(), v1.y(), v1.z());

	v3.add(v4);
	Serial.print(v3.x());
	Serial.print('\t');
	Serial.print(v3.y());
	Serial.print('\t');
	Serial.print(v3.z());
	Serial.println(v3.dist(v4));

	delay(250);	
}