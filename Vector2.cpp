#include"Vector2.hpp" 
#include <iostream>

Vector2::Vector2(){
	setval(0,0);
};
Vector2::Vector2(int _n1, int _n2){
	setval(_n1, _n2);
}
Vector2::Vector2(double _n1, double _n2){
	setval(_n1, _n2);
}
void Vector2::setval(double _n1, double _n2){
	x = _n1;
	y = _n2;
}
Vector2 Vector2::add(Vector2 second){
	Vector2 sum;
	sum.x = x + second.x; 
	sum.y = y + second.y; 
	return sum;
}
Vector2 Vector2::mult(Vector2 second){
	Vector2 prod;
	prod.x = x * second.x; 
	prod.y = y * second.y; 
	return prod; 
}

void Vector2::Normalize(){
	double _lenght = sqrt(pow(x,2) + pow(y,2)); 
	if(_lenght == 0){return;}
	x = x / _lenght;
	y = y / _lenght;
}
