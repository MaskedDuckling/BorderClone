#ifndef PERSO_HPP
# define PERSO_HPP

#include "Mob.hpp"

class Perso : public Mob
{
private:
    Texture2D _texture = LoadTexture("sprites/Character.png");
public:
    Perso(/* args */);
    ~Perso();
};

Perso::Perso(/* args */)
{
}

Perso::~Perso()
{
}


#endif