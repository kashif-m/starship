
#define MAX_ASTEROIDS 100
#define MIN_SPEED_ASTEROID 10
#define MAX_SPEED_ASTEROID 20
#define SPAWN_FREQUENCY_ASTEROID 50

int ASTEROID_COUNT = 0;

struct Asteroid {
  int tx, ty, tz,
    rx, ry, rz,
    speed, done;
  float sx, sy, sz;
  int cx, cy, cz,
    sizeX, sizeY, sizeZ;
};

struct Asteroid A[MAX_ASTEROIDS];

void moveAsteroid() {

  int i;
  for(i = 0; i < ASTEROID_COUNT; i++) {
    A[i].tz += A[i].speed;
    A[i].cz += A[i].speed;
    if(A[i].tz > -NEAR_VAL)
      A[i].done = 1;
    if(A[i].rx > 360)
      A[i].rx = 0;
    A[i].rx += 5;
  }
}

void initialise(struct Asteroid* a, int x, int y, int z, float sx, float sy, float sz, int speed) {

  a->done = 0;
  a->rx = 0;
  a->speed = 40;

  a->tx = x;
  a->ty = y;
  a->tz = z;
  
  a->sx = sx;
  a->sy = sy;
  a->sz = sz;

  a->sizeX = asteroid.sizeX * sx;
  a->sizeY = asteroid.sizeY * sy;
  a->sizeZ = asteroid.sizeZ * sz;

  a->cx = x;
  a->cy = y;
  a->cz = z + a->sizeZ / 2;
}

void plotAsteroid(struct Asteroid a) {

  glPushMatrix();
    glLoadIdentity();
    glTranslatef(a.tx, a.ty, a.tz);
    glScalef(a.sx, a.sy, a.sz);
    glRotatef(a.rx, 1, 0, 0);
    glColor3f(.17, .17, .17);
    plotModel(&asteroid, 'P');
  glPopMatrix();
}

void spawnAsteroid(int i) {

  int x, y, z, speed;
  x = (rand() % CURRENT_WIDTH + 1) - (CURRENT_WIDTH / 2);
  y = (rand() % CURRENT_HEIGHT + 1) - (CURRENT_HEIGHT / 2);
  z = -FAR_VAL;
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
