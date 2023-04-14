#ifndef ENNEMY_HPP
# define ENNEMY_HPP

#include "Entite.hpp"
#include "Player.hpp"

class Ennemy : public Entite{
public:
    static Texture2D _texture;
    int             degats;
    float           stuned;

    Ennemy(float x, float y);
    ~Ennemy();

    void checkcollision(std::list<projectile> & ref);
    int	update(Player & player);
    void	render();
};

#endif