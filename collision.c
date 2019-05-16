
void front(int pos[], int size[]) {
  glBegin(GL_LINE_LOOP);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] + size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] + size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] + size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] + size[2] / 2);
  glEnd();
}

void back(int pos[], int size[]) {
  glBegin(GL_LINE_LOOP);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] - size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] - size[2] / 2);
  glEnd();
}

void right(int pos[], int size[]) {
  glBegin(GL_LINE_LOOP);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] + size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] + size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] - size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] - size[2] / 2);
  glEnd();
}

void left(int pos[], int size[]) {
  glBegin(GL_LINE_LOOP);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] + size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] + size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] - size[2] / 2);
  glEnd();
}

void top(int pos[], int size[]) {
  glBegin(GL_LINE_LOOP);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] + size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] + size[2] / 2);
  glEnd();
}

void bottom(int pos[], int size[]) {
  glBegin(GL_LINE_LOOP);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] + size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] + size[2] / 2);
  glEnd();
}

void plotCollisionFrame(int pos[], int size[]) {

  glPushMatrix();
    left(pos, size);
    right(pos, size);
    top(pos, size);
    bottom(pos, size);
    front(pos, size);
    back(pos, size);
  glPopMatrix();
}

void detectStarshipCollision() {

  int i;
  for(i = 0; i < MAX_ASTEROIDS; i++) {
    // printf("%d %d %d\n", A[i].cx, A[i].cy, A[i].cz);
    if( fabs(A[i].cx - starship.cx) < fabs(A[i].sizeX / 2 + starship.sizeX / 2)) {
      if( fabs(A[i].cy - starship.cy) < fabs(A[i].sizeY / 2 + starship.sizeY / 2)) {
        if(fabs(A[i].cz - starship.cz) < fabs(A[i].sizeZ / 2 + starship.sizeZ / 2)) {
          A[i].done = 1;
        }
      }
    }
  }
  printf("\n");
}

void detectBulletCollision() {

  int i;
  for(i = 0; i < MAX_ASTEROIDS; i++) {
    if( fabs(A[i].cx - tx - 130) < fabs(A[i].sizeX / 2 + 25) ||
          fabs(A[i].cx - tx + 130) < fabs(A[i].sizeX / 2 + 25)) {
      if( fabs(A[i].cy - ty) < fabs(A[i].sizeY / 2 + 25)) {
        if(fabs(A[i].cz - tz) < fabs(A[i].sizeZ / 2 + 25)) {
          A[i].done = 1;
          tz = -FAR_VAL;
        }
      }
    }
  }
  printf("\n");
}
