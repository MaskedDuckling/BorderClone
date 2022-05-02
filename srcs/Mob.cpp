#include "Mob.hpp"

//Mob::_texture = LoadTexture("sprites/ennemy.png");

Mob::Mob() : _position(150, 150), _mSpeed(5), _Health(100)
{
}

Mob::Mob(float x, float y, Texture2D *texture) :  _position(x, y)
{
}

Mob::~Mob()
{
}

void	Mob::move_x(float dx)
{
	_position.x += dx;
}

void	Mob::move_y(float dy)
{
	_position.y += dy;
}

void	Mob::move(Vector const &v)
{
	_position += v;
}

void	Mob::getHurt(int damage)
{
	_Health -= damage;
}

void	Mob::render()
{
	DrawTextureV( *_texture, _position, BLACK);
}