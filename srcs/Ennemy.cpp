#include "Ennemy.hpp"

Ennemy::Ennemy(float x, float y) : Entite(x,y,2,30, 8){}

Ennemy::~Ennemy(){
}

void Ennemy::update(Player & player)
{
    Vector dir = player._position - _position;
    dir = dir.normed();
    move(dir * _mSpeed);
    std::list<std::list<projectile>::iterator> toremove;
    auto it = player._pistolet._proj.begin();
    for (projectile &cur : player._pistolet._proj) {
        if (CheckCollisionCircles(_position, radius, cur._position, 5)) {
            getHurt(cur._degats);
            toremove.push_back(it);
        }
        it++;
    }

    for (auto &ite : toremove)
        player._pistolet._proj.erase(ite);
        
}

void Ennemy::render(){
    DrawTexture(_texture, _position.x-8.f, _position.y-8.f, WHITE);
}