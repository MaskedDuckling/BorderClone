#include <raylib.h>
#include "Vector.hpp"

class Perso
{
private:
    Vector _Position;
    int _mSpeed;
    int _Health;

public:
    Perso();
    ~Perso();
    void    move_x(float dx);
    void    move_y(float dy);
    void    move(Vector const &v);

	
	void	getHurt(int damage);

};

Perso::Perso() : _Position(150, 150), _mSpeed(5), _Health(100)
{
}

Perso::~Perso()
{
}

void	Perso::move_x(float dx)
{
	_Position.x += dx;
}

void	Perso::move_y(float dy)
{
	_Position.y += dy;
}

void	Perso::move(Vector const &v)
{
	_Position += v;
}

void	Perso::getHurt(int damage)
{
	_Health -= damage;
}