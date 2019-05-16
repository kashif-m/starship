
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include <stdbool.h>

bool showStarship = true;
int count = 0, count1 = 0, CURRENT_WIDTH = 1, CURRENT_HEIGHT = 1;

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1000
#define SCREEN_DEPTH 1000

#include "textPrinter.c"
#include "glutFunctions.c"
#include "audio.c"
#include "loadModels.c"
#include "starship.c"
#include "asteroid.c"
#include "bullet.c"
#include "collision.c"
#include "star.c"
#include "plotter.c"

void display() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  if(showStarship) {
    plotAsteroids(&count);
    plotStarship();
    starshipWire();
    plotBullet();
  } else {
    glEnable(GL_LIGHT3);
    drawString(0 - 100, 0, -500, "DEATH IN OUTER SPACE");
    glEnable(GL_LIGHT3);
  }
  plotStars(&count1);

  glFlush();
  glutSwapBuffers();

  count++;
  count1++;
}

int main (int argc, char *argv[]) {

  // audio
  startAudio();

  // load models
  loadModel(&asteroid, "Asteroid1.obj");
  loadModel(&starship, "StarshipNew.obj");

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
  glutPassiveMotionFunc(moveStarship);
  glutIdleFunc(moveStar);
  glutMouseFunc(fireRounds);
  
  glutMainLoop();

  return 0;
}

// REFERENCE FOR AUDIO
// https://cboard.cprogramming.com/linux-programming/105923-c-program-play-sound.html
