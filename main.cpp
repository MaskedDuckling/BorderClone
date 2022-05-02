
#include "raylib.h"
#include <iostream>

void	ft_exit()
{
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

int	menu()
{
	Texture2D scarfy = LoadTexture("sprites/Title.png");
	while (1)
	{
		BeginDrawing();
		DrawTexture(scarfy, -50, -50, WHITE);
		DrawText("Dark Zombie", 0, 0, 50, GREEN);
		DrawText("Play",150, 150, 50, BLACK);
		DrawText("Exit",150, 300, 50, BLACK);
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && menu_mouse_click())
			return (1);
		EndDrawing();
	}
	return (1);
}

int main(void)
{
	const int screenWidth = 960;
	const int screenHeight = 540;
	float speed = 5.0f;
	InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
	SetTargetFPS(60); 
	menu();
	while (!(WindowShouldClose()))
	{
	
	}
	CloseWindow();
	return 0;
}