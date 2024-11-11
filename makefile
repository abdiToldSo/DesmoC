test:
	gcc -o raylibhelloworld.exe test.cpp -lraylib -lgdi32 -lwinmm
test2:
	gcc -o raylibhelloworld.exe test2.cpp -lraylib -lgdi32 -lwinmm
run:
	./raylibhelloworld
build: test.cpp Plane.o
	g++ -o raylibhelloworld.exe Plane.o tinyexpr.o test.cpp -lraylib -lgdi32 -lwinmm
	./raylibhelloworld
Plane.o: Plane.h Plane.cpp
	 gcc Plane.cpp -lraylib -lwinmm -lgdi32 -c
tinyexpr.o: tinyexpr.h tinyexpr.c
	gcc -c tinyexpr.c -lwinmm -lgdi32
