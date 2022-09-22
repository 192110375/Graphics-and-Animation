#include<GL/glut.h>
#include<math.h>
double parr[8];
void init()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0,0,0,1);
glColor3f(1,0,1);
gluOrtho2D(-500,500,-500,500); // Left,right,bottom,top
// Polygon Defaut
parr[0] = 10; //x
parr[1] = 10; //y
parr[2] = 200;
parr[3] = 10;
parr[4] = 150;
parr[5] = 150;
}
void polygon()
{
glColor3f(1,0,0);
glBegin(GL_LINE_LOOP);
glVertex2f(parr[0],parr[1]);
glVertex2f(parr[2],parr[3]);
glVertex2f(parr[4],parr[5]);
glEnd();
glFlush();
}
void drawCorodinates()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,1,1);
glPointSize(4);
glBegin(GL_LINES);
glVertex2f(-500,0);
glVertex2f(500,0);
glVertex2f(0,500);glVertex2f(0,-500);
glEnd();
glColor3f(1,0,0);
glBegin(GL_POINTS);
glVertex2f(0,0);
glEnd();
glFlush();
}
// Reflection About Origin
void reflection_origin()
{
for(int i=0;i<6;i++)
{
parr[i] = -parr[i];
}
polygon();
}
// Reflection About X-axis
void reflection_x()
{
for(int i=1;i<6;i=i+2)
{
parr[i] = -parr[i];
}
polygon();
}
// Reflection About Y-axis
void reflection_y()
{
for(int i=0;i<6;i=i+2)
{
parr[i] = -parr[i];
}
polygon();
}
void menu(int ch)
{
drawCorodinates();
switch(ch)
{case 1: polygon();
break;
case 2: reflection_origin();
break;
case 3: reflection_x();
break;
case 4: reflection_y();
break;
}
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("2D Transformation");
init();
glutDisplayFunc(drawCorodinates);
glutCreateMenu(menu);
glutAddMenuEntry("1 Display Polygon",1);
glutAddMenuEntry("2 Reflection About Origin",2);
glutAddMenuEntry("3 Reflection About X-Axis",3);
glutAddMenuEntry("4 Reflection About Y-Axiis",4);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
return 0;
}
