#include <Game.h>

float x = 0.0f;
float y = 0.0f;
float scale = 1.0f;
Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(0)
{

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


}

void Game::update()
{

	swapPress();
	inputRotation();
	glLoadIdentityOn();
	inputTranslate();
	scaleObjects();
	

	glRotatef(rotationAngle, 0.0f, 0.0f, 1.0f);
	glTranslatef(x, y, 0.0f);
	glScalef(scale, scale, scale);
	if (identity)
	{
		glLoadIdentity();
	}
}

void Game::draw()
{



	
		

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		if (image == 0)
		{
			glBegin(GL_TRIANGLES);
			{
			
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
				
				glColor3f(0.0f, 1.0f, 1.0f);
				glVertex3f(10.0, 2.0, -50.0);


			}
			glEnd();
		}
		
		else if (image == 2)
		{
			glBegin(GL_LINES);
			{
				
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

void Game::inputRotation()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rotationAngle -= 0.0005f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rotationAngle += 0.0005f;
	}
}

void Game::inputTranslate()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		x -= 0.00005f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		x += 0.00005f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		y -= 0.00005f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		y += 0.00005f;
	}
}

void Game::scaleObjects()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
	{
		scale -= 0.00005f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		scale += 0.00005f;
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

			// Reset Values
			identity = false;
			x = 0;
			y = 0;
			scale = 1.0f;
			rotationAngle = 0;


			return true;
		}

	}
	else
	{
		pressed = false;
		return false;
	}
}

