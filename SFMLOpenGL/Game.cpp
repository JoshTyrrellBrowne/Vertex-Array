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

	glDrawElements(GL_TRIANGLES, 108, GL_UNSIGNED_INT, &vertex_index);

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
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		// vector addition way..
	//		/*displacementVectors[i] = displacementVectors[i] + MyVector3(0,0.01,0);*/

	//		// Matrix Translation way..
	//		if (displacementVectors[i].z >= 0)// if z < 0 the translation will be opposite
	//		{
	//			displacementVectors[i] = MyMatrix3::translation(MyVector3(0, 0.01, 0)) * displacementVectors[i];
	//		}
	//		else
	//		{
	//			displacementVectors[i] = MyMatrix3::translation(MyVector3(0, -0.01, 0)) * displacementVectors[i];
	//		}
	//	}
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		// vector addition way..
	//		/*displacementVectors[i] = displacementVectors[i] + MyVector3(0, -0.01, 0);*/

	//		// Matrix Translation way..
	//		if (displacementVectors[i].z >= 0)// if z < 0 the translation will be opposite
	//		{
	//			displacementVectors[i] = MyMatrix3::translation(MyVector3(0, -0.01, 0)) * displacementVectors[i];
	//		}
	//		else
	//		{
	//			displacementVectors[i] = MyMatrix3::translation(MyVector3(0, 0.01, 0)) * displacementVectors[i];
	//		}
	//	}
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		// vector addition way..
	//		/*displacementVectors[i] = displacementVectors[i] + MyVector3(0.01, 0, 0);*/

	//		// Matrix Translation way..
	//		if (displacementVectors[i].z >= 0)// if z < 0 the translation will be opposite
	//		{
	//			displacementVectors[i] = MyMatrix3::translation(MyVector3(0.01, 0, 0)) * displacementVectors[i];
	//		}
	//		else
	//		{
	//			displacementVectors[i] = MyMatrix3::translation(MyVector3(-0.01, 0, 0)) * displacementVectors[i];
	//		}
	//	}
	//}
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//{
	//	for (int i = 0; i < 8; i++)
	//	{
	//		// vector addition way..
	//		/*displacementVectors[i] = displacementVectors[i] + MyVector3(-0.01, 0, 0);*/

	//		// Matrix Translation way..
	//		if (displacementVectors[i].z >= 0)	// if z < 0 the translation will be opposite
	//		{
	//			displacementVectors[i] = MyMatrix3::translation(MyVector3(-0.01, 0, 0)) * displacementVectors[i];
	//		}
	//		else
	//		{
	//			displacementVectors[i] = MyMatrix3::translation(MyVector3(0.01, 0, 0)) * displacementVectors[i];
	//		}
	//	}
	//}
	
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
	vertices[48] = cubeCorners[5].x;
	vertices[49] = cubeCorners[5].y;
	vertices[50] = cubeCorners[5].z;
	//v17
	vertices[51] = cubeCorners[0].x;
	vertices[52] = cubeCorners[0].y;
	vertices[53] = cubeCorners[0].z;
	//v18
	vertices[54] = cubeCorners[0].x;
	vertices[55] = cubeCorners[0].y;
	vertices[56] = cubeCorners[0].z;

	//v19
	vertices[57] = cubeCorners[3].x;
	vertices[58] = cubeCorners[3].y;
	vertices[59] = cubeCorners[3].z;
	//v20
	vertices[60] = cubeCorners[7].x;
	vertices[61] = cubeCorners[7].y;
	vertices[62] = cubeCorners[7].z;
	//v21
	vertices[63] = cubeCorners[7].x;
	vertices[64] = cubeCorners[7].y;
	vertices[65] = cubeCorners[7].z;
	//v22
	vertices[66] = cubeCorners[4].x;
	vertices[67] = cubeCorners[4].y;
	vertices[68] = cubeCorners[4].z;

	//23
	vertices[69] = cubeCorners[0].x;
	vertices[70] = cubeCorners[0].y;
	vertices[71] = cubeCorners[0].z;
	//24
	vertices[72] = cubeCorners[1].x;
	vertices[73] = cubeCorners[1].y;
	vertices[74] = cubeCorners[1].z;
	//25
	vertices[75] = cubeCorners[2].x;
	vertices[76] = cubeCorners[2].y;
	vertices[77] = cubeCorners[2].z;
	//26
	vertices[78] = cubeCorners[6].x;
	vertices[79] = cubeCorners[6].y;
	vertices[80] = cubeCorners[6].z;

	//27
	vertices[81] = cubeCorners[6].x;
	vertices[82] = cubeCorners[6].y;
	vertices[83] = cubeCorners[6].z;
	//28
	vertices[84] = cubeCorners[5].x;
	vertices[85] = cubeCorners[5].y;
	vertices[86] = cubeCorners[5].z;
	//29
	vertices[87] = cubeCorners[1].x;
	vertices[88] = cubeCorners[1].y;
	vertices[89] = cubeCorners[1].z;
	//30
	vertices[90] = cubeCorners[3].x;
	vertices[91] = cubeCorners[3].y;
	vertices[92] = cubeCorners[3].z;

	//31
	vertices[93] = cubeCorners[7].x;
	vertices[94] = cubeCorners[7].y;
	vertices[95] = cubeCorners[7].z;
	//32
	vertices[96] = cubeCorners[6].x;
	vertices[97] = cubeCorners[6].y;
	vertices[98] = cubeCorners[6].z;
	//33
	vertices[99] = cubeCorners[6].x;
	vertices[100] = cubeCorners[6].y;
	vertices[101] = cubeCorners[6].z;
	//34
	vertices[102] = cubeCorners[2].x;
	vertices[103] = cubeCorners[2].y;
	vertices[104] = cubeCorners[2].z;
	//35
	vertices[105] = cubeCorners[3].x;
	vertices[106] = cubeCorners[3].y;
	vertices[107] = cubeCorners[3].z;
}
