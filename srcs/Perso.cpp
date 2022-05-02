#include "Perso.hpp"

Perso::Perso() : _position(150, 150), _mSpeed(5), _Health(100)
{
    *_texture = LoadTexture("sprites/Character.png");
}

Perso::Perso(float x, float y, Texture2D *texture) :  _position(x, y)
{
    this->_texture = texture;
}

Perso::~Perso()
{
}

void	Perso::move_x(float dx)
{
	_position.x += dx;
}

void	Perso::move_y(float dy)
{
	_position.y += dy;
}

void	Perso::move(Vector const &v)
{
	_position += v;
}

void	Perso::getHurt(int damage)
{
	_Health -= damage;
}

void	Perso::render()
{
	DrawTextureV( *_texture, _position, BLACK);
}