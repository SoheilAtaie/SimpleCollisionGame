#include "raylib.h"

//window details
int width = 200;
int height = 300;

//Circle coordinates
int circle_X{ 50 };
int circle_Y{ 150 };
int circle_radius{ 20 };

// circle edges
int l_circle_X{ circle_X - circle_radius };
int r_circle_X{ circle_X + circle_radius };
int u_circle_Y{ circle_Y - circle_radius };
int b_circle_Y{ circle_Y + circle_radius };

//rect coordiates
int rect_X = 100;
int rect_Y = 0;
int rect_length{ 50 };

// rect edges
int l_rect_X{ rect_X };
int r_rect_X{ rect_X + rect_length };
int u_rect_Y{ rect_Y };
int b_rect_Y{ rect_Y + rect_length };

int direction{ 10 };

//collision 
bool collision_with_rect = 
						(b_rect_Y >= u_circle_Y) && 
						(u_rect_Y <= b_circle_Y) && 
						(r_rect_X >= l_circle_X) && 
						(l_rect_X <= r_circle_X);

void circle_func()
{
	DrawCircle(circle_X, circle_Y, circle_radius, BLUE);

	if (IsKeyDown(KEY_D) && circle_X < width - circle_radius)
	{
		circle_X = circle_X + 10.0;
	}
	else if (IsKeyDown(KEY_A) && circle_X > circle_radius)
	{
		circle_X = circle_X - 10.0;
	}
	else if (IsKeyDown(KEY_S) && circle_Y < height - circle_radius)
	{
		circle_Y = circle_Y + 10.0;
	}
	else if (IsKeyDown(KEY_W) && circle_Y > circle_radius)
	{
		circle_Y = circle_Y - 10.0;
	}
}

void rect_func() 
{
	DrawRectangle(rect_X, rect_Y, rect_length, rect_length, ORANGE);
	
	// Move the box 
	rect_Y += direction;
	if (rect_Y > height || rect_Y < 0)
	{
		direction = -direction;
	}
}

int main()
{
	InitWindow(width, height, "AwesomeGame!");


	SetTargetFPS(60);

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		ClearBackground(RED);

		if (collision_with_rect == false)
		{
			// update collision detection edges 
			l_circle_X = circle_X - circle_radius;
			r_circle_X = circle_X + circle_radius;
			u_circle_Y = circle_Y - circle_radius;
			b_circle_Y = circle_Y + circle_radius;
			l_rect_X = rect_X;
			r_rect_X = rect_X + rect_length;
			u_rect_Y = rect_Y;
			b_rect_Y = rect_Y + rect_length;
			// update the collision bool
			collision_with_rect =
				(b_rect_Y >= u_circle_Y) &&
				(u_rect_Y <= b_circle_Y) &&
				(r_rect_X >= l_circle_X) &&
				(l_rect_X <= r_circle_X);

			circle_func();
			rect_func();
			
		}
		else
		{
			DrawText("Game Over!", 50, 100, 20, BLACK);
		}
		
		
		EndDrawing();
	}

	return 0;
}
