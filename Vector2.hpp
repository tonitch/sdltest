#ifndef Vector2_H
#define Vector2_H

#include <math.h>

class Vector2{
	public:	
		int x;
		int y;

		Vector2();
		Vector2(int _n1, int _n2);
		Vector2(double _n1, double _n2);
		void setval(double _n1, double _n2);
		Vector2 add(Vector2 second);
		Vector2 mult(Vector2 second);

		void Normalize();
};

#endif
