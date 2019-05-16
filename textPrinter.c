
void drawString(float x, float y, float z, char *string)
{
	char *c;
	glRasterPos3f(x,y,z);

	for(c=string;*c!='\0';c++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
}
