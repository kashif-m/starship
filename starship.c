
int CX = 0, CY = -1500 / 5;

// VERY special function
void moveStarship(int X, int Y) {
        
    if (X < CURRENT_WIDTH/2 && starship.cx > -CURRENT_WIDTH * 3)
      CX = (-(CURRENT_WIDTH/2) + X) / 1.3;
    else if (X > CURRENT_WIDTH/2 && starship.cx < CURRENT_WIDTH * 3)
      CX = (X - (CURRENT_WIDTH/2)) / 1.3;
    
    if (Y < CURRENT_HEIGHT/2 && starship.cy < CURRENT_HEIGHT * 3)
      CY = ((CURRENT_HEIGHT/2) - Y) / 1.4;
    else if (Y > CURRENT_HEIGHT/2 && starship.cy > -CURRENT_HEIGHT * 3)
      CY = -(Y - (CURRENT_HEIGHT/2)) / 1.3;

    starship.cx = 1.2*CX;
    starship.cy = 1.2*CY;
  glutPostRedisplay();
}

void plotStarship() {
  glPushMatrix();
    glTranslatef(0, 0, -700);
    glScalef(0.25, 0.25, 0.25);
    glTranslatef(5*CX, 5*CY, 0);
    glRotatef(180, 0, 1, 0);  
    glColor3f(1, 0, 1);
    plotModel(&starship, 'P');
  glPopMatrix();
}

void plotStarshipWire() {
  glPushMatrix();
    glTranslatef(0, 0, -700);
    glScalef(0.25, 0.25, 0.25);
    glTranslatef(5*CX, 5*CY, 0);
    glRotatef(180, 0, 1, 0);
    glColor3f(1, 0, 1);
    plotModel(&starship, 'L');
  glPopMatrix();
}
