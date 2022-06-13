#include <windows.h>
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

inline int around(const float a) {
	return int(a + 0.5);
}

void setPixel(GLint x,GLint y){
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void lineDDA() {
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.4,0.2);
	
	int x0 = 180, y0 = 15, xEnd = 10, yEnd = 145;
	int dx = xEnd - x0, dy = yEnd - y0, steps, k;
	float xIncreament, yIncreament, x = x0, y = y0;

	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xIncreament = float(dx) / float(steps);
	yIncreament = float(dy) / float(steps);

	setPixel(around(x),around(y));
	for (k = 0; k < steps; k++) {
		x += xIncreament;
		y += yIncreament;
		setPixel(around(x),around(y));
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
	glutDisplayFunc(lineDDA);
    glutMainLoop();
    return 0;
}