
void plotAsteroids(int* count) {
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
    asteroids(count);
  glDisable(GL_LIGHT0);
  glDisable(GL_LIGHT1);
}

void starshipWire() {
  glEnable(GL_LIGHT2);
  glEnable(GL_LIGHT3);
  glEnable(GL_LIGHT4);
    glDisable(GL_POLYGON_OFFSET_FILL);
      plotStarshipWire();
      glLineWidth(2);
    glEnable(GL_POLYGON_OFFSET_FILL);
  glPolygonOffset(1.0, 1.0);
  glDisable(GL_LIGHT2);
  glDisable(GL_LIGHT3);
  glDisable(GL_LIGHT4);
}

void asteroidCollisonFrame() {

  int i;
  for(i = 0; i < MAX_ASTEROIDS; i++) {
    int pos[] = {A[i].cx, A[i].cy, A[i].cz};
    int size[] = {A[i].sizeX, A[i].sizeY, A[i].sizeZ};
    plotCollisionFrame(pos, size);
  }
}

void plotStars(int* count) {
  glEnable(GL_LIGHT5);
    stars(count);
    int pos[] = {starship.cx, starship.cy, starship.cz};
    int size[] = {starship.sizeX, starship.sizeY, starship.sizeZ};
    plotCollisionFrame(pos, size);
    // asteroidCollisonFrame();
  glDisable(GL_LIGHT5);
}

void plotBullet() {
  glEnable(GL_LIGHT6);
  if(!done)    
    bullets();
  glDisable(GL_LIGHT6);
}
