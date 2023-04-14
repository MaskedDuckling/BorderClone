#include "Player.hpp"

// Player::Player() : _pistolet(*this)
// {
	
// }

Player::Player(float x, float y) : Entite(x,y,5,100, 32), _pistolet(*this) {
	std::cout << x << y << "\n";
}

Player::~Player()
{
	UnloadTexture(_texture);
}

void	Player::move_x(float dx)
{
	_position.x += dx;
}

void	Player::move_y(float dy)
{
	_position.y += dy;
}

void	Player::move(Vector const &v)
{
	_position += v;
}

void	Player::getHurt(int damage)
{
	_Health -= damage;
}

#define W 87
#define A 65
#define S 83
#define D 68

void Player::update()
{
	if (IsKeyDown(W))
		move_y(-_mSpeed);
	if (IsKeyDown(A))
		move_x(-_mSpeed);
	if (IsKeyDown(S))
		move_y(_mSpeed);
	if (IsKeyDown(D))
		move_x(_mSpeed);
	_pistolet.update();
}

void	Player::render()
{
	DrawTexture(_texture, _position.x-32.f, _position.y-32.f, WHITE);
	_pistolet.render();  
}