#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define left 1
#define right 2
#define bottom 4
#define top 8
#define number 5

class LineClass
{
public:
    GLfloat x1,y1,x2,y2;
    GLfloat x1_init,y1_init,x2_init,y2_init;
}lines[number];

GLfloat xleft=30,xright=70,ytop=70,ybottom=30;

GLint encode(GLfloat x,GLfloat y)
{
    GLint code = 0;
    if(x<xleft) code |= left;
    if(x>xright) code |= right;
    if(y>ytop) code |= top;
    if(y<ybottom) code |= bottom;
    return code;
}

void pointChange()
{
    GLfloat x,y,x0,y0;
    for(GLint i=0;i<number;i++)
    {
        lines[i].x1=2+i*9;
        lines[i].x2=50+i*i*3;
        lines[i].y1=100-i*i*i;
        lines[i].y2=19+i*i*4;

        if(lines[i].x1 == lines[i].x2)
            lines[i].x1++;
        if(lines[i].y1 == lines[i].y2)
            lines[i].y1++;

        lines[i].x1_init=lines[i].x1;
        lines[i].x2_init=lines[i].x2;
        lines[i].y1_init=lines[i].y1;
        lines[i].y2_init=lines[i].y2;

        GLint code1,code2;
        code1=encode(lines[i].x1,lines[i].y1);
        code2=encode(lines[i].x2,lines[i].y2);

        GLint code;

        while(code1!=0 || code2!=0)
        {
            if(code1&code2)
            {
                lines[i].x1=0;
                lines[i].x2=0;
                lines[i].y1=0;
                lines[i].y2=0;
                break;
            }
            if(code1!=0)
                code = code1;
            else
                code = code2;

            y0=lines[i].y1;
            x0=lines[i].x1;

            if(code&left)
            {
                x=xleft;
                y=y0-(x0-x)*(lines[i].y1-lines[i].y2)/(lines[i].x1-lines[i].x2);
            }
            else if(code & right)
            {
                x=xright;
                y=y0-(x0-x)*(lines[i].y1-lines[i].y2)/(lines[i].x1-lines[i].x2);
            }
            else if(code & bottom)
            {
                y=ybottom;
                x=x0-(y0-y)*(lines[i].x1-lines[i].x2)/(lines[i].y1-lines[i].y2);
            }
            else if(code & top)
            {
                y=ytop;
                x=x0-(y0-y)*(lines[i].x1-lines[i].x2)/(lines[i].y1-lines[i].y2);
            }
            else
                printf("´íÎó!");

            if(code==code1)
            {
                lines[i].x1=x;
                lines[i].y1=y;
                code1 = encode(lines[i].x1,lines[i].y1);
            }
            else
            {
                lines[i].x2=x;
                lines[i].y2=y;
                code2 = encode(lines[i].x2,lines[i].y2);
            }
        }
    }

}

void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,100.0,0.0,100.0);
    pointChange();
}

void displayFcn()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glPointSize(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xleft,ybottom);
    glVertex2f(xright,ybottom);
    glVertex2f(xright,ytop);
    glVertex2f(xleft,ytop);
    glEnd();
    glFlush();

    for(GLint i=0;i<number;i++)
    {
        glColor3f(1.0,0.0,0.0);
        glPointSize(2);
        glBegin(GL_LINES);
        glVertex2f(lines[i].x1_init,lines[i].y1_init);
        glVertex2f(lines[i].x2_init,lines[i].y2_init);
        glEnd();
        glFlush();

        glColor3f(0.0,0.0,0.0);
        glPointSize(2);
        glBegin(GL_LINES);
        glVertex2f(lines[i].x1,lines[i].y1);
        glVertex2f(lines[i].x2,lines[i].y2);
        glEnd();
        glFlush();
    }
}

int main(int argc,char * argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(400,400);
    glutCreateWindow("example");
    init();
    glutDisplayFunc(displayFcn);
    glutMainLoop();
    return 0;
}


