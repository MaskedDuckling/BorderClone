#ifndef ENTITE_HPP
# define ENTITE_HPP

#include <raylib.h>
#include "Vector.hpp"

class Entite
{
public:
	Vector		_position;
	int			_mSpeed;
	int			_Health;
	float 		radius;

	Entite();
    Entite(float x, float y, int mspeed, int Health, float radius);
	~Entite();
	void    move_x(float dx);
	void    move_y(float dy);
	void    move(Vector const &v);

	
	void	getHurt(int damage);
	void	render();
    void    shoot()const;

};

#endif