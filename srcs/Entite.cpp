#include "Entite.hpp"

//Entite::_Image = LoadImage("sprites/ennemy.png");

Entite::Entite() : _position(150, 150), _mSpeed(5), _Health(100)
{
}

Entite::Entite(float x, float y, int mspeed, int Health, float radius)
:  _position(x, y), _mSpeed(mspeed), _Health(Health), radius(radius)
{
}

Entite::~Entite()
{
}

void	Entite::move_x(float dx)
{
	_position.x += dx;
}

void	Entite::move_y(float dy)
{
	_position.y += dy;
}

void	Entite::move(Vector const &v)
{
	_position += v;
}

void	Entite::getHurt(int damage)
{
	_Health -= damage;
}