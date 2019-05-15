
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <time.h>
#include <unistd.h>

int count = 0, count1 = 0, CURRENT_WIDTH = 0, CURRENT_HEIGHT = 0;
float theta[] = {0, 0, 0};

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1000
#define SCREEN_DEPTH 1000

#include "glutFunctions.c"
#include "audio.c"
#include "loadModels.c"
#include "star.c"
#include "asteroid.c"
#include "starship.c"

void display() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
    asteroids(&count);
  glDisable(GL_LIGHT0);
  glDisable(GL_LIGHT1);

  plotStarship();

  glEnable(GL_LIGHT2);
  glEnable(GL_LIGHT3);
  glEnable(GL_LIGHT4);
    glDisable(GL_POLYGON_OFFSET_FILL);
      glLineWidth(1.5);
      plotStarshipWire();
    glEnable(GL_POLYGON_OFFSET_FILL);
  glPolygonOffset(1.0, 1.0);
  glDisable(GL_LIGHT2);
  glDisable(GL_LIGHT3);
  glDisable(GL_LIGHT4);

  glEnable(GL_LIGHT5);
    stars(&count1);
  glDisable(GL_LIGHT5);

  glFlush();
  glutSwapBuffers();

  count++;
  count1++;
}

int main (int argc, char *argv[]) {

  // audio
  // startAudio();

  // load models
  loadModel(&starship, "Starship.obj");
  loadModel(&asteroid, "Asteroid1.obj");

  srand(time(0));
  spawnAsteroid(0);
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
  glutSpecialFunc(moveStarship);
  glutIdleFunc(moveAsteroid);
  
  glutMainLoop();

  return 0;
}

// REFERENCE FOR AUDIO
// https://cboard.cprogramming.com/linux-programming/105923-c-program-play-sound.html
