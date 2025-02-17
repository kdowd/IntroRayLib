#include <iostream>
#include <vector>
#include <raylib.h>
#include <raylib-cpp-utils.hpp>


using namespace std;

const int screenWidth = 800;
const int screenHeight = 600;

const int MAX_COLORS_COUNT = 21;

class Paddle {

public:
	Vector2 v{};
	int speed = 6;


	Paddle(int x, int y) {

		v.x = x;
		v.y = y;

	}

	void Draw() {
		DrawRectangle(v.x, v.y, 100, 20, { 255,0,0,125 });
	}

	void Update() {

		if (IsKeyDown(KEY_RIGHT)) v.x += speed;
		if (IsKeyDown(KEY_LEFT)) v.x -= speed;
		if (IsKeyDown(KEY_UP)) v.y -= speed;
		if (IsKeyDown(KEY_DOWN)) v.y += speed;
	}

};

int main()
{
	std::cout << "Hello World!\n";





	InitAudioDevice();
	Sound fxWav = LoadSound("stereofl.wav");
	PlaySound(fxWav);


	Color BackGroundColour = Color{ 155, 155, 155, 255 };

	SetTraceLogLevel(TraceLogLevel::LOG_NONE);

	InitWindow(screenWidth, screenHeight, "RAYGUNNED");
	SetTargetFPS(60);
	Paddle P(screenWidth / 2, screenHeight / 2);
	Texture2D plane = LoadTexture("StashAirplaneDuotone.png");
	Vector2 planePos = { 30,30 };




	while (WindowShouldClose() == false) {

		if (IsKeyDown(KEY_SPACE)) {
			DrawText("Welcome To My Game, Suckers !!!!", 18, GetScreenHeight() - 30, 20, GOLD);
			DrawFPS(10, 10);
		}

		BeginDrawing();
		P.Draw();
		P.Update();
		DrawTextureV(plane, planePos, RAYWHITE);



		EndDrawing();

		ClearBackground(BackGroundColour);
	}

	CloseWindow();
}

