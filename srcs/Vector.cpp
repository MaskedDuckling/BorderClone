#include "Vector.hpp"

Vector::Vector() : x(0), y(0)
{
}

Vector::Vector(int x2, int y2){
	x=x2;
	y=y2;
}

Vector::Vector(float x2, float y2)
{
	x = x2;
	y = y2;
}

Vector::~Vector()
{
}

float Vector::distance(Vector & ref){
	return ((*this - ref).norm());
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
	Vector ret(this->x - rhs.x, this->y - rhs.y);
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


std::ostream &operator<<(std::ostream &out, Vector const & rhs)
{
	out << "x: " << rhs.x << " y: " << rhs.y;
	return out;
}