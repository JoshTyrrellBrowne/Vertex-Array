#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <Vector3.h>
#include <Matrix3.h>
#include <MyVector3.h>

using namespace std;
using namespace sf;
using namespace gpp;

class Game
{
public:
	Game();
	~Game();
	void run();

	// cube corners
	MyVector3 v1{ 1.0f, 1.0f, -5.0f };
	MyVector3 v2{ -1.0f, 1.0f, -5.0f };
	MyVector3 v3{ -1.0f, -1.0f, -5.0f };
	MyVector3 v4{ 1.0f, -1.0f, -5.0f };

	MyVector3 v5{ 1.0f, 1.0f, -6.0f };
	MyVector3 v6{ -1.0f, 1.0f, -6.0f };
	MyVector3 v7{ -1.0f, -1.0f, -6.0f };
	MyVector3 v8{ 1.0f, -1.0f, -6.0f };

	MyVector3 cubeCorners[8];

private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();

	void checkKeyPress();

	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
};