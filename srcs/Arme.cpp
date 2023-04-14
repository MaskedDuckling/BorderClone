#include "Player.hpp"
#include <iostream>

Arme::Arme(Player & ref): _player(ref){
    _interval = 0.1;
}

void Arme::shoot(){
    if (GetTime() < _lastshot + _interval)
        return;
    _lastshot = GetTime();
    Vector target(GetMouseX(),GetMouseY());
    Vector dir = target - _player._position;
    std::cout << "SHOOT!" << _proj.size() << " " << target << " " << _player._position << " " << dir << std::endl;
    dir = dir.normed();
    _proj.push_back(projectile(10, _player._position, dir));
    if (_proj.size() > 20){
        _proj.pop_front();
    }
}

void Arme::update()
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        shoot();
    for (projectile &cur : _proj)
        cur._position += cur._vitesse * 5;
}

void Arme::render()
{
    for (projectile &cur : _proj) {
        DrawCircle(cur._position.x, cur._position.y, 5, RED);
        // if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        //     std::cout << cur._position << " "<<cur._vitesse << std::endl;
    }

}
