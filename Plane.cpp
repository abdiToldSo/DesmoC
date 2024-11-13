#include "Plane.h"

Plane::Plane(int X, int Y) {
  posX = X;
  posY = Y;
}

Plane::~Plane() {}
int Plane::GetPosX() { return posX; }
int Plane::GetPosY() { return posY; }
void Plane::SetPosX(int X) { posX = X; }
void Plane::SetPosY(int Y) { posY = Y; }
void Plane::DrawPlane() {
  DrawLine(GetScreenWidth(), GetScreenHeight() / 2.0f, 0,
           GetScreenHeight() / 2.0f, BLACK);
  DrawLine((GetScreenWidth() / 2.0f), GetScreenHeight(),
           (GetScreenWidth() / 2.0f), 0, BLACK);
}

void Plane::CalculatePoints(char *input) {
  // prob have to use hard coded values for
  // curves like x & x^2
  // formula = input
  // points = 22
  double x;
  te_variable vars[] = {{"x", &x}};
  int err;

  te_expr *expr = te_compile(input, vars, 1, &err);

  if (expr) {
    for (int i = 0; i < 23; i++) {
      x = i - 11;
      points[i] = (Vector2){(float)x, float(te_eval(expr))};
      // control[i].start = (Vector2){ points[i].x +50, points[i].y };
      control[i].start = (Vector2){
          GetScreenWidth() / 2.0f + 50.0f +
              points[i].x * (GetScreenWidth() / 23.0f + 0.0f),
          GetScreenHeight() / 2.0f + 50.0f +
              points[i].y * -(GetScreenHeight() / 23.0f + 0.0f),
      };
      control[i].end = (Vector2){
          GetScreenWidth() / 2.0f - 50.0f +
              points[i].x * (GetScreenWidth() / 23.0f + 0.0f),
          GetScreenHeight() / 2.0f - 50.0f +
              points[i].y * -(GetScreenHeight() / 23.0f + 0.0f),
      };
      // control[i].end = (Vector2){ points[i+1].x -50, points[i+1].y };
      std::cout << points[i].x << " " << points[i].y << std::endl;
    }
    te_free(expr);
  } else {
    std::cout << "Parse Error!" << std::endl;
  }
}

void Plane::DrawPoints() {
  for (int i = 0; i < 23; i++) {

    DrawCircle(GetScreenWidth() / 2.0f + 0.0f +
                   points[i].x * (GetScreenWidth() / 23.0f + 0.0f),
               // GetScreenHeight()/2.0f + points[i].y*-22.0f,
               GetScreenHeight() / 2.0f + 0.0f +
                   points[i].y * -(GetScreenHeight() / 23.0f + 0.0f),
               8.0f, RED);
  }
}
void Plane::DrawPlot() {
  // for (int i = 0; i < (23-1); i++) {
  Vector2 bezierPoints[23];
  for (int i = 0; i < 23; i++) {
    bezierPoints[i] =
        (Vector2){GetScreenWidth() / 2.0f + 0.0f +
                      points[i].x * (GetScreenWidth() / 23.0f + 0.0f),
                  GetScreenHeight() / 2.0f + 0.0f +
                      points[i].y * -(GetScreenHeight() / 23.0f + 0.0f)};
  }
  // pointsInterleaved[3*(23-1)] = points[23-1];
  // DrawSplineBezierCubic(pointsInterleaved, 3*(23-1)+1, 8.0f, RED);
  DrawSplineCatmullRom(bezierPoints, 23, 8.0f, RED);
}
// GetScreenWidth()/2.0f + 0.0f + points[i].x*(GetScreenWidth()/23.0f +0.0f),

void HandlePlane() {
  return; // this will be hard to implement, raylib has an included Camera2d
          // however that's giving me a blank window rn
}
