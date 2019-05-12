
#define NEAR_VAL 200
#define FAR_VAL SCREEN_DEPTH*1.5

void asteroidLight() {

	GLfloat mat_ambient[] = { 0, .3, .8, 0.0 };
	GLfloat light_position[] = { 0.0, -1000, -1000, 0.0 };
	GLfloat mat_shininess[] = { 5.0 };

	glLightfv(GL_LIGHT1, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
}

void starshipLight() {

	GLfloat mat_ambient[] = { .1, .1, .1, 1.0 };
	GLfloat mat_shininess[] = { 5.0 };
	GLfloat light_position[] = { 0.0, 1000, -100, 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

// init
void init() {

	glPointSize(10);
	glShadeModel(GL_SMOOTH);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 1);

	// light sources
	starshipLight();
	asteroidLight();

	// material
	GLfloat mat[] = {0.09, .09, .1, 0};
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
	glMaterialfv(GL_BACK, GL_AMBIENT, mat);
}

// reshape
void reshape(int w, int h) {

	CURRENT_WIDTH = w;
	CURRENT_HEIGHT = h;

	glClearColor(.1, .1, .1, 1);
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float negX = -w / 2, posX = w / 2,
				negY = -h / 2, posY = h / 2;

	glFrustum(negX, posX, negY, posY, NEAR_VAL, FAR_VAL);
	glMatrixMode(GL_MODELVIEW);
}
