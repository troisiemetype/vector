#ifndef VECint32_tOR_H
#define VECint32_tOR_H

#include <Arduino.h>

class Vect{
public:

	Vect(){;}
	Vect(int32_t, int32_t, int32_t);

	void set(int32_t, int32_t, int32_t);

	Vect add(Vect);
	Vect add(int32_t, int32_t, int32_t);

	Vect sub(Vect);
	Vect sub(int32_t, int32_t, int32_t);

	Vect mult(int32_t);

	Vect div(int32_t);

	uint32_t mag();

	uint32_t dist(Vect);
	uint32_t dist(int32_t, int32_t, int32_t);

	int32_t dot(Vect);
	int32_t dot(int32_t, int32_t, int32_t);

	Vect cross(Vect);
	Vect cross(int32_t, int32_t, int32_t);

	Vect rotateX(float);
	Vect rotateY(float);
	Vect rotateZ(float);

	int32_t x();
	int32_t y();
	int32_t z();

	Vect x(int32_t);
	Vect y(int32_t);
	Vect z(int32_t);

protected:

	int32_t _x, _y, _z;

};

#endif