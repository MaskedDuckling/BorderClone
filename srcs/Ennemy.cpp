#include "Ennemy.hpp"

Ennemy::Ennemy(float x, float y) : Entite(x,y,1,10, 8), degats(10){
    stuned = 0;
}

Ennemy::~Ennemy(){
}

void Ennemy::checkcollision(std::list<projectile> & ref){
    std::list<std::list<projectile>::iterator> toremove;
    auto it = ref.begin();
    for (projectile &cur : ref) {
        if (CheckCollisionCircles(_position, radius, cur._position, 5)) {
            getHurt(cur._degats);
            toremove.push_back(it);
        }
        it++;
    }

    for (auto &ite : toremove)
        ref.erase(ite);
}

int Ennemy::update(Player & player)
{
    Vector dir = player._position - _position;
    dir = dir.normed();
    if (GetTime() - stuned >= 1)
        move(dir * _mSpeed);
    checkcollision(player._pistolet._proj);
    checkcollision(player._fusilapompe._proj);

    if (CheckCollisionCircles(_position, radius, player._position, player.radius)){
        player.getHurt(degats);
        return (1);
    }
    return (0);
}

void Ennemy::render(){
    DrawTexture(_texture, _position.x-8.f, _position.y-8.f, WHITE);
}