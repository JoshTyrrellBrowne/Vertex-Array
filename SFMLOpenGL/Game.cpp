#include <Game.h>

bool flip = false;
int current = 1;

// colours..
MyVector3 red = { 1.0f, 0.0f, 0.0f };
MyVector3 green = { 0.0f, 1.0f, 0.0f };
MyVector3 blue = { 0.0f, 0.0f, 1.0f };

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{

}

Game::~Game() {}


// Vertices for one Triangle
float vertices[] = { 1.0f, 1.0f, -5.0f,   -1.0f, 1.0f, -5.0f,   -1.0f, -1.0f, -5.0f,	// Front face
					 1.0f, 1.0f, -5.0f,   1.0f, -1.0f, -5.0f,   -1.0f, -1.0f, -5.0f, 

					 1.0f, 1.0f, -6.0f,   -1.0f, 1.0f, -6.0f,   -1.0f, -1.0f, -6.0f,	// Back face
					 1.0f, 1.0f, -6.0f,   1.0f, -1.0f, -6.0f,   -1.0f, -1.0f, -6.0f,

					 1.0f, 1.0f, -5.0f,   -1.0f, 1.0f, -5.0f,   -1.0f, 1.0f, -6.0f,	// Top Face
					 1.0f, 1.0f, -6.0f,   -1.0f, 1.0f, -6.0f,   1.0f, 1.0f, -5.0f,

					 1.0f, 1.0f, -5.0f,   -1.0f, -1.0f, -5.0f,   1.0f, 1.0f, -6.0f,	// Right side Face
					 1.0f, 1.0f, -6.0f,   -1.0f, -1.0f, -6.0f,   -1.0f, -1.0f, -5.0f };

// Colors for those vertices
float colors[] = { red.x,red.y,red.z,
				   green.x,green.y,green.z,
				   blue.x,blue.y,blue.z,

                   red.x,red.y,red.z,
				   green.x,green.y,green.z,
                   blue.x,blue.y,blue.z,

				   red.x,red.y,red.z,
	               green.x,green.y,green.z,
	               blue.x,blue.y,blue.z,

	               red.x,red.y,red.z,
	               green.x,green.y,green.z,
	               blue.x,blue.y,blue.z,

					red.x,red.y,red.z,
					green.x,green.y,green.z,
					blue.x,blue.y,blue.z,

					red.x,red.y,red.z,
					green.x,green.y,green.z,
					blue.x,blue.y,blue.z,

					blue.x,blue.y,blue.z,
					blue.x,blue.y,blue.z,
					blue.x,blue.y,blue.z,

					blue.x,blue.y,blue.z,
					blue.x,blue.y,blue.z,
					blue.x,blue.y,blue.z };

// OLD WAY..
/*{ 1.0f, 0.0f, 0.0f, 
					0.0f, 1.0f, 0.0f, 
					0.0f, 0.0f, 1.0f,
					1.0f, 0.0f, 0.0f,
					0.0f, 1.0f, 0.0f,
					0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f,
	1.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 1.0f };*/

// Index to be drawn
unsigned int vertex_index[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

void Game::initialize()
{
	isRunning = true;

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLES, 23, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

