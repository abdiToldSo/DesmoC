#include <iostream>
#include "include/raylib.h"
#include "include/rlImGui.h"
#include "include/imgui.h"
using namespace std;


int main() {
	const int width = 800;
	const int height = 450;

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(width, height, "raylib [core] example - basic window");
	SetTargetFPS(60);
	//rlImGuiSetup(true);
	while (!WindowShouldClose()) {
		BeginDrawing();
			//rlImGuiBegin();
			ClearBackground(RAYWHITE);
			DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
			//rlImGuiEnd();
		EndDrawing();
	}

	//rlImGuiShutdown();
	CloseWindow();

	return 0;
}
