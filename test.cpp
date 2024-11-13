// #include <iostream>
// #include <string>
// #include <cstring>
#include "include/raylib.h"
// #include "include/rlImGui.h"
// #include "include/imgui.h"
#include "Plane.h"
using namespace std;
bool IsAnyKeyPressed();
void DrawInputBox(char *name, bool mouseOnText, int letterCount,
                  int frameCounter);
void HandleInputBox(char *name, bool &mouseOnText, int &letterCount,
                    int &frameCounter);
// void HandleCameraInput();

Camera2D camera = {0};
const int height = 450;
const int width = 800;

Rectangle textBox = {width / 2.0f - 100, 20, 225, 50};
bool mouseOnText = false;
// char name[MAX_INPUT_CHARS + 1] = "\0";      // NOTE: One extra space required
// for null terminator char '\0'
#define MAX_INPUT_CHARS 10

int main() {
  // const int width = 800;

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  InitWindow(width, height, "raylib [core] example - basic window");
  SetTargetFPS(60);

  // string name = "";
  char name[MAX_INPUT_CHARS + 1] =
      "\0"; // NOTE: One extra space required for null terminator char '\0'
  int letterCount = 0;
  // Rectangle textBox = { width/2.0f - 100, 180, 225, 50};
  bool mouseOnText = false;
  int frameCounter = 0;
  // char inputText[26] = "Place mouse over input box.";
  char inputText[] = "Place mouse over input box.";
  Plane test(width / 2.0f, height / 2.0f);
  camera.target = (Vector2){test.GetPosX() + 20.0f, test.GetPosY() + 20.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;
  // string inputText = "Place mouse over input box.";
  // rlImGuiSetup(true);
  while (!WindowShouldClose()) {
    textBox.x = (GetScreenWidth() / 2.0f) - 100;
    // cout << GetMousePosition().x << " ";
    // cout << GetMousePosition().y << endl;
    HandleInputBox(name, mouseOnText, letterCount, frameCounter);
    // HandleCameraInput();
    if (IsAnyKeyPressed())
      test.HandleInput(name);
    // HandleInputBox(name, mouseOnText);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    test.DrawPlane();
    // test.DrawPoints();
    test.DrawPlot();
    DrawText(inputText,
             (GetScreenWidth() / 2.0f - MeasureText(inputText, 20) / 2), 70, 20,
             GRAY);
    // DrawText(inputText, (GetScreenWidth() / 2), 70, 20, GRAY);
    DrawInputBox(name, mouseOnText, letterCount, frameCounter);
    // DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS),
    // , 100, 20, DARKGRAY);
    DrawText(TextFormat("INPUT CHARS: %i/%i", letterCount, MAX_INPUT_CHARS),
             GetScreenWidth() / 2.0f -
                 MeasureText(TextFormat("INPUT CHARS: %i/%i", letterCount,
                                        MAX_INPUT_CHARS),
                             20) /
                     2.0f,
             100, 20, DARKGRAY);

    EndDrawing();
  }

  // rlImGuiShutdown();
  CloseWindow();
  return 0;
}

bool IsAnyKeyPressed() {
  bool keyPressed = false;
  int key = GetKeyPressed();

  if ((key >= 32) && (key <= 126))
    keyPressed = true;
  return keyPressed;
}

void DrawInputBox(char *name, bool mouseOnText, int letterCount,
                  int frameCounter) {
  if (mouseOnText)
    DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width,
                       (int)textBox.height, RED);
  else
    DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width,
                       (int)textBox.height, DARKGRAY);

  DrawText(name, (int)textBox.x + 5, (int)textBox.y + 8, 40, MAROON);
  if (mouseOnText) {
    if (letterCount < MAX_INPUT_CHARS) {
      // Draw blinking underscore char
      if (((frameCounter / 20) % 2) == 0)
        DrawText("_", (int)textBox.x + 8 + MeasureText(name, 40),
                 (int)textBox.y + 12, 40, MAROON);
    } else
      DrawText("Press BACKSPACE to delete chars...", 230, 110, 20, GRAY);
  }
}

void HandleInputBox(char *name, bool &mouseOnText, int &letterCount,
                    int &frameCounter) {
  if (CheckCollisionPointRec(GetMousePosition(), textBox))
    mouseOnText = true;
  else
    mouseOnText = false;

  if (mouseOnText) {
    SetMouseCursor(MOUSE_CURSOR_IBEAM);
    int key = GetCharPressed();

    while (key > 0) {
      if ((key >= 32) && (key <= 125) && (letterCount < MAX_INPUT_CHARS)) {
        name[letterCount] = (char)key;
        name[letterCount + 1] = '\0';
        letterCount++;
      }

      key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE)) {
      letterCount--;
      if (letterCount < 0)
        letterCount = 0;
      name[letterCount] = '\0';
    }
  } else
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);

  if (mouseOnText)
    frameCounter++;
  else
    frameCounter = 0;
}
/*
void HandleCameraInput() {
        camera.zoom += ((float)GetMouseWheelMove()*0.05f);
        //cout << camera.zoom << endl;
}
*/
