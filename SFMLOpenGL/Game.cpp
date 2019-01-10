#include <Game.h>

bool flip = false;
int current = 1;

// colours..
MyVector3 red = { 1.0f, 0.0f, 0.0f };
MyVector3 green = { 0.0f, 1.0f, 0.0f };
MyVector3 blue = { 0.0f, 0.0f, 1.0f };

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	cubeCorners[0] = v1;
	cubeCorners[1] = v2;
	cubeCorners[2] = v3;
	cubeCorners[3] = v4;
	cubeCorners[4] = v5;
	cubeCorners[5] = v6;
	cubeCorners[6] = v7;
	cubeCorners[7] = v8;
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
float colors[] = { 
	red.x,red.y,red.z,
    green.x,green.y,green.z,		//1st triangle
	blue.x,blue.y,blue.z,

    red.x,red.y,red.z,
	green.x,green.y,green.z,		//2
	blue.x,blue.y,blue.z,

				   
	red.x,red.y,red.z,               
	green.x,green.y,green.z,       //3         
	blue.x,blue.y,blue.z,

	              
	red.x,red.y,red.z,              
	green.x,green.y,green.z,       //4    
	blue.x,blue.y,blue.z,

					
	red.x,red.y,red.z,				
	green.x,green.y,green.z,		//5		
	blue.x,blue.y,blue.z,

	red.x,red.y,red.z,
	green.x,green.y,green.z,		//6
	blue.x,blue.y,blue.z,

	red.x,red.y,red.z,
	green.x,green.y,green.z,		//7
	blue.x,blue.y,blue.z,

	red.x,red.y,red.z,
	green.x,green.y,green.z,		//8
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
unsigned int vertex_index[] = { 0, 1, 2,   3, 4, 5,   6, 7, 8,   9, 10, 11,   12, 13,14,   15, 16,17,  18, 19, 20,   21, 22, 23 };

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
	checkKeyPress();

	updateVerts();

	elapsed = clock.getElapsedTime();

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glVertexPointer(3, GL_FLOAT, 0, &vertices);
	glColorPointer(3, GL_FLOAT, 0, &colors);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, &vertex_index);

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}


void Game::checkKeyPress()
{
	// rotations...
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		/*for (float x : vertices)
		{
			x = (MyMatrix3::rotationX(0.01) * x);
		}
		*/
		for (int i = 0; i < 8; i++)
		{
			cubeCorners[i] = (MyMatrix3::rotationX(0.01) * cubeCorners[i]);
		}
	}
	
}

void Game::updateVerts()
{
	/*vertIndex = 0;
	for (int i = 0; i < 8; i++)
	{
		vertices[vertIndex] = cubeCorners[i].x;
		vertIndex++;
		vertices[vertIndex] = cubeCorners[i].y;
		vertIndex++;
		vertices[vertIndex] = cubeCorners[i].z;
		vertIndex++;
	}*/

	//v0
	vertices[0] = cubeCorners[0].x;
	vertices[1] = cubeCorners[0].y;
	vertices[2] = cubeCorners[0].z;
	//v1
	vertices[3] = cubeCorners[1].x;
	vertices[4] = cubeCorners[1].y;
	vertices[5] = cubeCorners[1].z;
	//v2
	vertices[6] = cubeCorners[2].x;
	vertices[7] = cubeCorners[2].y;
	vertices[8] = cubeCorners[2].z;
	//v3
	vertices[9] = cubeCorners[0].x;
	vertices[10] = cubeCorners[0].y;
	vertices[11] = cubeCorners[0].z;
	//v4
	vertices[12] = cubeCorners[3].x;
	vertices[13] = cubeCorners[3].y;
	vertices[14] = cubeCorners[3].z;
	//v5
	vertices[15] = cubeCorners[2].x;
	vertices[16] = cubeCorners[2].y;
	vertices[17] = cubeCorners[2].z;
	//v6
	vertices[18] = cubeCorners[4].x;
	vertices[19] = cubeCorners[4].y;
	vertices[20] = cubeCorners[4].z;
	//v7
	vertices[21] = cubeCorners[5].x;
	vertices[22] = cubeCorners[5].y;
	vertices[23] = cubeCorners[5].z;
	//v8
	vertices[24] = cubeCorners[6].x;
	vertices[25] = cubeCorners[6].y;
	vertices[26] = cubeCorners[6].z;
	//v9
	vertices[27] = cubeCorners[4].x;
	vertices[28] = cubeCorners[4].y;
	vertices[29] = cubeCorners[4].z;
	//v10
	vertices[30] = cubeCorners[7].x;
	vertices[31] = cubeCorners[7].y;
	vertices[32] = cubeCorners[7].z;
	//v11
	vertices[33] = cubeCorners[6].x;
	vertices[34] = cubeCorners[6].y;
	vertices[35] = cubeCorners[6].z;
	//v12
	vertices[36] = cubeCorners[0].x;
	vertices[37] = cubeCorners[0].y;
	vertices[38] = cubeCorners[0].z;
	//v13
	vertices[39] = cubeCorners[1].x;
	vertices[40] = cubeCorners[1].y;
	vertices[41] = cubeCorners[1].z;
	//v14
	vertices[42] = cubeCorners[5].x;
	vertices[43] = cubeCorners[5].y;
	vertices[44] = cubeCorners[5].z;
	//v15
	vertices[45] = cubeCorners[4].x;
	vertices[46] = cubeCorners[4].y;
	vertices[47] = cubeCorners[4].z;
	//v16
	vertices[45] = cubeCorners[4].x;
	vertices[46] = cubeCorners[4].y;
	vertices[47] = cubeCorners[4].z;
	//v17
	vertices[48] = cubeCorners[0].x;
	vertices[49] = cubeCorners[0].y;
	vertices[50] = cubeCorners[0].z;
}
