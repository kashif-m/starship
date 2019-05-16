
int CX = 0;
int CY = -400;

// VERY special function
void moveStarship(int X, int Y) {
        
    if (X < CURRENT_WIDTH / 2 && starship.cx > -CURRENT_WIDTH)
      CX = (-(CURRENT_WIDTH / 2) + X);
    else if (X > CURRENT_WIDTH / 2 && starship.cx < CURRENT_WIDTH)
      CX = (X - (CURRENT_WIDTH / 2));

    if (Y < CURRENT_HEIGHT / 2 && starship.cy < CURRENT_HEIGHT)
      CY = ((CURRENT_HEIGHT / 2) - Y);
    else if (Y > CURRENT_HEIGHT / 2 && starship.cy > -CURRENT_HEIGHT)
      CY = -(Y - (CURRENT_HEIGHT / 2));

    starship.cx = CX;
    starship.cy = CY;
  glutPostRedisplay();
}

void plotStarship() {
  glPushMatrix();
    glTranslatef(0, -12, 0);
    glTranslatef(CX, CY, 0);
    plotModel(&starship, 'P');
  glPopMatrix();
}

void plotStarshipWire() {
  glPushMatrix();
    glTranslatef(0, -12, 0);
    glTranslatef(CX, CY, 0);
    plotModel(&starship, 'L');
  glPopMatrix();
}
