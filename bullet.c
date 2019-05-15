
int tx, ty, tz, done = 1;

void bullets() {
  
  glPushMatrix();
    glTranslatef(130, -(CURRENT_HEIGHT / 2) + 200, -800);
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
  tx = -starship.cx;
  ty = starship.cy;
  tz = 0;
}

// keyboard function
void fireRounds(unsigned char key, int x, int y) {

	// spacebar
	if(key == ' ')
		spawnBullet();
}
