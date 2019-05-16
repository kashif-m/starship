
#define NEAR_VAL 500
#define FAR_VAL NEAR_VAL*5
float h, s, l;

void asteroidTopLight() {

	// light gray
	GLfloat mat_ambient[] = { .35, .35, .35, 1.0 };
	GLfloat light_position[] = { 0.0, 1000, -1000, 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, mat_ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void asteroidBottomLight() {

	// dark gray
	GLfloat mat_ambient[] = { .25, .25, .25, 1.0 };
	GLfloat light_position[] = { 0.0, -1000, -1000, 0.0 };

	glLightfv(GL_LIGHT1, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, mat_ambient);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);
}

void spaceshipLeftLight() {

	// red
	GLfloat mat_ambient[] = { 0.0, 0.1, .3, 1.0 };
	GLfloat light_position[] = { -1000, 500, 0, 0.0 };

	glLightfv(GL_LIGHT2, GL_DIFFUSE, mat_ambient);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position);
	glLightfv(GL_LIGHT2, GL_AMBIENT, mat_ambient);
}

void spaceshipCenterLight() {

	// green
	GLfloat mat_ambient[] = { .1, 0, .2, 1.0 };
	GLfloat light_position[] = { 0.0, -500, 1000, 0.0 };

	glLightfv(GL_LIGHT3, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, mat_ambient);
	glLightfv(GL_LIGHT3, GL_POSITION, light_position);
}

void spaceshipRightLight() {

	// blue
	GLfloat mat_ambient[] = { 0.3, 0, .1, 1.0 };
	GLfloat light_position[] = { 1000, 500, 0, 0.0 };

	glLightfv(GL_LIGHT4, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, mat_ambient);
	glLightfv(GL_LIGHT4, GL_POSITION, light_position);
}

void starsLight() {

	// white
	GLfloat mat_ambient[] = { 1, 1, 1, 1.0 };
	GLfloat light_position[] = { 0, 0, 1000, 0.0 };

	glLightfv(GL_LIGHT5, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, mat_ambient);
	glLightfv(GL_LIGHT5, GL_POSITION, light_position);
}

void bulletLight() {

	// Orange
	GLfloat mat_ambient[] = { 1, 0.2, 0, 1.0 };
	GLfloat light_position[] = { 0, 0, 1000, 0.0 };

	glLightfv(GL_LIGHT6, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, mat_ambient);
	glLightfv(GL_LIGHT6, GL_POSITION, light_position);
}

// init
void init() {

	glutFullScreen();
	// glutSetCursor(GLUT_CURSOR_NONE);
	glPointSize(10);
	glShadeModel(GL_SMOOTH);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 1);

	// light sources
	asteroidTopLight();
	asteroidBottomLight();
	spaceshipLeftLight();
	spaceshipCenterLight();
	spaceshipRightLight();
	starsLight();
	bulletLight();

	// material
	GLfloat mat[] = { 1, 1, 1, 0 };
	GLfloat backMat[] = { 0, 0, 0, 0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
	glMaterialfv(GL_BACK, GL_DIFFUSE, backMat);
}

// reshape
void reshape(int w, int h) {

	CURRENT_WIDTH = w;
	CURRENT_HEIGHT = h;

	glClearColor(0.01, 0.01, 0.01, 1);
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float negX = -w / 2, posX = w / 2,
				negY = -h / 2, posY = h / 2;

	gluLookAt(0, 0, 0, 0, 0, -100, 0, 1, 0);
	glFrustum(negX, posX, negY, posY, NEAR_VAL, 1000000);
	glMatrixMode(GL_MODELVIEW);
}
