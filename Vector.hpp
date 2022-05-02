class Vector
{
public:
	float x;
	float y;

	Vector();
	Vector::Vector(float x, float y);
	~Vector();

	Vector operator+(Vector const & rhs)const;
	Vector operator-(Vector const & rhs)const;
	Vector operator*(float rhs)const;
	Vector operator/(float rhs)const;
	Vector & operator+=(Vector const & rhs);
	Vector & operator-=(Vector const & rhs);
};

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