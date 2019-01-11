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

	for (int i = 0; i < 108; i++)
	{
		vertex_index[i] = i;
	}

	// initialize displacement to 1
	for (int i = 0; i < 8; i++)
	{
		displacementVectors[i] = { 1,1,1 };
	}
}

Game::~Game() {}




// Vertices for one Triangle (DONE IN UPDATE NOW
//float vertices[] = { 1.0f, 1.0f, -5.0f,   -1.0f, 1.0f, -5.0f,   -1.0f, -1.0f, -5.0f,	// Front face
//					 1.0f, 1.0f, -5.0f,   1.0f, -1.0f, -5.0f,   -1.0f, -1.0f, -5.0f, 
//
//					 1.0f, 1.0f, -6.0f,   -1.0f, 1.0f, -6.0f,   -1.0f, -1.0f, -6.0f,	// Back face
//					 1.0f, 1.0f, -6.0f,   1.0f, -1.0f, -6.0f,   -1.0f, -1.0f, -6.0f,
//
//					 1.0f, 1.0f, -5.0f,   -1.0f, 1.0f, -5.0f,   -1.0f, 1.0f, -6.0f,	// Top Face
//					 1.0f, 1.0f, -6.0f,   -1.0f, 1.0f, -6.0f,   1.0f, 1.0f, -5.0f,
//
//					 1.0f, 1.0f, -5.0f,   -1.0f, -1.0f, -5.0f,   1.0f, 1.0f, -6.0f,	// Right side Face
//					 1.0f, 1.0f, -6.0f,   -1.0f, -1.0f, -6.0f,   -1.0f, -1.0f, -5.0f };

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
	blue.x,blue.y,blue.z,

	red.x,red.y,red.z,
	green.x,green.y,green.z,		//9		
	blue.x,blue.y,blue.z,

	red.x,red.y,red.z,
	green.x,green.y,green.z,		//10
	blue.x,blue.y,blue.z,

	red.x,red.y,red.z,
	green.x,green.y,green.z,		//11
	blue.x,blue.y,blue.z,

	red.x,red.y,red.z,
	green.x,green.y,green.z,		//12
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
//unsigned int vertex_index[] = { 0, 1, 2,   3, 4, 5,   6, 7, 8,   9, 10, 11,   12, 13,14,   15, 16,17,  18, 19, 20,   21, 22, 23, 24, 25, 26, 27,
//								28, 29,30,31,32,33,34,35,36,37,38,39};

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

	glTranslatef(0, 0, -10);   // this moves the camera back
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

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, &vertex_index);

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
		for (int i = 0; i < 8; i++)
		{
			cubeCorners[i] = (MyMatrix3::rotationX(0.01) * cubeCorners[i]);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int i = 0; i < 8; i++)
		{
			cubeCorners[i] = (MyMatrix3::rotationX(-0.01) * cubeCorners[i]);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (int i = 0; i < 8; i++)
		{
			cubeCorners[i] = (MyMatrix3::rotationZ(0.01) * cubeCorners[i]);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < 8; i++)
		{
			cubeCorners[i] = (MyMatrix3::rotationZ(-0.01) * cubeCorners[i]);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		glLoadIdentity();
	}
	// SCALE...
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		for (int i = 0; i < 8; i++)
		{
			cubeCorners[i] = (MyMatrix3::scale(0.99) * cubeCorners[i]);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		for (int i = 0; i < 8; i++)
		{
			cubeCorners[i] = (MyMatrix3::scale(1.01) * cubeCorners[i]);
		}
	}
	// TRANSLATION...
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		for (int i = 0; i < 8; i++)
		{
			// vector addition way..
			/*displacementVectors[i] = displacementVectors[i] + MyVector3(0,0.01,0);*/

			// Matrix Translation way..
			if (displacementVectors[i].z >= 0)// if z < 0 the translation will be opposite
			{
				displacementVectors[i] = MyMatrix3::translation(MyVector3(0, 0.01, 0)) * displacementVectors[i];
			}
			else
			{
				displacementVectors[i] = MyMatrix3::translation(MyVector3(0, -0.01, 0)) * displacementVectors[i];
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		for (int i = 0; i < 8; i++)
		{
			// vector addition way..
			/*displacementVectors[i] = displacementVectors[i] + MyVector3(0, -0.01, 0);*/

			// Matrix Translation way..
			if (displacementVectors[i].z >= 0)// if z < 0 the translation will be opposite
			{
				displacementVectors[i] = MyMatrix3::translation(MyVector3(0, -0.01, 0)) * displacementVectors[i];
			}
			else
			{
				displacementVectors[i] = MyMatrix3::translation(MyVector3(0, 0.01, 0)) * displacementVectors[i];
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (int i = 0; i < 8; i++)
		{
			// vector addition way..
			/*displacementVectors[i] = displacementVectors[i] + MyVector3(0.01, 0, 0);*/

			// Matrix Translation way..
			if (displacementVectors[i].z >= 0)// if z < 0 the translation will be opposite
			{
				displacementVectors[i] = MyMatrix3::translation(MyVector3(0.01, 0, 0)) * displacementVectors[i];
			}
			else
			{
				displacementVectors[i] = MyMatrix3::translation(MyVector3(-0.01, 0, 0)) * displacementVectors[i];
			}
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (int i = 0; i < 8; i++)
		{
			// vector addition way..
			/*displacementVectors[i] = displacementVectors[i] + MyVector3(-0.01, 0, 0);*/

			// Matrix Translation way..
			if (displacementVectors[i].z >= 0)	// if z < 0 the translation will be opposite
			{
				displacementVectors[i] = MyMatrix3::translation(MyVector3(-0.01, 0, 0)) * displacementVectors[i];
			}
			else
			{
				displacementVectors[i] = MyMatrix3::translation(MyVector3(0.01, 0, 0)) * displacementVectors[i];
			}
		}
	}
	
}

void Game::updateVerts()
{
	for (int i = 0; i < 8; i++)
	{
		resultVectors[i] = cubeCorners[i] + displacementVectors[i];
	}

	//v0
	vertices[0] = resultVectors[0].x;
	vertices[1] = resultVectors[0].y;
	vertices[2] = resultVectors[0].z;
	//v1
	vertices[3] = resultVectors[1].x;
	vertices[4] = resultVectors[1].y;
	vertices[5] = resultVectors[1].z;
	//v2
	vertices[6] = resultVectors[2].x;
	vertices[7] = resultVectors[2].y;
	vertices[8] = resultVectors[2].z;
	//v3
	vertices[9] = resultVectors[0].x;
	vertices[10] = resultVectors[0].y;
	vertices[11] = resultVectors[0].z;
	//v4
	vertices[12] = resultVectors[3].x;
	vertices[13] = resultVectors[3].y;
	vertices[14] = resultVectors[3].z;
	//v5
	vertices[15] = resultVectors[2].x;
	vertices[16] = resultVectors[2].y;
	vertices[17] = resultVectors[2].z;
	//v6
	vertices[18] = resultVectors[4].x;
	vertices[19] = resultVectors[4].y;
	vertices[20] = resultVectors[4].z;
	//v7
	vertices[21] = resultVectors[5].x;
	vertices[22] = resultVectors[5].y;
	vertices[23] = resultVectors[5].z;
	//v8
	vertices[24] = resultVectors[6].x;
	vertices[25] = resultVectors[6].y;
	vertices[26] = resultVectors[6].z;
	//v9
	vertices[27] = resultVectors[4].x;
	vertices[28] = resultVectors[4].y;
	vertices[29] = resultVectors[4].z;
	//v10
	vertices[30] = resultVectors[7].x;
	vertices[31] = resultVectors[7].y;
	vertices[32] = resultVectors[7].z;
	//v11
	vertices[33] = resultVectors[6].x;
	vertices[34] = resultVectors[6].y;
	vertices[35] = resultVectors[6].z;
	//v12
	vertices[36] = resultVectors[0].x;
	vertices[37] = resultVectors[0].y;
	vertices[38] = resultVectors[0].z;
	//v13
	vertices[39] = resultVectors[1].x;
	vertices[40] = resultVectors[1].y;
	vertices[41] = resultVectors[1].z;
	//v14
	vertices[42] = resultVectors[5].x;
	vertices[43] = resultVectors[5].y;
	vertices[44] = resultVectors[5].z;
	//v15
	vertices[45] = resultVectors[4].x;
	vertices[46] = resultVectors[4].y;
	vertices[47] = resultVectors[4].z;
	//v16
	vertices[48] = resultVectors[5].x;
	vertices[49] = resultVectors[5].y;
	vertices[50] = resultVectors[5].z;
	//v17
	vertices[51] = resultVectors[0].x;
	vertices[52] = resultVectors[0].y;
	vertices[53] = resultVectors[0].z;
	//v18
	vertices[54] = resultVectors[0].x;
	vertices[55] = resultVectors[0].y;
	vertices[56] = resultVectors[0].z;
	//v19
	vertices[57] = resultVectors[3].x;
	vertices[58] = resultVectors[3].y;
	vertices[59] = resultVectors[3].z;
	//v20
	vertices[60] = resultVectors[7].x;
	vertices[61] = resultVectors[7].y;
	vertices[62] = resultVectors[7].z;
	//v21
	vertices[63] = resultVectors[7].x;
	vertices[64] = resultVectors[7].y;
	vertices[65] = resultVectors[7].z;
	//v22
	vertices[66] = resultVectors[4].x;
	vertices[67] = resultVectors[4].y;
	vertices[68] = resultVectors[4].z;
	//23
	vertices[69] = resultVectors[0].x;
	vertices[70] = resultVectors[0].y;
	vertices[71] = resultVectors[0].z;
	//24
	vertices[72] = resultVectors[1].x;
	vertices[73] = resultVectors[1].y;
	vertices[74] = resultVectors[1].z;
	//25
	vertices[75] = resultVectors[2].x;
	vertices[76] = resultVectors[2].y;
	vertices[77] = resultVectors[2].z;
	//26
	vertices[78] = resultVectors[6].x;
	vertices[79] = resultVectors[6].y;
	vertices[80] = resultVectors[6].z;
	//27
	vertices[81] = resultVectors[6].x;
	vertices[82] = resultVectors[6].y;
	vertices[83] = resultVectors[6].z;
	//28
	vertices[84] = resultVectors[5].x;
	vertices[85] = resultVectors[5].y;
	vertices[86] = resultVectors[5].z;
	//29
	vertices[87] = resultVectors[1].x;
	vertices[88] = resultVectors[1].y;
	vertices[89] = resultVectors[1].z;
	//30
	vertices[90] = resultVectors[3].x;
	vertices[91] = resultVectors[3].y;
	vertices[92] = resultVectors[3].z;
	//31
	vertices[93] = resultVectors[7].x;
	vertices[94] = resultVectors[7].y;
	vertices[95] = resultVectors[7].z;
	//32
	vertices[96] = resultVectors[6].x;
	vertices[97] = resultVectors[6].y;
	vertices[98] = resultVectors[6].z;
	//33
	vertices[99] = resultVectors[6].x;
	vertices[100] = resultVectors[6].y;
	vertices[101] = resultVectors[6].z;
	//34
	vertices[102] = resultVectors[2].x;
	vertices[103] = resultVectors[2].y;
	vertices[104] = resultVectors[2].z;
	//35
	vertices[105] = resultVectors[3].x;
	vertices[106] = resultVectors[3].y;
	vertices[107] = resultVectors[3].z;
}
