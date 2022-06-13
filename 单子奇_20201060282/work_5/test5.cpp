#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

int xc,yc,R;
void init(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,200,0,150);
}

void circlePrint(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    int x,y;
    double d;
    x=0;
    y=R;
    d=1.25-R;
    glBegin(GL_POINTS);
    glVertex2i(x+xc,y+yc);
    while(x<y)
    {
        if(d<=0)
            d=2*x+3+d;
        else
        {
            d=2*(x-y)+5+d;
            y--;
        }
        x++;
        glVertex2i(x+xc,y+yc);
        glVertex2i(y+xc,x+yc);
        glVertex2i(y+xc,-x+yc);
        glVertex2i(x+xc,-y+yc);
        glVertex2i(-x+xc,-y+yc);
        glVertex2i(-y+xc,-x+yc);
        glVertex2i(-x+xc,y+yc);
        glVertex2i(-y+xc,x+yc);
    }
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    scanf("%d",&xc);
    scanf("%d",&yc);
    scanf("%d",&R);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,300);
    glutCreateWindow("Example");

    init();
    glutDisplayFunc(circlePrint);

    glutMainLoop();

    return 0;
}