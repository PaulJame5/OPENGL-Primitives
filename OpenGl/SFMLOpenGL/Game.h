#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>


#include <gl/GL.h>
#include <gl/GLU.h>

using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	 // Uncomment for Part 2
	 // ********************
	const int primatives;

	GLuint index;
	Clock clock;
	Time elapsed;

	int image = 0;
	void glLoadIdentityOn();
	void inputRotation();
	void inputTranslate();
	void scaleObjects();
	bool identity = false;	
	bool identityPress = false;

	float rotationAngle = 0.0f;
	bool pressed = false;
	bool swapPress();
	 // ********************
};