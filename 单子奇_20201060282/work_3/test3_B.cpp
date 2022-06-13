#include<Windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>

void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}

void Bres2() {//改进bresenham算法，用2e*dx
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.2, 0.2, 0.2);

	int x0 = 10, y0 = 15, xEnd = 180, yEnd = 145;
	int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
	int e = -dx;

	int x, y;
	if (x0 > xEnd) {
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	}
	else {
		x = x0;
		y = y0;
	}
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	while (x < xEnd) {

		e = e + 2 * dy;
		if (e > 0) {
			x++;
			y++;
			e = e - 2 * dx;
		}
		else {
			x++;
		}
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
	}

	glFlush();

}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("An Example OpenGL Program");
    init();
	glutDisplayFunc(Bres2);
    glutMainLoop();
    return 0;
}
