
void back() {
  glBegin(GL_LINE_LOOP);
    glVertex3f(starship.cx + starship.sizeX / 2,
      starship.cy + starship.sizeY / 2,
      starship.cz / 1.13 + starship.sizeZ / 2);
    glVertex3f(starship.cx + starship.sizeX / 2,
      starship.cy - starship.sizeY / 2,
      starship.cz / 1.13 + starship.sizeZ / 2);
    glVertex3f(starship.cx - starship.sizeX / 2,
      starship.cy - starship.sizeY / 2,
      starship.cz / 1.13 + starship.sizeZ / 2);
    glVertex3f(starship.cx - starship.sizeX / 2,
      starship.cy + starship.sizeY / 2,
      starship.cz / 1.13 + starship.sizeZ / 2);
  glEnd();
}

void right() {
  glBegin(GL_LINE_LOOP);
    glVertex3f(starship.cx + starship.sizeX / 2,
      starship.cy + starship.sizeY / 2,
      starship.cz / 1.13 + starship.sizeZ / 2);
    glVertex3f(starship.cx + starship.sizeX / 2,
      starship.cy - starship.sizeY / 2,
      starship.cz / 1.13 + starship.sizeZ / 2);
    glVertex3f(starship.cx + starship.sizeX / 2,
      starship.cy - starship.sizeY / 2,
      starship.cz / 1.13 - starship.sizeZ / 2);
    glVertex3f(starship.cx + starship.sizeX / 2,
      starship.cy + starship.sizeY / 2,
      starship.cz / 1.13 - starship.sizeZ / 2);
  glEnd();
}

void left() {
  glBegin(GL_LINE_LOOP);
    glVertex3f(starship.cx - starship.sizeX / 2,
      starship.cy + starship.sizeY / 2,
      starship.cz / 1.13 + starship.sizeZ / 2);
    glVertex3f(starship.cx - starship.sizeX / 2,
      starship.cy - starship.sizeY / 2,
      starship.cz / 1.13 + starship.sizeZ / 2);
    glVertex3f(starship.cx - starship.sizeX / 2,
      starship.cy - starship.sizeY / 2,
      starship.cz / 1.13 - starship.sizeZ / 2);
    glVertex3f(starship.cx - starship.sizeX / 2,
      starship.cy + starship.sizeY / 2,
      starship.cz / 1.13 - starship.sizeZ / 2);
  glEnd();
}

void front() {
  glBegin(GL_LINE_LOOP);
    glVertex3f(starship.cx + starship.sizeX / 2,
      starship.cy + starship.sizeY / 2,
      starship.cz / 1.13 - starship.sizeZ / 2);
    glVertex3f(starship.cx + starship.sizeX / 2,
      starship.cy - starship.sizeY / 2,
      starship.cz / 1.13 - starship.sizeZ / 2);
    glVertex3f(starship.cx - starship.sizeX / 2,
      starship.cy - starship.sizeY / 2,
      starship.cz / 1.13 - starship.sizeZ / 2);
    glVertex3f(starship.cx - starship.sizeX / 2,
      starship.cy + starship.sizeY / 2,
      starship.cz / 1.13 - starship.sizeZ / 2);
  glEnd();
}

void top() {
  glBegin(GL_LINE_LOOP);
    glVertex3f(starship.cx + starship.sizeX / 2,
      starship.cy + starship.sizeY / 2,
      starship.cz / 1.13 + starship.sizeZ / 2);
    glVertex3f(starship.cx + starship.sizeX / 2,
      starship.cy + starship.sizeY / 2,
      starship.cz / 1.13 - starship.sizeZ / 2);
    glVertex3f(starship.cx - starship.sizeX / 2,
      starship.cy + starship.sizeY / 2,
      starship.cz / 1.13 - starship.sizeZ / 2);
    glVertex3f(starship.cx - starship.sizeX / 2,
      starship.cy + starship.sizeY / 2,
      starship.cz / 1.13 + starship.sizeZ / 2);
  glEnd();
}

void bottom() {
  glBegin(GL_LINE_LOOP);
    glVertex3f(starship.cx + starship.sizeX / 2,
      starship.cy - starship.sizeY / 2,
      starship.cz / 1.13 + starship.sizeZ / 2);
    glVertex3f(starship.cx + starship.sizeX / 2,
      starship.cy - starship.sizeY / 2,
      starship.cz / 1.13 - starship.sizeZ / 2);
    glVertex3f(starship.cx - starship.sizeX / 2,
      starship.cy - starship.sizeY / 2,
      starship.cz / 1.13 - starship.sizeZ / 2);
    glVertex3f(starship.cx - starship.sizeX / 2,
      starship.cy - starship.sizeY / 2,
      starship.cz / 1.13 + starship.sizeZ / 2);
  glEnd();
}

void plotCollisionFrame() {

  glPushMatrix();
    // glTranslate(0, 100, 0);
    back();
    right();
    left();
    front();
    top();
    bottom();
  glPopMatrix();
}

void detectCollision() {

  int i;
  for(i = 0; i < MAX_ASTEROIDS; i++) {
    // printf("%d %d %d\n", A[i].tx, A[i].ty, A[i].tz);
  }
}
