
#define MAX_ASTEROIDS 10
#define MIN_SPEED 20
#define SPAWN_FREQUENCY 100

int ASTEROID_COUNT = 0;

struct asteroid {
  int tx, ty, tz,
    rx, ry, rz,
    speed, done;
  float sx, sy, sz;
};

struct asteroid A[MAX_ASTEROIDS];

// idle function
void moveAsteroid() {

  if(theta[0] > 360)
    theta[0] = 0;
  theta[0] += 1;
  int i;
  for(i = 0; i < ASTEROID_COUNT; i++) {
    A[i].tz += A[i].speed;
    if(A[i].tz > -NEAR_VAL)
      A[i].done = 1;
    if(A[i].rx > 360)
      A[i].rx = 0;
    A[i].rx += 5;
  }
  glutPostRedisplay();
}

void initialise(struct asteroid* a, int x, int y, int z, float sx, float sy, float sz, int speed) {
  a->tx = x; a->ty = y; a->tz = z;
  a->done = 0;
  a->rx = 0;
  a->sx = sx;
  a->sy = sy;
  a->sz = sz;
  a->speed = speed;
}

void plotAsteroid(struct asteroid a) {

  glPushMatrix();
    glScalef(a.sx, a.sy, a.sz);
    glTranslatef(a.tx, a.ty, a.tz);
    glRotatef(a.rx, 1, 0, 0);
    glColor3f(.17, .17, .17);
    plotModel('a');
  glPopMatrix();
}

void spawnAsteroid(int i) {

  int x, y, z, speed;
  x = (rand() % SCREEN_WIDTH*3 + 1) - (SCREEN_WIDTH*3 / 2);
  y = (rand() % SCREEN_HEIGHT*3 + 1) - (SCREEN_HEIGHT*3 / 2);
  z = -FAR_VAL - 100;
  speed = (rand() % 40 + 1);
  if(speed < MIN_SPEED)
    speed = MIN_SPEED;

  float sx, sy, sz;
  sx = ((float)rand()) / ((float)RAND_MAX) / 2.0 + 0.3;
  sy = ((float)rand()) / ((float)RAND_MAX) / 2.0 + 0.3;
  sz = ((float)rand()) / ((float)RAND_MAX) / 2.0 + 0.3;

  initialise(&A[i], x, y, z, sx, sy, sz, speed);
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
