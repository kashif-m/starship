
// special function
void moveStarship(int key, int X, int Y) {

  switch(key) {
    case GLUT_KEY_UP:
      if(starship.cy < CURRENT_HEIGHT / 1.5)
        starship.cy += 50;
      break;

    case GLUT_KEY_DOWN:
      if(starship.cy > -CURRENT_HEIGHT / 5.5)
        starship.cy -= 50;
      break;

    case GLUT_KEY_RIGHT:
      if(starship.cx < CURRENT_WIDTH / 2.5)
        starship.cx += 50;
      break;
    
    case GLUT_KEY_LEFT:
      if(starship.cx > -CURRENT_WIDTH / 2.5)
        starship.cx -= 50;
      break;

    default:
      break;
  }

  glutPostRedisplay();
}

void plotStarship() {
  glPushMatrix();
    glTranslatef(0, -(CURRENT_HEIGHT / 2) + 200, -320);
    glTranslatef(starship.cx, starship.cy, 0);
    glRotatef(180, 0, 1, 0);  
    glScalef(0.15, 0.25, 0.15);
    glColor3f(1, 0, 1);
    plotModel(&starship, 'P');
  glPopMatrix();
}

void plotStarshipWire() {
  glPushMatrix();
    glTranslatef(0, -(CURRENT_HEIGHT / 2) + 200, -320);
    glTranslatef(starship.cx, starship.cy, 0);
    glRotatef(180, 0, 1, 0);  
    glScalef(0.15, 0.25, 0.15);
    glColor3f(1, 0, 1);
    plotModel(&starship, 'L');
  glPopMatrix();
}
