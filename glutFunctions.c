
#define NEAR_VAL 500
#define FAR_VAL NEAR_VAL*10
float h, s, l, color[4];
float hueAngle = 180;

float* HueToRGB(int a)
{
	float r, g, b;
	color[3] = 0;
	if(a < 60) {
		r = 1;g = (float)(a%60)/60 ; b=0;
	}
	else if(a < 120) {
		r=(float)(1 - (float)(a%60)/60); g=1 ; b=0;
	}
	else if(a < 180) {
		r=0; g=1; b=(float)(a%60)/60;
	}
	else if(a < 240) {
		r=0; g=(float)(1 - (float)(a%60) /60); b=1;
	}
	else if(a < 300) {
		r=(float)(a%60)/60; g=0; b=1;
	}
	else if(a < 360) {
		r=1; g=0; b=(float)(1 - (float)(a%60)/60);
	}
		color[0]=r;
		color[1]=g;
		color[2]=b;

	return color;
}

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

	GLfloat* a = HueToRGB(hueAngle);
	GLfloat mat_ambient[4];
	mat_ambient[0] = *(a + 0);
	mat_ambient[1] = *(a + 1);
	mat_ambient[2] = *(a + 2);
	mat_ambient[3] = *(a + 3);
	// red
	GLfloat light_position[] = { -1000, 500, 0, 0.0 };

	glLightfv(GL_LIGHT2, GL_DIFFUSE, mat_ambient);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position);
	glLightfv(GL_LIGHT2, GL_AMBIENT, mat_ambient);
}

void spaceshipCenterLight() {

	GLfloat* a = HueToRGB(hueAngle);
	GLfloat mat_ambient[4];
	mat_ambient[0] = *(a + 0);
	mat_ambient[1] = *(a + 1);
	mat_ambient[2] = *(a + 2);
	mat_ambient[3] = *(a + 3);
	// green
	GLfloat light_position[] = { 0.0, -500, 1000, 0.0 };

	glLightfv(GL_LIGHT3, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, mat_ambient);
	glLightfv(GL_LIGHT3, GL_POSITION, light_position);
}

void spaceshipRightLight() {

	GLfloat* a = HueToRGB(hueAngle);
	GLfloat mat_ambient[4];
	mat_ambient[0] = *(a + 0);
	mat_ambient[1] = *(a + 1);
	mat_ambient[2] = *(a + 2);
	mat_ambient[3] = *(a + 3);
	// blue
	GLfloat light_position[] = { 1000, 500, 0, 0.0 };

	glLightfv(GL_LIGHT4, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, mat_ambient);
	glLightfv(GL_LIGHT4, GL_POSITION, light_position);

	hueAngle += 0.1;
	if(hueAngle > 360)
		hueAngle = 0;
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
	GLfloat mat_ambient[] = { 1, 0.5, 0, 1.0 };
	GLfloat light_position[] = { 0, 0, 1000, 0.0 };

	glLightfv(GL_LIGHT6, GL_AMBIENT, mat_ambient);
	glLightfv(GL_LIGHT6, GL_DIFFUSE, mat_ambient);
	glLightfv(GL_LIGHT6, GL_POSITION, light_position);
}

// init
void init() {

	glutFullScreen();
	glutSetCursor(GLUT_CURSOR_NONE);
	glPointSize(10);
	glShadeModel(GL_SMOOTH);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 1);

	// light sources
	asteroidTopLight();
	asteroidBottomLight();
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

	glFrustum(negX, posX, negY, posY, NEAR_VAL, FAR_VAL);
	//gluLookAt(500, 0, -700, 0, 0, -700, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}
