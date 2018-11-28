#include <Game.h>

 // Uncomment for Part 2
 // ********************
bool flip = false;
int current = 1;
 // ********************

Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(0)
{
	 // Uncomment for Part 2
	 // ********************
	 index = glGenLists(primatives);
	 // ********************
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0); 
	glMatrixMode(GL_MODELVIEW);

	//  Uncomment for Part 2
	//  ********************
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	//glMatrixMode(GL_MODELVIEW);


	//glNewList(index, GL_COMPILE);
	//glBegin(GL_TRIANGLES);
	//{
	//	glColor3f(0.0f, 0.0f, 1.0f);
	//	glVertex3f(0.0, 2.0, -4.0);
	//	glVertex3f(-2.0, -2.0, -5.0);
	//	glVertex3f(2.0, -2.0, -5.0);
	//}
	//glEnd();
	//glEndList();


	//glNewList(index+2, GL_COMPILE);
	//glBegin(GL_TRIANGLES);
	//{
	//	glColor3f(1.0f, 0.0f, 1.0f);
	//	glVertex3f(0.0, 2.0, -5.0);
	//	glVertex3f(-2.0, -2.0, -5.0);
	//	glVertex3f(2.0, -2.0, -5.0);
	//}
	//glEnd();
	//glEndList();

	//glNewList(index + 1, GL_COMPILE);
	//glBegin(GL_TRIANGLES);
	//{
	//	glColor3f(0.0f, 1.0f, 0.0f);
	//	glVertex3f(0.2, 0.0, -2.0);
	//	glVertex3f(-2.0, -2.0, -2.0);
	//	glVertex3f(2.0, -2.0, -2.0);
	//}
	//glEnd();
	//glEndList();

	 // Uncomment for Part 2
	 // ********************
}

void Game::update()
{

	 // Uncomment for Part 2
	 // ********************
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	 // ********************

	//cout << "Update up" << endl;
}

void Game::draw()
{

	// // Uncomment for Part 2
	// // ********************
	//cout << "Draw up" << endl;

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	////Investigate Here!!!!!

	//cout << "Drawing Primative " << current << endl;
	//glCallList(current);
	// // Uncomment for Part 2
	// // ********************

	//window.display();

	
		

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		if (image == 0)
		{
			glBegin(GL_TRIANGLES);
			{
				if (identity)
				{
					glLoadIdentity();
				}
				glColor3f(0.0f, 1.0f, 1.0f);
				glVertex3f(0.0, 2.0, -50.0);


				glVertex3f(-2.0, -2.0, -50.0);
				glVertex3f(2.0, -2.0, -50.0);
			}
			glEnd();
		}
		else if (image == 1)
		{
			glBegin(GL_POINTS);
			{
				if (identity)
				{
					glLoadIdentity();
				}
				glColor3f(0.0f, 1.0f, 1.0f);
				glVertex3f(10.0, 2.0, -50.0);


			}
			glEnd();
		}
		
		else if (image == 2)
		{
			glBegin(GL_LINES);
			{
				if (identity)
				{
					glLoadIdentity();
				}
				glColor3f(1.0f, 1.0f, 1.0f); glLineWidth(10.0);
				glVertex3f(0.0, 10.0, -50.0);
				glVertex3f(-10.0, 2.0, -50.0);


			}
			glEnd();
		}

		else if (image == 3)
		{
			// Draws a line from the end of each point to the next 
			glBegin(GL_LINE_STRIP);
			{
				if (identity)
				{
					glLoadIdentity();
				}
				glColor3f(1.0f, 1.0f, 1.0f); glLineWidth(10.0);
				glVertex3f(15.0, 10.0, -50.0);
				glVertex3f(10.0, 2.0, -50.0);
				glVertex3f(-5.0, 2.0, -50.0);
				glVertex3f(15.0, 10.0, -50.0);


			}
			glEnd();
		}

		else if (image == 4)
		{
			// Will link the last one to the first vertex point
			glBegin(GL_LINE_LOOP);
			{
				if (identity)
				{
					glLoadIdentity();
				}
				glColor3f(0.0f, 1.0f, 1.0f); glLineWidth(10.0);
				glVertex3f(-15.0, -10.0, -50.0);
				glVertex3f(-10.0, -2.0, -50.0);
				glVertex3f(5.0, -2.0, -50.0);
				glVertex3f(-15.0, 10.0, -50.0);


			}
			glEnd();
		}

		else if (image == 5)
		{
			glBegin(GL_TRIANGLE_STRIP);
			{
				if (identity)
				{
					glLoadIdentity();
				}
				glColor3f(0.0f, 0.0f, 1.0f);
				glVertex3f(0.0, 5.0, -50.0);
				glVertex3f(-2.0, 8.0, -50.0);
				glVertex3f(2.0, 8.0, -50.0);
				glVertex3f(5.0, 5.0, -50.0);
			}
			glEnd();
		}

		else if (image == 6)
		{
			glBegin(GL_TRIANGLE_FAN);
			{
				if (identity)
				{
					glLoadIdentity();
				}
				glColor3f(0.5f, 0.5f, 1.0f);
				glVertex3f(0.0, -5.0, -50.0);
				glVertex3f(-2.0, -8.0, -50.0);
				glVertex3f(2.0, -8.0, -50.0);
				glVertex3f(5.0, -5.0, -50.0);
				glVertex3f(6.0, -6.0, -50.0);
			}
			glEnd();
		}

		else if (image == 7)
		{
			glBegin(GL_QUADS);
			{
				if (identity)
				{
					glLoadIdentity();
				}
				glColor3f(0.2f, 0.5f, 0.3f);
				glVertex3f(2.0, -15.0, -50.0);
				glVertex3f(2.0, -12.0, -50.0);
				glVertex3f(-6.0, -12.0, -50.0);
				glVertex3f(-6.0, -15.0, -50.0);
			}
			glEnd();
		}

		else if (image == 8)
		{
			glBegin(GL_QUAD_STRIP);
			{
				if (identity)
				{
					glLoadIdentity();
				}
				glColor3f(0.2f, 0.5f, 0.3f);
				glVertex3f(0.0, -18.0, -80.0);
				glVertex3f(0.0, -16.0, -80.0);
				glVertex3f(-6.0, -18.0, -80.0);
				glVertex3f(-6.0, -16.0, -80.0);
				glVertex3f(26.0, 20.0, -80.0);
			}
			glEnd();
		}

		else if (image == 9)
		{
			glBegin(GL_POLYGON);
			{
				if (identity)
				{
					glLoadIdentity();
				}
				glColor3f(0.2f, 0.2f, 0.3f);
				glVertex3f(-26.0, -18.0, -80.0);
				glVertex3f(-26.0, 16.0, -80.0);
				glVertex3f(-20.0, -18.0, -80.0);
				glVertex3f(-20.0, -16.0, -80.0);
				glVertex3f(-15.0, 20.0, -80.0);
			}
			glEnd();
		}
		     
		swapPress();
		glLoadIdentityOn();
		window.display();
	

}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}

void Game::glLoadIdentityOn()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		cout << "Press I" << endl;
		if (!identityPress)
		{
			identity = !identity;
			identityPress = true;
		}

	}
	else
	{
		identityPress = false;
	}
}

bool Game::swapPress()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		cout << "Press" << endl;
		if (pressed)
		{
			return false;
		}
		else
		{
			if (image < 9)
			{
				image++;
			}
			else
			{
				image = 0;
			}
			pressed = true;
			return true;
		}

	}
	else
	{
		pressed = false;
		return false;
	}
}

