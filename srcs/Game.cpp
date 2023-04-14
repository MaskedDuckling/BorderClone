#include "Game.hpp"
#include <iostream>
Texture2D Player::_texture;
Texture2D Ennemy::_texture;


Game::Game() : player(50.f, 50.f)
{   
    screenWidth = WIDTH;
    screenHeight = HEIGHT;
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
    SetTargetFPS(60);
    DrawRectangle(0, 0, WIDTH, HEIGHT, BLACK);
    Player::_texture = LoadTexture("sprites/Character.png");
    Ennemy::_texture = LoadTexture("sprites/ennemy.png");
}

Game::~Game()
{
	UnloadTexture(Player::_texture);
	UnloadTexture(Ennemy::_texture);
	CloseWindow();
}

int	Game::menu()
{
    Texture2D title = LoadTexture("sprites/Title.png");
    while (1)
    {
        BeginDrawing();
        DrawTexture(title, -50, -50, WHITE);
        DrawText("Dark Zombie", 0, 0, 50, GREEN);
        DrawText("Play",150, 150, 50, BLACK);
        DrawText("Exit",150, 300, 50, BLACK);
        EndDrawing();
        if(WindowShouldClose())
            ft_exit(); 
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && menu_mouse_click())
            return (1);
    }
    UnloadTexture(title);
    return (1);
}

void Game::loop()
{
    // int key;
    //     std::cout << key << "   ";
    // if ((key = GetKeyPressed()) != 0)
    while (player._Health != 0)
    {
        //update()
        while (ennemies.size() <= 10){
            int randominator = rand();
            randominator %= (2*HEIGHT);
            if (randominator < HEIGHT)
                ennemies.push_back(Ennemy(0,randominator));
            else
                ennemies.push_back(Ennemy(WIDTH,randominator-HEIGHT));

        }
        if(WindowShouldClose())
            ft_exit();
        player.update();
        for (Ennemy & cur: ennemies)
            cur.update(player);

        for (auto it = ennemies.begin(); it != ennemies.end(); it++)
            if (it->_Health <= 0)   {
                auto it2 = it;
                it--;
                ennemies.erase(it2);
            }

        // render()
        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.render();
        for (Ennemy & cur: ennemies)
            cur.render();
        EndDrawing();
    }
}

void	ft_exit()
{
    CloseWindow();
    exit(0);
}

int	menu_mouse_click()
{
    int pos[2] = {GetMouseX() , GetMouseY()};
    if (pos[0] < 150 || pos[0] > 250)
        return (0);
    if (pos[1] > 150 && pos[1] < 200)
        return(1);
    else if (pos[1] > 300 && pos[1] < 350)
        ft_exit();
    return (0);
}