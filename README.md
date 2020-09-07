# switch-lighttable
literally displays a screen filled with one color, for scanning negatives or other uses. Like a flashlight, or video light.

Uses OpenGL. Why? CV-driven development.

# Controls

* X, B, A - increase amount of red, green, blue.
* R + X, B, A - decrease amount of red, green, blue.
* Y - increase brightness.
* R + Y - decrease brightness.

* Up, Down, Left, Right - presets. 
* Held U/D/L/R - preset overwrite with current setting.

Presets are written to a text file /switch/lighttable/presets.ini, so you can modify it as you like in your favorite text editor (the biggest problem - no native vim port on Switch). In case such a file does not exist, it will be filled with default values:
* Up, left and right is brightest, whitest; 
* Down is least bright, black, to save power.

* + - toggle display of parameters.

# Todo, or other dumb ideas

* implement everything listed here
* add 35mm/645/6x6/6x7/6x9 borders for aligning negatives (of course, created as OpenGL vertices-objects thingeys - sorry, I'm really bad with computer graphics)
* absolutely retarded, as the screen has horrible PPI and is an LCD and not an OLED - a gallery app that displays >negative< of the given images, and cycles through 6x6/6x9/24x36mm formats so you can slide your switch in the film carrier of your enlarger and print digital pictures.
