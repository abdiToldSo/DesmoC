#include "Plane.h"

Plane::Plane(int X, int Y) {
	posX = X;
	posY = Y;
}

Plane::~Plane() {}
int Plane::GetPosX() {return posX;}
int Plane::GetPosY() {return posY;}
void Plane::SetPosX(int X) {posX = X;}
void Plane::SetPosY(int Y) {posY = Y;}
void Plane::DrawPlane() {
	//DrawCircle(posX, posY, 100, BLACK);
	//std::cout << GetScreenWidth() << std::endl;
	/*
	for (double i=0; i < GetScreenWidth(); i += GetScreenWidth()/22.0f) {
	//for (; i < GetScreenWidth(); i += GetScreenWidth()/22) {
		//if (!( (i < GetScreenWidth()/2.0) +10 && (i > GetScreenWidth()/2.0) - 10)) {
		//if ( !(GetScreenWidth()/2.0 - 10.0 <= i && i <= GetScreenWidth()/2.0 + 10.0) ) {
			DrawLine(i, 0, i, GetScreenHeight(), PURPLE );
		//}
	}
	
	//for (double i=0; i < GetScreenHeight(); i += GetScreenHeight()/22.0f) {
	for (double i=0; i < GetScreenHeight(); i += GetScreenWidth()/22.0f) {
	//for (; i < GetScreenWidth(); i += GetScreenWidth()/22) {
		//if (!( (i < GetScreenWidth()/2.0) +10 && (i > GetScreenWidth()/2.0) - 10)) {
		if ( !(GetScreenHeight()/2.0f - 5.0 <= i && i <= GetScreenHeight()/2.0f + 5.0) ) {
			DrawLine(0, i+1, GetScreenWidth(), i+1, PURPLE );
		}
	}
	*/
	DrawLine( GetScreenWidth(), GetScreenHeight()/2.0f,0, GetScreenHeight()/2.0f, BLACK );
	DrawLine( (GetScreenWidth()/2.0f), GetScreenHeight(), (GetScreenWidth()/2.0f), 0, BLACK );
}

void Plane::CalculatePoints(char *input) {
	//prob have to use hard coded values for
	//curves like x & x^2
	//formula = input
	//points = 22
	double x;
	te_variable vars[] = {{"x", &x}};	
	int err;

	te_expr *expr = te_compile(input, vars, 1, &err);

	if (expr) {
		for (int i = 0; i < 23; i++) {
			x = i-11;
			points[i] = (Vector2){x, te_eval(expr)};
			//control[i].start = (Vector2){ points[i].x +50, points[i].y };
			control[i].start = (Vector2){ 
				GetScreenWidth()/2.0f + 50.0f + points[i].x*(GetScreenWidth()/23.0f +0.0f),
				GetScreenHeight()/2.0f + 50.0f + points[i].y*-(GetScreenHeight()/23.0f +0.0f),
			};
			control[i].end = (Vector2){ 
				GetScreenWidth()/2.0f - 50.0f + points[i].x*(GetScreenWidth()/23.0f +0.0f),
				GetScreenHeight()/2.0f - 50.0f + points[i].y*-(GetScreenHeight()/23.0f +0.0f),
			};
			//control[i].end = (Vector2){ points[i+1].x -50, points[i+1].y };
			std::cout << points[i].x << " " << points[i].y << std::endl;
		}
		te_free(expr);
	} else {
		std::cout << "Parse Error!" << std::endl;
	}
}

void Plane::DrawPoints() {
	for (int i = 0; i < 23; i++) {

		DrawCircle(
			  //GetScreenWidth()/2.0f + 0.0f + points[i].x*(GetScreenWidth()/23.0f +0.0f) - 2*points[i].x,
			  //GetScreenWidth()/2.0f + 0.0f + points[i].x*(GetScreenWidth()/23.0f +0.0f) - 2*points[i].x,
			  GetScreenWidth()/2.0f + 0.0f + points[i].x*(GetScreenWidth()/23.0f +0.0f),
			  //GetScreenHeight()/2.0f + points[i].y*-22.0f,
			  GetScreenHeight()/2.0f + 0.0f + points[i].y*-(GetScreenHeight()/23.0f +0.0f),
			  //GetScreenHeight()/2.0f + 0.0f + points[i].y*-(GetScreenHeight()/23.0f +0.0f),
			  //points[i].x + GetScreenWidth()/2.0f,
			  //points[i].y + GetScreenHeight()/2.0f,
			  8.0f,
			  RED
			  );
		//DrawLine(points[i].x*(GetScreenWidth()/23.0f)+GetScreenWidth()/2.0f, 0, points[i].x*(GetScreenWidth()/23.0f)+GetScreenWidth()/2.0f, GetScreenHeight(), PURPLE);
		//DrawLine(0, GetScreenHeight()/2.0f + 0.0f + points[i].y*-(GetScreenHeight()/23.0f +0.0f), GetScreenWidth(),  GetScreenHeight()/2.0f + 0.0f + points[i].y*-(GetScreenHeight()/23.0f +0.0f), PURPLE );

	}
}
void Plane::DrawPlot() {
	//for (int i = 0; i < (23-1); i++) {
	Vector2 bezierPoints[23];
	for (int i = 0; i < 23; i++) {
		//pointsInterleaved[3*i] = points[i];
		/*
		pointsInterleaved[3*i] = (Vector2) {GetScreenWidth()/2.0f + 0.0f + points[i].x*(GetScreenWidth()/23.0f +0.0f),
						  GetScreenHeight()/2.0f + 0.0f + points[i].y*-(GetScreenHeight()/23.0f +0.0f),};
		pointsInterleaved[3*i + 1] = (Vector2) {GetScreenWidth()/2.0f + 0.0f + points[i+1].x*(GetScreenWidth()/23.0f +0.0f),
						  GetScreenHeight()/2.0f + 0.0f + points[i+1].y*-(GetScreenHeight()/23.0f +0.0f),};
		pointsInterleaved[3*i + 2] = (Vector2) {GetScreenWidth()/2.0f + 0.0f + points[i+2].x*(GetScreenWidth()/23.0f +0.0f),
						  GetScreenHeight()/2.0f + 0.0f + points[i+2].y*-(GetScreenHeight()/23.0f +0.0f),};
		pointsInterleaved[3*i + 1] = points[i];
		pointsInterleaved[3*i + 2] = points[i];
		*/

		bezierPoints[i] = (Vector2) {
			GetScreenWidth()/2.0f + 0.0f + points[i].x*(GetScreenWidth()/23.0f +0.0f),
			GetScreenHeight()/2.0f + 0.0f + points[i].y*-(GetScreenHeight()/23.0f +0.0f)
		};
	}
	//pointsInterleaved[3*(23-1)] = points[23-1];
	//DrawSplineBezierCubic(pointsInterleaved, 3*(23-1)+1, 8.0f, RED);
	DrawSplineCatmullRom(bezierPoints, 23, 8.0f, RED);
}
//GetScreenWidth()/2.0f + 0.0f + points[i].x*(GetScreenWidth()/23.0f +0.0f),

void HandlePlane() {
	return; //this will be hard to implement, raylib has an included Camera2d
		//however that's giving me a blank window rn	
}
