#include "include/raylib.h"
#include "include/tinyexpr.h"
#include <iostream>
#include <string>
#ifndef _PLANE_H_
#define _PLANE_H_

typedef struct {
  Vector2 start;
  Vector2 end;
} ControlPoint;

class Plane {
private:
  int posX;
  int posY;
  Vector2 points[23];
  Vector2 pointsInterleaved[3 * 22 + 1] = {0};
  char *m_input;
  ControlPoint control[23 - 1] = {0};
  int pointSize = 23;
  float f_pointSize = 23.0f;

public:
  Plane(int posX, int posY);
  ~Plane();
  int GetPosX();
  int GetPosY();
  void SetPosX(int X);
  void SetPosY(int Y);
  void DrawPlane();
  void CalculatePoints(char *input);
  void HandleInput(char *input) {
    m_input = input;
    std::cout << m_input << std::endl;
    CalculatePoints(m_input);
  }
  void DrawPoints();
  void DrawPlot();
  void HandlePlane(); //<- Would Take Mouse Input to Zoom In and Out
};

#endif
