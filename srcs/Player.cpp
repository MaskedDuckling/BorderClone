#include "Player.hpp"
#include "Game.hpp"
#include <string>


// Player::Player() : _pistolet(*this)
// {
	
// }

Player::Player(float x, float y) : Entite(x,y,5,100, 32), _pistolet(*this), _fusilapompe(*this) {
    score = 0;
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
	_fusilapompe.update();
}

void	Player::render()
{
	DrawTexture(_texture, _position.x-32.f, _position.y-32.f, WHITE);
	_pistolet.render();
	_fusilapompe.render();
	DrawRectangle(_position.x - 32, _position.y + 40, 64, 10, BLACK);
	DrawRectangle(_position.x - 32, _position.y + 40, 64 * (float)_Health / 100, 10, RED);
	DrawText(std::to_string(score).c_str(), WIDTH/2, 10, 50, WHITE);
}