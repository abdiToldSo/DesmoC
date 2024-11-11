#include <iostream>
#include "include/raylib.h"
#include "include/rlImGui.h"
#include "include/imgui.h"
//#include "include/Plane.h"
#include "Plane.h"
using namespace std;

#define MAX_INPUT_CHARS     8
int main() {
	const int width = 800;
	const int height = 450;

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(width, height, "raylib [core] example - basic window");
	SetTargetFPS(60);

	//string name = "";
	char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required for null terminator char '\0'
	int letterCount = 0;
	Rectangle textBox = { width/2.0f - 100, 180, 225, 50};
	bool mouseOnText = false;
	int frameCounter = 0;
	//rlImGuiSetup(true);
	while (!WindowShouldClose()) {
		
		if (CheckCollisionPointRec(GetMousePosition(), textBox))
			mouseOnText = true;
		else mouseOnText = false;

		if (mouseOnText) {
			SetMouseCursor(MOUSE_CURSOR_IBEAM);
			int key = GetCharPressed();

			while (key > 0) {
				if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) {
					name[letterCount] = (char)key;
					name[letterCount+1] = '\0';
					letterCount++;
				}

				key = GetCharPressed();
			}

			if (IsKeyPressed(KEY_BACKSPACE)) {
				letterCount--;
				if (letterCount < 0) letterCount = 0;
				name[letterCount] = '\0';
			}
		}
		else SetMouseCursor(MOUSE_CURSOR_DEFAULT);

		if (mouseOnText) frameCounter++;
		else frameCounter = 0;
		
		BeginDrawing();
			ClearBackground(RAYWHITE);
			DrawText("Place mouse over input box.", 240, 140, 20, GRAY);
			if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
			else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

			DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);

			DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS), 315, 250, 20, DARKGRAY);

            if (mouseOnText) {
		if (letterCount < MAX_INPUT_CHARS) {
		// Draw blinking underscore char
			if (((frameCounter/20)%2) == 0) DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40), (int)textBox.y + 12, 40, MAROON);
		}
		else DrawText("Press BACKSPACE to delete chars...", 230, 300, 20, GRAY);
	}
		EndDrawing();
	}

	//rlImGuiShutdown();
	CloseWindow();
	return 0;
}

bool IsAnyKeyPressed() {
	bool keyPressed = false;
	int key = GetKeyPressed();

	if ((key >= 32) && (key <= 126)) keyPressed = true;
	return keyPressed;
}
