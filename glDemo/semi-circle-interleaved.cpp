#include "semi-circle-interleaved.h"

struct CircleVertex {

	GLfloat		x, y;		// position
	GLubyte		r, g, b;	// colour

	CircleVertex(GLfloat x, GLfloat y, GLubyte r, GLubyte g, GLubyte b) {

		this->x = x;
		this->y = y;

		this->r = r;
		this->g = g;
		this->b = b;

	}
};

static CircleVertex vertices[] = {

	CircleVertex(-0.25f, 0.0f, 255, 0, 0),
	CircleVertex(-0.75f, 0.0f, 255, 0, 0),
	CircleVertex(-0.216506351f, 0.125f, 255, 0, 0),
	CircleVertex(-0.649519053f, 0.375f, 255, 0, 0),
	CircleVertex(-0.125, 0.216506351f, 255, 255, 0),
	CircleVertex(-0.375f, 0.649519053f, 255, 255, 0),
	CircleVertex(0.0f, 0.25f, 0, 255, 0),
	CircleVertex(0.0f, 0.75f, 0, 255, 0),
	CircleVertex(0.125f, 0.216506351f, 112, 231, 243),
	CircleVertex(0.375f, 0.649519053f, 112, 231, 243),
	CircleVertex(0.216506351f, 0.125f, 0, 0, 255),
	CircleVertex(0.649519053f, 0.375f, 0, 0, 255),
	CircleVertex(0.25f, 0.0f, 234, 53, 230),
	CircleVertex(0.75f, 0.0f, 234, 53, 230),
};

static GLubyte vertexes[] = {
	0, 1, 2,
	1, 2, 3,
	2, 3, 4,
	3, 4, 5,
	4, 5, 6,
	5, 6, 7,
	6, 7, 8,
	7, 8, 9,
	8, 9, 10,
	9, 10, 11,
	10, 11, 12,
	11, 12, 13
};

void drawSemiCircleInterleaved()
{
	// Declare the data type of the array
	glVertexPointer(2, GL_FLOAT, sizeof(CircleVertex), &(vertices[0].x));
	glColorPointer(3, GL_UNSIGNED_BYTE, sizeof(CircleVertex), &(vertices[0].r));

	// Declare which arrays are needed for the semi-circle object
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	// Draw the object
	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 14);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, vertexes);
}