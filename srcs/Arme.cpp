#include "Player.hpp"
#include <iostream>

Arme::Arme(Player & ref): _player(ref){
    _interval = 0.1;
    _lastshot = 0;
}

void Arme::shoot(){
    if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        return;
    if (GetTime() < _lastshot + _interval)
        return;
    _lastshot = GetTime();
    Vector target(GetMouseX(),GetMouseY());
    Vector dir = target - _player._position;
    std::cout << "SHOOT!" << _proj.size() << " " << target << " " << _player._position << " " << dir << std::endl;
    dir = dir.normed();
    _proj.push_back(projectile(10, _player._position, dir));
    if (_proj.size() > 40){
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
void Shotgun::update(){
    if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        shoot();
    for (projectile &cur : _proj)
        cur._position += cur._vitesse * 5;
}
Shotgun::Shotgun(Player &ref) : Arme(ref)
{
    _interval = 1;
}

void Shotgun::shoot()
{
    if (!IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        return;
    if (GetTime() < _lastshot + _interval)
        return;
    _lastshot = GetTime();
    Vector target(GetMouseX(),GetMouseY());
    Vector dir = target - _player._position;
    std::cout << "SHOOT!" << _proj.size() << " " << target << " " << _player._position << " " << dir << std::endl;
    dir = dir.normed();
    Vector tang(-dir.y, dir.x);
    for (int i = 0; i < 7; i++)
    {
        _proj.push_back(projectile(10, _player._position, dir + tang / 7 * (i - 3)));
    }
    while (_proj.size() > 40){
        _proj.pop_front();
    }
}