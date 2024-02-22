#include "vector.h"

Vect::Vect(int32_t x, int32_t y, int32_t z = 0){
	set(x, y, z);
}

void Vect::set(int32_t x, int32_t y, int32_t z = 0){
	_x = x;
	_y = y;
	_z = z;
}

Vect Vect::add(Vect v){
	return add(v._x, v._y, v._z);
}

Vect Vect::add(int32_t x, int32_t y, int32_t z = 0){
	_x += x;
	_y += y;
	_z += z;

	return *this;
}

Vect Vect::sub(Vect v){
	return sub(v._x, v._y, v._z);
}

Vect Vect::sub(int32_t x, int32_t y, int32_t z = 0){
	_x -= x;
	_y -= y;
	_z -= z;

	return *this;
}

Vect Vect::mult(int32_t val){
	_x *= val;
	_y *= val;
	_z *= val;

	return *this;
}

Vect Vect::div(int32_t val){
	_x /= val;
	_y /= val;
	_z /= val;

	return *this;
}

uint32_t Vect::mag(){
	return sqrt(_x * _x + _y * _y + _z *_z);
}

uint32_t Vect::dist(Vect v){
	return dist(v._x, v._y, v._z);
}

uint32_t Vect::dist(int32_t x, int32_t y, int32_t z = 0){
	Vect v = Vect(x, y, z);
	v.sub(_x, _y, _z);
	return v.mag();
}

int32_t Vect::dot(Vect v){
	return dot(v._x, v._y, v._z);
}

int32_t Vect::dot(int32_t x, int32_t y, int32_t z = 0){
	return _x * x + _y * y + _z * z;
}

Vect Vect::cross(Vect v){
	return cross(v._x, v._y, v._z);
}

Vect Vect::cross(int32_t x, int32_t y, int32_t z = 0){
	return Vect(y * _z - z * _y, z * _x - x * _z, x * _y - y * _x);
}

Vect Vect::rotateX(float angle){
	int32_t y = _y * cos(angle) - _z * sin(angle);
	int32_t z = _y * sin(angle) + _z * cos(angle);
	_y = y;
	_z = z;
	return *this;
}

Vect Vect::rotateY(float angle){
	int32_t z = _z * cos(angle) - _x * sin(angle);
	int32_t x = _z * sin(angle) + _x * cos(angle);
	_x = x;
	_z = z;
	return *this;
}

Vect Vect::rotateZ(float angle){
	int32_t x = _x * cos(angle) - _y * sin(angle);
	int32_t y = _x * sin(angle) + _y * cos(angle);
	_x = x;
	_y = y;
	return *this;
}

int32_t Vect::x(){
	return _x;
}

int32_t Vect::y(){
	return _y;
}

int32_t Vect::z(){
	return _z;
}

Vect Vect::x(int32_t x){
	_x = x;
	return *this;
}

Vect Vect::y(int32_t y){
	_y = y;
	return *this;
}

Vect Vect::z(int32_t z){
	_z = z;
	return *this;
}
