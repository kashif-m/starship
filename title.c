
#include<GL/glut.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1000

void drawString(float x, float y, float z, char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
	{   
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}


void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.5);
	drawString(SCREEN_WIDTH / 3 + 100, SCREEN_HEIGHT-50, 0.0, "CAMBRIDGE INSTITUTE OF TECHNOLOGY");
	glFlush();
}

void init()
{
	glClearColor(1,1,1,0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,SCREEN_WIDTH,0,SCREEN_HEIGHT);
}

void main(int argc, char* argv[]) {

	glutInit(&argc, argv);
  glutInitWindowPosition(10, 10);
  glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("StarShip 3D Intro"); 
  init();
  glutDisplayFunc(display);
  // glutKeyboardFunc(exit);
  glutMainLoop();
}
