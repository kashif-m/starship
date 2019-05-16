
int tx, ty, tz, done = 1;

void bullets() {
  
  glPushMatrix();
    glTranslatef(tx - 130, ty, tz);
    glutSolidSphere(12, 4, 10);
    glTranslatef(starship.sizeX - 12, 0, 0);
    glutSolidSphere(12, 4, 10);
  glPopMatrix();
}

void moveBullet() {
  if(!done)
    tz -= 100; 
}

void spawnBullet() {

  done = 0;
  tx = CX;
  ty = CY;
  tz = -700;
}

// mouse function
void fireRounds(int key, int state, int x, int y) {

	// LMB
	if(key == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		spawnBullet();
}
