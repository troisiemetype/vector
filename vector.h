#ifndef VECTOR_H
#define VECTOR_H

#include <Arduino.h>

template <class T>
class Vect{
public:

	Vect(){;}
	Vect(T x, T y, T z = 0);

	void set(T x, T y, T z = 0);

	Vect add(Vect);
	Vect add(T x, T y, T z = 0);

	Vect sub(Vect);
	Vect sub(T x, T y, T z = 0);

	Vect mult(T);

	Vect div(T);

	T mag();

	T dist(Vect);
	T dist(T x, T y, T z = 0);

	T dot(Vect);
	T dot(T x, T y, T z = 0);

	Vect cross(Vect);
	Vect cross(T x, T y, T z = 0);

	// Could be nice to implement rotation along an arbitrary axis.
	Vect rotateX(float);
	Vect rotateY(float);
	Vect rotateZ(float);

	T x();
	T y();
	T z();

	Vect x(T);
	Vect y(T);
	Vect z(T);

protected:

	T _x, _y, _z;

};


template <class T>
Vect<T>::Vect(T x, T y, T z){
	set(x, y, z);
}

template <class T>
void Vect<T>::set(T x, T y, T z){
	_x = x;
	_y = y;
	_z = z;
}

template <class T>
Vect<T> Vect<T>::add(Vect v){
	return add(v._x, v._y, v._z);
}

template <class T>
Vect<T> Vect<T>::add(T x, T y, T z){
	_x += x;
	_y += y;
	_z += z;

	return *this;
}

template <class T>
Vect<T> Vect<T>::sub(Vect v){
	return sub(v._x, v._y, v._z);
}

template <class T>
Vect<T> Vect<T>::sub(T x, T y, T z){
	_x -= x;
	_y -= y;
	_z -= z;

	return *this;
}

template <class T>
Vect<T> Vect<T>::mult(T val){
	_x *= val;
	_y *= val;
	_z *= val;

	return *this;
}

template <class T>
Vect<T> Vect<T>::div(T val){
	_x /= val;
	_y /= val;
	_z /= val;

	return *this;
}

template <class T>
T Vect<T>::mag(){
	return sqrt(_x * _x + _y * _y + _z *_z);
}

template <class T>
T Vect<T>::dist(Vect v){
	return dist(v._x, v._y, v._z);
}

template <class T>
T Vect<T>::dist(T x, T y, T z){
	Vect v = Vect(x, y, z);
	v.sub(_x, _y, _z);
	return v.mag();
}

template <class T>
T Vect<T>::dot(Vect v){
	return dot(v._x, v._y, v._z);
}

template <class T>
T Vect<T>::dot(T x, T y, T z){
	return _x * x + _y * y + _z * z;
}

template <class T>
Vect<T> Vect<T>::cross(Vect v){
	return cross(v._x, v._y, v._z);
}

template <class T>
Vect<T> Vect<T>::cross(T x, T y, T z){
	return Vect(y * _z - z * _y, z * _x - x * _z, x * _y - y * _x);
}

template <class T>
Vect<T> Vect<T>::rotateX(float angle){
	T y = _y * cos(angle) - _z * sin(angle);
	T z = _y * sin(angle) + _z * cos(angle);
	_y = y;
	_z = z;
	return *this;
}

template <class T>
Vect<T> Vect<T>::rotateY(float angle){
	T z = _z * cos(angle) - _x * sin(angle);
	T x = _z * sin(angle) + _x * cos(angle);
	_x = x;
	_z = z;
	return *this;
}

template <class T>
Vect<T> Vect<T>::rotateZ(float angle){
	T x = _x * cos(angle) - _y * sin(angle);
	T y = _x * sin(angle) + _y * cos(angle);
	_x = x;
	_y = y;
	return *this;
}

template <class T>
T Vect<T>::x(){
	return _x;
}

template <class T>
T Vect<T>::y(){
	return _y;
}

template <class T>
T Vect<T>::z(){
	return _z;
}

template <class T>
Vect<T> Vect<T>::x(T x){
	_x = x;
	return *this;
}

template <class T>
Vect<T> Vect<T>::y(T y){
	_y = y;
	return *this;
}

template <class T>
Vect<T> Vect<T>::z(T z){
	_z = z;
	return *this;
}



#endif