#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>

class Vector
{
public:
	Vector(GLfloat X, GLfloat Y, GLfloat Z) {
		this->x = X;
		this->y = Y;
		this->z = Z;
	}

	void somaX(int I) {
		this->x+=I;
	}
	GLfloat getX() {
		return this->x;
	}
	void somaY(int I) {
		this->y += I;
	}
	GLfloat getY() {
		return this->y;
	}
	void somaZ(int I) {
		this->z += I;
	}
	GLfloat getZ() {
		return this->z;
	}
private:
	GLfloat x; GLfloat y; GLfloat z;
};
