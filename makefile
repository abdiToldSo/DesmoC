test:
	gcc -o DesmoC.exe test.cpp -lraylib -lgdi32 -lwinmm
test2:
	gcc -o DesmoC.exe test2.cpp -lraylib -lgdi32 -lwinmm
run:
	./DesmoC
build: test.cpp Plane.o
	g++ -o DesmoC.exe Plane.o tinyexpr.o test.cpp -lraylib -lgdi32 -lwinmm
	./DesmoC
Plane.o: Plane.h Plane.cpp
	 gcc Plane.cpp -lraylib -lwinmm -lgdi32 -c
tinyexpr.o: tinyexpr.h tinyexpr.c
	gcc -c tinyexpr.c -lwinmm -lgdi32
