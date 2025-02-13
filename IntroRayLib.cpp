#include <iostream>
#include <vector>
#include <raylib.h>
#include <raylib-cpp-utils.hpp>


using namespace std;

const int screenWidth = 800;
const int screenHeight = 600;



int main()
{
	std::cout << "Hello World!\n";

	Color BackGroundColour = Color{ 155, 155, 155, 255 };

	SetTraceLogLevel(TraceLogLevel::LOG_NONE);

	InitWindow(screenWidth, screenHeight, "RAYGUNNED");
	SetTargetFPS(60);
	Texture2D plane = LoadTexture("StashAirplaneDuotone.png");
	Vector2 planePos = { 30,30 };




	while (WindowShouldClose() == false) {

		if (IsKeyDown(KEY_SPACE)) {
			DrawText("Welcome To My Game, Suckers !!!!", 18, GetScreenHeight() - 30, 20, GOLD);
			DrawFPS(10, 10);
		}

		BeginDrawing();

		DrawTextureV(plane, planePos, RAYWHITE);
		DrawRectangle(screenWidth / 2, screenHeight / 2, 100, 20, { 255,0,0,125 });


		EndDrawing();

		ClearBackground(BackGroundColour);
	}

	CloseWindow();
}

