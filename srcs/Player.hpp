#ifndef PERSO_HPP
# define PERSO_HPP

#include "Entite.hpp"
#include "Arme.hpp"
#include <list>

class Arme;

class Player : public Entite
{
private:
public:
    Arme _pistolet;
    
    static Texture2D _texture;
    Player();
    Player(float x, float y) ;
    ~Player();

    void	move_x(float dx);
    void	move_y(float dy);
    void	move(Vector const &v);
    void	getHurt(int damage);
    void	update();
    void	render();
};



#endif