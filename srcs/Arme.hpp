#ifndef ARME_HPP
#define ARME_HPP

#include <list>
#include "Vector.hpp"

class Player;

struct projectile{
    int     _degats;
    Vector  _position;
    Vector  _vitesse;

    projectile(int degats, Vector position, Vector vitesse)
    : _degats(degats), _position(position), _vitesse(vitesse)
    {}

};

class Arme{
    public:
        double    _interval;
        double  _lastshot;
        std::list<projectile> _proj;
        Player &_player;

        Arme(Player & ref);
        void shoot();
        void update();
        void render();

};

#endif