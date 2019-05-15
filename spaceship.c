
int cx = 0, cy = 0, cz = 0;

// special function
void moveSpaceship(int key, int X, int Y) {

  switch(key) {
    case GLUT_KEY_UP:
      if(cy < CURRENT_HEIGHT / 1.5)
        cy += 50;
      break;

    case GLUT_KEY_DOWN:
      if(cy > -CURRENT_HEIGHT / 5.5)
        cy -= 50;
      break;

    case GLUT_KEY_RIGHT:
      if(cx < CURRENT_WIDTH / 2.5)
        cx += 50;
      break;
    
    case GLUT_KEY_LEFT:
      if(cx > -CURRENT_WIDTH / 2.5)
        cx -= 50;
      break;

    default:
      break;
  }

  glutPostRedisplay();
}

void spaceship() {
  glPushMatrix();
    glTranslatef(0, -(CURRENT_HEIGHT / 2) + 200, -320);
    glTranslatef(cx, cy, 0);
    glRotatef(180, 0, 1, 0);  
    glScalef(0.15, 0.25, 0.15);
    glColor3f(1, 0, 1);
    plotModel('s');
  glPopMatrix();
}

void spaceshipWire() {
  glPushMatrix();
    glTranslatef(0, -(CURRENT_HEIGHT / 2) + 200, -320);
    glTranslatef(cx, cy, 0);
    glRotatef(180, 0, 1, 0);  
    glScalef(0.15, 0.25, 0.15);
    glColor3f(1, 0, 1);
    plotModel('w');
  glPopMatrix();
}