#include <math.h>
#include "raylib.h"

#define WIDTH 900
#define HEIGHT 600

#define ANGLE_DERIVATION 20 * (M_PI/180.00)
#define GEN_DERIV 0.7
#define START_LENGTH 180
#define COLOR_TREE RAYWHITE

void Draw_tree(float x, float y, float length, float angle, float thickness)
{
	if (length <= 1)
		return ;
	Vector2 start = {x, y};
	Vector2 end = {x + sin(angle) * length , y - cos(angle) * length};
	DrawLineEx(start, end, thickness, RAYWHITE);	
	Draw_tree(end.x, end.y, length * GEN_DERIV, angle + ANGLE_DERIVATION , thickness * GEN_DERIV);
	Draw_tree(end.x, end.y, length * GEN_DERIV, angle - ANGLE_DERIVATION , thickness * GEN_DERIV);
}

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Tree-Fractal");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
	Draw_tree(WIDTH/2 , HEIGHT - 10, START_LENGTH ,0 * (M_PI/180.00) , 20);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
