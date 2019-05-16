
int tx, ty, tz, done = 1;

void bullets() {
  
  glPushMatrix();
    glTranslatef(130, -0, -700);
    glScalef(0.25, 0.25, 0.25);
    glRotatef(180, 0, 1, 0);  
    glColor3f(1, 0, 1);

    glTranslatef(tx, ty, tz);
    glutSolidSphere(50, 4, 10);
    glTranslatef(1050, 0, 0);
    glutSolidSphere(50, 4, 10);
  glPopMatrix();
}

void moveBullet() {
  if(!done)
    tz += 500; 
}

void spawnBullet() {

  done = 0;
  tx = -5*CX;
  ty = 5*CY;
  tz = 0;
}

// mouse function
void fireRounds(int key, int state, int x, int y) {

	// LMB
	if(key == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		spawnBullet();
}
