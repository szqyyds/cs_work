#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

static int year = 0, day = 0;
static int longitude = 200, latitude=200;

void init(void) 
{
   glClearColor (1.0, 1.0, 1.0, 0.0);
   //glClearDepth(1.0);
   glShadeModel (GL_SMOOTH);    //������ڲ������ɫͨ���Զ���ζ�����ɫ��ֵ�������൱��gouraud��������
   //glShadeModel (GL_FLAT);   //������ڲ����е�ʹ����ͬ����ɫ

   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LESS);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


   GLfloat mat_diffuse[] = { 0.96, 0.23, 0.11, 1.0 };  //������ϵ������ӦRGBA�ĸ�������A�����ڻ�Ͽ�(glBlend)������Ч 

   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; //���淴��ϵ��,��ӦRGBA�ĸ�������A�����ڻ�Ͽ�������Ч   
   GLfloat mat_shininess[] = { 50.0 };  
	  
 
   glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_diffuse);//���û�����ϵ�����������ϵ��     
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);//set material ����ⷴ��  
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);//���ò��Ϸ���ָ��  

   glEnable(GL_LIGHTING);  
   glEnable(GL_LIGHT0);  
  
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT );
    
   GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };//���һ������Ϊ0����ʾ��Դ������Զ��  
   //GLfloat light_position[] = { 1.0, -1, 0.0, 1.0 };//�ֲ���Դ  
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);//��Դλ��  

   glColor3f (1.0, 1.0, 1.0); //���ù�Դ�󣬲���ʹ����ɫ������������ɫ
   
   glMatrixMode(GL_MODELVIEW);  //ʹ��ģ����ͼ����ջ�������ļ��α任      
   glPushMatrix();              //������������ϵ���۲�����ϵ�ı任����
   
   glutSolidTeapot(1.0);

   glPopMatrix();                //�ָ���������ϵ���۲�����ϵ�ı任����
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);  //ʹ������С�����봰�ڵ���ʾ�����Сһ��
   glMatrixMode(GL_MODELVIEW); //ʹ��ģ����ͼ����ջ
   glLoadIdentity();
   
/* gluLookAt �����趨�˹۲��ӵ㣬�͹۲췽��
����ԭ�ͣ�gluLookAt(GLdoble eyex,GLdouble eyey,GLdouble eyez,GLdouble centerx,GLdouble centery,GLdouble centerz,GLdouble upx,GLdouble upy,GLdouble upz);
��ѡȡ eyex,eyey, eyez����Ϊԭ�㣨�۲�����ϵ�����꣨����������ϵ����ʾ�ģ�����
Ȼ��centerx, centery,centerz��ָ���˹۲췽�򣨣���ķ����򣩣���
upx,upy,upz��ָ���ˣ����������Ľ��Ʒ�������һ���ͣ��᷽��������������ͨ����ص����㣬�ҵ������ģ���������򣬴Ӷ�Ҳ�����ҵ��������������Ҫ����ͨ�������Ĳ�������㣩��
ʹ����gluLookAt������ʵ�����ǽ����˴���������ϵ���۲�����ϵ��ת���ľ��󣬺����ͶӰ�任���ڹ۲�����ϵ�½���
*/
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); 

   glMatrixMode (GL_PROJECTION);//ʹ��ͶӰ����ջ��׼���趨ͶӰ����
   glLoadIdentity ();//��ʼ��ͶӰ����Ϊ��λ����

// gluPerspective���������Ӿ��壨�ü���̨�����ĸ������ĺ����ͼ��
// �ú���ʵ���ϻ�����ĸ�������������ͶӰ�任��͸��ͶӰ����
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 0.5, 30.0);  
}



int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow("Teapot");
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
