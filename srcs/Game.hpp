#ifndef GAME_HPP
# define GAME_HPP

#include "Player.hpp"
#include "Ennemy.hpp"
#include "Carte.hpp"
#include "TileMap.hpp"

#define WIDTH 965
#define HEIGHT 650

class Game
{
private:
    int screenWidth;
    int screenHeight;
    Texture2D background;

    Player player;
    std::list<Ennemy>   ennemies;
    Carte carte;

public:
    Game();
    ~Game();

    void repousse();
    int	menu();
    void loop();
};

void	ft_exit();
int	menu_mouse_click();

#endif