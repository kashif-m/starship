
// init
void init() {

   GLfloat mat_ambient[] = { 0, 1, 1, 0.0 };
   GLfloat mat_shininess[] = { 5.0 };
   GLfloat light_position[] = { 0.0, 100.0, 100.0, 1.0 };

   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_SMOOTH);

   glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_ambient);
   glMaterialfv(GL_BACK, GL_DIFFUSE, mat_ambient);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}

// idle
void moveAsteroid() {

  glutPostRedisplay();
}

// reshape
void reshape(int w, int h) {

  glClearColor(.1, .1, .1, 1);
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  float negX = -w / 2, posX = w / 2,
        negY = -h / 2, posY = h / 2;

  glOrtho(negX, posX, negY, posY, -SCREEN_DEPTH / 2, SCREEN_DEPTH / 2);
  glMatrixMode(GL_MODELVIEW);
}
