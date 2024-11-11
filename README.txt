godaamn this was a pain in the butt to setup
now that it is though, i have working text box that i'll putt in the top left corner
now i have to make a graph... damn
after that i can worry about drawing the actual graphs.

prob need to implement a class for the main coordinate system
after that write a class for whatever equation we want to plot... damn
lord help me 🙏

11/10/24 : "Plane.h" is written, got main axis' drawing to screen
|	   gonna try and decide what domain and range should be
|	   I think setting both to 10 would be find for now
|	   after that, draw gray subdivision lines and i'll be happy
|	   then after that, draw circle points according to user input
|	   this went a little smoother than i thouht it would
|	   i think that means i know c++ forreal now
|	   (:O
|	   thank god!
|
->1:01am : Just got the little lines displaying for domain and range (:OOO
|	   last thing to do is plot the graphs
|	   i can either
|		1) Plot the individual points from (-10, 10)
|		2) Plot the continuous line for the same domain ✅
|	   gonna use raylib's bezier curves like this:
|		1) take user's desired plot (e.g. x, try linear then quadratics up to x^2)
|		2) parse and calculate points
|		3) save to Vector2 array of size [22]
|		4) Call this function once in DrawPlane() or equivalent function:
|			DrawSplineBezierCubic(array, 22, 8.0f, RED); (read raylib docs and example for more info)
|	   
|	   Originally planed on having a dedicated graph class, which I might still do but will likely complicate things
|	   think it would be easier to give Plane.h some necessary member vars like "input_graph" && "vector2_points" (<- our array from earlier)
|	   then have a dedicated "void DrawGraph()" function draw the actual graph when the player input isn't empty
|	   that sounds good to me
|	   man i need water lol
|	   but this is so much coooooooooler 😔
|	   nevermind, forgot i refilled my water earlier 🙌 thank god!!!!
|	   bet, less do it now 😎😈
|
->2:26am : Will likely need to use "tinyexpr.h" from github if i want to make my life easier
|	   man i love adding header files to my projects and wonder how to deal with em!!! 😱😱😱 (i dont)
|
->5:30am : nearly done, need to fix plane lines,then implement bezier curve
|
->11:10am: implementing bezier curve for plotted graph
|
->1:37pm : implmented "catmullRom" bezier curve, 90% done :)))
	   I want the plotted line to go past the corners of the window
	   also, still want to implement actual coordinate points
	   after that, allow for camera control with mouse, likely using Camera2D()
	   (btw, variables for points[] size seem to just break the program 🤷)

->2:30pm : also would like to let user move text cursor with arrow keys 
	   so i don't have to delete end of formula to edit
	   (just checked the HandleInputBox() function and it takes a couple more brain cells than
	   I currently have rn ~_~)
