
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <time.h>
#include <unistd.h>

int count = 0, CURRENT_WIDTH = 0, CURRENT_HEIGHT = 0;
float theta[] = {0, 0, 0};

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1000
#define SCREEN_DEPTH 1000

#include "audio.c"
#include "loadModels.c"
#include "glutFunctions.c"
#include "asteroid.c"
#include "spaceship.c"

void display() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  spaceship();
  asteroids(&count);

  glFlush();
  glutSwapBuffers();

  count++;
}

int main (int argc, char *argv[]) {

  // audio
  // startAudio();

  // load models
  loadSpaceShip();
  loadAsteroid();

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
  glutSpecialFunc(moveSpaceship);
  glutIdleFunc(moveAsteroid);
  
  glutMainLoop();

  return 0;
}

// REFERENCE FOR AUDIO
// https://cboard.cprogramming.com/linux-programming/105923-c-program-play-sound.html
