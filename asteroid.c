
#define MAX_ASTEROIDS 10
#define ASTEROID_SPEED 10
#define SPAWN_FREQUENCY 100

int ASTEROID_COUNT = 0;

struct asteroid {
  int tx, ty, tz,
    rx, ry, rz;
  int done;
};

struct asteroid A[MAX_ASTEROIDS];

void initialise(struct asteroid* a, int x, int y, int z) {
  a->tx = x; a->ty = y; a->tz = z;
  a->done = 0;
}

void plotAsteroid(struct asteroid a) {

  glPushMatrix();
    glScalef(.5, .5, .5);
    glTranslatef(a.tx, a.ty, a.tz);
    glRotatef(a.rx, 1, 0, 0);
    glColor3f(.17, .17, .17);
    plotModel('a');
  glPopMatrix();
}

// idle
void moveAsteroid() {

  int i;
  for(i = 0; i < ASTEROID_COUNT; i++) {
    A[i].tz += ASTEROID_SPEED;
    if(A[i].tz > -NEAR_VAL)
      A[i].done = 1;
    if(A[i].rx == 360)
      A[i].rx = 0;
    A[i].rx += 5;
  }
  glutPostRedisplay();
}

void spawnAsteroid(int i) {

  int x, y, z;

  x = (rand() % SCREEN_WIDTH*3 + 1) - (SCREEN_WIDTH*3 / 2);
  y = (rand() % SCREEN_HEIGHT*3 + 1) - (SCREEN_HEIGHT*3 / 2);
  z = -FAR_VAL - 100;

  initialise(&A[i], x, y, z);
  ASTEROID_COUNT++;
}

void asteroids(int* count) {

  int i;
  if(*count == SPAWN_FREQUENCY && ASTEROID_COUNT < MAX_ASTEROIDS) {
    spawnAsteroid(ASTEROID_COUNT);
    *count = 0;
  }

  for(i = 0; i < ASTEROID_COUNT; i++) {
    
    if(!A[i].done)
      plotAsteroid(A[i]);
    else {
      ASTEROID_COUNT--;
      spawnAsteroid(i);
    }
  }
}
