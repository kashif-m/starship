
void front(int pos[], int size[]) {
  glBegin(GL_LINE_LOOP);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] / 1.13 + size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] / 1.13 + size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] / 1.13 + size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] / 1.13 + size[2] / 2);
  glEnd();
}

void back(int pos[], int size[]) {
  glBegin(GL_LINE_LOOP);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] / 1.13 - size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] / 1.13 - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] / 1.13 - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] / 1.13 - size[2] / 2);
  glEnd();
}

void right(int pos[], int size[]) {
  glBegin(GL_LINE_LOOP);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] / 1.13 + size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] / 1.13 + size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] / 1.13 - size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] / 1.13 - size[2] / 2);
  glEnd();
}

void left(int pos[], int size[]) {
  glBegin(GL_LINE_LOOP);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] / 1.13 + size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] / 1.13 + size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] / 1.13 - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] / 1.13 - size[2] / 2);
  glEnd();
}

void top(int pos[], int size[]) {
  glBegin(GL_LINE_LOOP);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] / 1.13 + size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] / 1.13 - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] / 1.13 - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] + size[1] / 2,
      pos[2] / 1.13 + size[2] / 2);
  glEnd();
}

void bottom(int pos[], int size[]) {
  glBegin(GL_LINE_LOOP);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] / 1.13 + size[2] / 2);
    glVertex3f(pos[0] + size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] / 1.13 - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] / 1.13 - size[2] / 2);
    glVertex3f(pos[0] - size[0] / 2,
      pos[1] - size[1] / 2,
      pos[2] / 1.13 + size[2] / 2);
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

void detectCollision() {

  int i;
  for(i = 0; i < MAX_ASTEROIDS; i++) {
    // printf("%d %d %d\n", A[i].tx, A[i].ty, A[i].tz);
  }
}
