
#define MAX_STARS 500
#define MIN_SPEED_STAR 50
#define SPAWN_FREQUENCY_STAR 1
#define MAX_RADIUS 3

int STAR_COUNT = 0;

struct star {
  int tx, ty, tz,
    speed, done, radius;
};

struct star S[MAX_STARS];

void moveStar() {

  int i;
  for(i = 0; i < STAR_COUNT; i++) {
    S[i].tz += S[i].speed;
    if(S[i].tz > -NEAR_VAL)
      S[i].done = 1;
  }
}

void initialiseStar(struct star* s, int x, int y, int z, int radius, int speed) {
  s->tx = x; s->ty = y; s->tz = z;
  s->done = 0;
  s->radius = radius;
  s->speed = speed;
}

void plotStar(struct star s) {

  glPushMatrix();
    glTranslatef(s.tx, s.ty, s.tz);
    glColor3f(1, 0, 0);
    glutSolidSphere(s.radius, 10, 10);
  glPopMatrix();
}

void spawnStar(int i) {

  int x, y, z, speed, radius;
  x = (rand() % CURRENT_WIDTH + 1) - (CURRENT_WIDTH / 2);
  y = (rand() % CURRENT_HEIGHT + 1) - (CURRENT_HEIGHT / 2);
  z = -FAR_VAL - 100;
  speed = (rand() % 10 + 1);
  radius = (rand() % MAX_RADIUS + 1);
  if(speed < MIN_SPEED_STAR)
    speed = MIN_SPEED_STAR;

  initialiseStar(&S[i], x, y, z, radius, speed);
  STAR_COUNT++;
}

void stars(int* count) {

  int i;
  if(*count == SPAWN_FREQUENCY_STAR && STAR_COUNT < MAX_STARS) {
    spawnStar(STAR_COUNT);
    *count = 0;
  }

  for(i = 0; i < STAR_COUNT; i++) {

    if(!S[i].done)
      plotStar(S[i]);
    else {
      STAR_COUNT--;
      spawnStar(i);
    }
  }
}
