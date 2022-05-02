#include "Vector.hpp"

Vector::Vector() : x(0), y(0)
{
}

Vector::Vector(float x, float y)
{
	x = x;
	y = y;
}

Vector::~Vector()
{
}

float	Vector::norm() const
{
	return std::sqrt(x*x + y*y);
}

Vector	Vector::normed() const
{
	return *this / norm();
}

Vector Vector::operator+(Vector const & rhs)const
{
	Vector ret(rhs.x + this->x, rhs.y + this->y);
	return (ret);
}

Vector Vector::operator-(Vector const & rhs)const
{
	Vector ret(rhs.x - this->x, rhs.y - this->y);
	return (ret);
}

Vector Vector::operator*(float rhs)const
{
	Vector ret(this->x * rhs, this->y * rhs);
	return (ret);
}

Vector Vector::operator/(float rhs)const
{
	Vector ret(this->x / rhs, this->y / rhs);
	return (ret);
}

 Vector & Vector::operator+=(Vector const & rhs)
 {
	this->x += rhs.x;
	this->y += rhs.y;
	return (*this);
 }

Vector & Vector::operator-=(Vector const & rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	return (*this);
}

Vector operator*(float f, Vector const & rhs)
{
	Vector ret(rhs.x * f, rhs.y * f);
	return (ret);
}

Vector::operator Vector2() const	{
    return (Vector2){x, y}; 
}