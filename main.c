
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include <time.h>
#include <unistd.h>

int axis = 1, cx = 0, cy = 0, cz = 0, count = 0;
int ax = 0, ay = 0, az = 0;
float theta[] = {0, 0, 0};

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1000
#define SCREEN_DEPTH 1000

#include "loadModels.c"
#include "glutFunctions.c"
#include "asteroid.c"

void special(int key, int X, int Y) {

  switch(key) {
    case GLUT_KEY_UP:
      if(cy < SCREEN_HEIGHT)
        cy += 50;
      break;

    case GLUT_KEY_DOWN:
      if(cy > -SCREEN_HEIGHT / 4)
        cy -= 50;
      break;

    case GLUT_KEY_RIGHT:
      if(cx > (-SCREEN_WIDTH / 2) - 150)
        cx -= 50;
      break;
    
    case GLUT_KEY_LEFT:
      if(cx < (SCREEN_WIDTH / 2) + 150)
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

  // spaceship
  glPushMatrix();
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, -(SCREEN_HEIGHT / 2) + 100, NEAR_VAL + 100);
    glTranslatef(cx, cy, 0);
    glScalef(0.25, 0.25, 0.045);
    glColor3f(1, 0, 1);
    plotModel('s');
  glPopMatrix();

  // asteroid
  count++;
  asteroids(&count);

  glFlush();
  glutSwapBuffers();
}

void killAudio() {
  system("kill -9 ");
}

void startAudio() {

  pid_t x;
  x = fork();

  if (x < 0)
    puts("ERR: fork failure");
  else if (x == 0)
    execlp("mpg123", "mpg123", "-q", "./lpwu.mp3", 0);
}

int main (int argc, char *argv[]) {

  // audio
  startAudio();

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
  glutSpecialFunc(special);
  glutIdleFunc(moveAsteroid);
  
  glutMainLoop();

  return 0;
}

// REFERENCE FOR AUDIO
// https://cboard.cprogramming.com/linux-programming/105923-c-program-play-sound.html
