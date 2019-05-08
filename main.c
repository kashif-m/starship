
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>

// models
#include "loadModels.c"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000
#define SCREEN_DEPTH 1000

int axis = 1, cx = 0, cy = 0, cz = 0;
float theta[] = {0, 0, 0};

void init() {

   GLfloat mat_ambient[] = { 0, 1, 1, 0.0 };
   GLfloat mat_shininess[] = { 5.0 };
   GLfloat light_position[] = { 0.0, 100.0, 100.0, 1.0 };

   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_ambient);
   glMaterialfv(GL_BACK, GL_DIFFUSE, mat_ambient);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}

void special(int key, int X, int Y) {

  switch(key) {
    case GLUT_KEY_UP:
      cy += 50;
      // axis 1= 0;
      break;

    case GLUT_KEY_DOWN:
      cy -= 50;
      // axis 1= 1;
      break;

    case GLUT_KEY_RIGHT:
      cx -= 50;
      // axis 1= 2;
      break;
    
    case GLUT_KEY_LEFT:
      cx += 50;
      break;

    default:
      break;
  }

  glutPostRedisplay();
}


void rotate() {

  theta[axis] += 1;
  if(theta[axis] == 360)
    theta[axis] = 0;
  glutPostRedisplay();
}

void reshape(int w, int h) {

  glClearColor(.1, .1, .1, 1);
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  float negX = -w / 2, posX = w / 2,
        negY = -h / 2, posY = h / 2;

  glOrtho(negX, posX, negY, posY, -SCREEN_DEPTH / 2, SCREEN_DEPTH / 2);
  glMatrixMode(GL_MODELVIEW);
}

void display() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  // spaceship
  glPushMatrix();
    glRotatef(40, 1, 0, 0);
    glRotatef(180, 0, 1, 0);
    glRotatef(0, 0, 0, 1);
    glTranslatef(0, -(SCREEN_HEIGHT / 2) + 200, 0);
    glScalef(0.15, 0.15, 0.15);
    glTranslatef(cx, cy, cz);

    glColor3f(0, 0, 0);
    plotSpaceShip();
  glPopMatrix();

  // asteroid
  glPushMatrix();
    glTranslatef(0, 100, -500);
    glScalef(.1, .1, .1);
    glColor3f(1, 0, 0);
    plotAsteroid();
  glPopMatrix();

  glFlush();
  glutSwapBuffers();
}

int main (int argc, char *argv[]) {

  // load models
  loadSpaceShip();
  loadAsteroid();

  glutInit(&argc, argv);

  // window
  glutInitWindowPosition(10, 10);
  glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("StarShip 3D");
 
  init();

  // glut functions
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutSpecialFunc(special);
  glutIdleFunc(rotate);
  
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();

  return 0;
}
