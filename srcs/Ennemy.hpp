#ifndef ENNEMY_HPP
# define ENNEMY_HPP

#include "Entite.hpp"
#include "Player.hpp"

class Ennemy : public Entite{
public:
    static Texture2D _texture;

    Ennemy(float x, float y);
    ~Ennemy();

    void	update(Player & player);
    void	render();
};

#endif