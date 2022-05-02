class Vector
{
private:
    float _x;
    float _y;
public:
    Vector();
    Vector::Vector(float x, float y);
    ~Vector();

    Vector operator+(Vector const & rhs)const;
    Vector operator-(Vector const & rhs)const;
    Vector operator*(float rhs)const;
    Vector & operator+=(Vector const & rhs);
    Vector & operator-=(Vector const & rhs);
};

Vector::Vector() : _x(0), _y(0)
{
}

Vector::Vector(float x, float y)
{
    _x = x;
    _y = y;
}

Vector::~Vector()
{
}

Vector operator+(Vector const & rhs)
{

}

Vector operator*(float f, Vector const & rhs);