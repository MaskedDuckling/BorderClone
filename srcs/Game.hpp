#ifndef GAME_HPP
# define GAME_HPP

#include "Player.hpp"
#include "Ennemy.hpp"

#define WIDTH 960
#define HEIGHT 540

class Game
{
private:
    int screenWidth;
    int screenHeight;

    Player player;
    std::list<Ennemy>   ennemies;

public:
    Game();
    ~Game();

    int	menu();
    void loop();
};

void	ft_exit();
int	menu_mouse_click();

#endif