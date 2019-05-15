
#define MAX_ASTEROIDS 10
#define MIN_SPEED_ASTEROID 20
#define MAX_SPEED_ASTEROID 35
#define SPAWN_FREQUENCY_ASTEROID 100

int ASTEROID_COUNT = 0;

struct Asteroid {
  int tx, ty, tz,
    rx, ry, rz,
    speed, done;
  float sx, sy, sz;
};

struct Asteroid A[MAX_ASTEROIDS];

// idle function
void moveAsteroid() {

  moveStar();
  moveBullet();
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

void initialise(struct Asteroid* a, int x, int y, int z, float sx, float sy, float sz, int speed) {
  a->tx = x; a->ty = y; a->tz = z;
  a->done = 0;
  a->rx = 0;
  a->sx = sx;
  a->sy = sy;
  a->sz = sz;
  a->speed = speed;
}

void plotAsteroid(struct Asteroid a) {

  glPushMatrix();
    glScalef(a.sx, a.sy, a.sz);
    glTranslatef(a.tx, a.ty, a.tz);
    glRotatef(a.rx, 1, 0, 0);
    glColor3f(.17, .17, .17);
    plotModel(&asteroid, 'P');
  glPopMatrix();
}

void spawnAsteroid(int i) {

  int x, y, z, speed;
  x = (rand() % SCREEN_WIDTH*3 + 1) - (SCREEN_WIDTH*3 / 2);
  y = (rand() % SCREEN_HEIGHT*3 + 1) - (SCREEN_HEIGHT*3 / 2);
  z = -FAR_VAL - 100;
  speed = (rand() % MAX_SPEED_ASTEROID + 1);
  if(speed < MIN_SPEED_ASTEROID)
    speed = MIN_SPEED_ASTEROID;

  float sx, sy, sz;
  sx = ((float)rand()) / ((float)RAND_MAX) / 2.0 + 0.3;
  sy = ((float)rand()) / ((float)RAND_MAX) / 2.0 + 0.3;
  sz = ((float)rand()) / ((float)RAND_MAX) / 2.0 + 0.3;

  initialise(&A[i], x, y, z, sx, sy, sz, speed);
  ASTEROID_COUNT++;
}

void asteroids(int* count) {

  int i;
  if(*count == SPAWN_FREQUENCY_ASTEROID && ASTEROID_COUNT < MAX_ASTEROIDS) {
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
