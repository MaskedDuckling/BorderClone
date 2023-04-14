#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <math.h>
#include <raylib.h>
#include <iostream>

class Vector
{
public:
	float x;
	float y;

	Vector();
	Vector(float x, float y);
	Vector(int x, int y);

	~Vector();

	float	norm() const;
	Vector	normed() const;

	Vector operator+(Vector const & rhs)const;
	Vector operator-(Vector const & rhs)const;
	Vector operator*(float rhs)const;
	Vector operator/(float rhs)const;
	Vector & operator+=(Vector const & rhs);
	Vector & operator-=(Vector const & rhs);

	operator Vector2() const;
};

std::ostream &operator<<(std::ostream &out, Vector const & rhs);

#endif 