#ifndef GAME_HPP
# define GAME_HPP

#include <list>
#include "Perso.hpp"

#define WIDTH 960
#define HEIGHT 540

class Game
{
private:
    int screenWidth;
    int screenHeight;

    Perso player;
    std::List<Mob>    ennemies;

public:
    Game();
    ~Game();

    int	menu();
    void render();
};

#endif