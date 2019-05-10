
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1000
#define SCREEN_DEPTH 1000

// models
#include "loadModels.c"

// glut functions
#include "glutFunctions.c"

int axis = 1, cx = 0, cy = 0, cz = 0;
int ax = 0, ay = 0, az = 0;
float theta[] = {0, 0, 0};

// idle
void moveAsteroid() {
  // ay++;
  az += 1;
  printf("%d\n", az);
  glutPostRedisplay();
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

void display() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();
  glRotatef(40, 1, 0, 0);

  // spaceship
  glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, -(SCREEN_HEIGHT / 2) + 100, -100);
    glScalef(0.25, 0.25, 0.075);
    glTranslatef(cx, cy, -10);
    glColor3f(1, 0, 1);
    plotModel('s');
  glPopMatrix();

  // asteroid
  glPushMatrix();
    glTranslatef(0, 0, -500);
    // glScalef(.1, .1, .1);
    glTranslatef(ax, ay, az);
    glColor3f(.17, .17, .17);
    plotModel('a');
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
  glutIdleFunc(moveAsteroid);
  
  glEnable(GL_DEPTH_TEST);
  glutMainLoop();

  return 0;
}
