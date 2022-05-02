#ifndef MOB_HPP
# define MOB_HPP

#include <raylib.h>
#include "Vector.hpp"

class Mob
{
private:
	Vector _position;
	int _mSpeed;
	int _Health;
	Texture2D _texture;

public:
	Mob();
    Mob(float x, float y, Texture2D *texture);
	~Mob();
	void    move_x(float dx);
	void    move_y(float dy);
	void    move(Vector const &v);

	
	void	getHurt(int damage);
	void	render();
    void    shoot()const;

};

#endif