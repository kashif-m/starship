
#include <stdio.h>
#include <GL/glut.h>

#define MAX_VERTICES 8000
#define MAX_TEXTURES 8000
#define MAX_NORMALS 8000
#define MAX_FACES 8000
#define MAX_POINTS 8000

float vertex[MAX_VERTICES][3], aVertex[MAX_VERTICES][3];
float texture[MAX_TEXTURES][3], aTexture[MAX_TEXTURES][3];
float normal[MAX_NORMALS][3], aNormal[MAX_NORMALS][3];
int faces[MAX_FACES][MAX_POINTS][3], aFaces[MAX_FACES][MAX_POINTS][3];
char lineHeader[128];

int TOTAL_FACES = 0, ASTEROID_TOTAL_FACES = 0;

void readLine(FILE *fp) {
  fscanf(fp, "%[^\n]", lineHeader);
}

void plotPoints(float x, float y, float z, float u, float v, float w, float nx, float ny, float nz) {
  
  glNormal3f(nx, ny, nz);
  glTexCoord2f(u, v);
  glVertex3f(x, y, z);
}


// asteroid
void plotModel(float *vertex, float *texture, float *normal, int *faces, int TOTAL_FACES) {

  int i;

  glColor3f(.17, .17, .17);
  for(i = 0; i < TOTAL_FACES; i++) {
    int j;

    glBegin(GL_POLYGON);
    for(j = 1; j <= *(faces + (i*MAX_FACES*3)); j++) {


      int v = *(faces + (i*MAX_FACES*3) + (j*3)) - 1,
        t = *(faces + (i*MAX_FACES*3) + (j*3) + 1) - 1,
        n = *(faces + (i*MAX_FACES*3) + (j*3) + 2) - 1;

      plotPoints(*(vertex + (v*3)), *(vertex + (v*3) + 1), *(vertex + (v*3) + 2),
        *(texture + (t*3)), *(texture + (t*3) + 1), *(texture + (t*3) + 2),
        *(normal + (n*3)), *(normal + (n*3) + 1), *(normal + (n*3) + 2));
    }
    glEnd();
  }
}

void updateAValues(char type, int i) {

  float v[3];
  int j;
  sscanf(lineHeader, "%f %f %f", &v[0], &v[1], &v[2]);

  switch(type) {
    case 'v': for(j = 0; j < 3; j++)
                aVertex[i][j] = v[j];
              break;
    case 't': for(j = 0; j < 3; j++)
                aTexture[i][j] = v[j];
              break;
    case 'n': for(j = 0; j < 3; j++)
                aNormal[i][j] = v[j];
              break;
  }
}

void loadAsteroid() {

  FILE* fv = fopen("./models/Asteroid.obj", "r");

  int f[3];
  int i = 0, k = 0, m = 0, o = 0;

  while (1) {

    char lineHeader[128];

    int res = fscanf(fv, "%s", lineHeader);
    if (res == EOF)
      break;

    if (strcmp(lineHeader, "f") == 0) {

      int j = 0, p = 0;
      while(1) {

        fscanf(fv, "%d/%d/%d", &f[0], &f[1], &f[2]);
        p++;
        for(j = 0; j < 3; j++)
          aFaces[o][p][j] = f[j];

        char ch = fgetc(fv);
        if(ch == 13 || ch == -1)
          break;
      }
      aFaces[o][0][0] = p;
      o++;
    } else if (strcmp(lineHeader, "v") == 0) {

      readLine(fv);
      updateAValues('v', i++);
    } else if (strcmp(lineHeader, "vt") == 0) {

      readLine(fv);
      updateAValues('t', k++);
    } else if (strcmp(lineHeader, "vn") == 0) {

      readLine(fv);
      updateAValues('n', m++);
    }
  }
  fclose(fv);
  ASTEROID_TOTAL_FACES = o;
}


// spaceship
void plotSpaceShip() {

  int i;

  for(i = 0; i < TOTAL_FACES; i++) {
    int j;

    glBegin(GL_POLYGON);
    for(j = 1; j <= faces[i][0][0]; j++) {

      int v = faces[i][j][0] - 1,
        t = faces[i][j][1] - 1,
        n = faces[i][j][2] - 1;

      plotPoints(vertex[v][0], vertex[v][1], vertex[v][2],
        texture[t][0], texture[t][1], texture[t][2],
        normal[n][0], normal[n][1], normal[n][2]);
    }
    glEnd();
  }
}

void updateValues(char type, int i) {

  float v[3];
  int j;
  sscanf(lineHeader, "%f %f %f", &v[0], &v[1], &v[2]);

  switch(type) {
    case 'v': for(j = 0; j < 3; j++)
                vertex[i][j] = v[j];
              break;
    case 't': for(j = 0; j < 3; j++)
                texture[i][j] = v[j];
              break;
    case 'n': for(j = 0; j < 3; j++)
                normal[i][j] = v[j];
              break;
  }
}

void loadSpaceShip() {

  FILE *vf = fopen("./models/Starship.obj", "r");

  int f[3];
  int i = 0, k = 0, m = 0, o = 0;

  while (1) {

    char lineHeader[128];
    int res = fscanf(vf, "%s", lineHeader);
    if (res == EOF)
      break;

    if (strcmp(lineHeader, "f") == 0) {

      int j = 0, p = 0;
      while(1) {

        fscanf(vf, "%d/%d/%d", &f[0], &f[1], &f[2]);
        p++;
        for(j = 0; j < 3; j++)
          faces[o][p][j] = f[j];

        char ch = fgetc(vf);
        if(ch == 13 || ch == -1)
          break;
      }
      faces[o][0][0] = p;
      o++;
    } else if (strcmp(lineHeader, "v") == 0) {

      readLine(vf);
      updateValues('v', i++);
    } else if (strcmp(lineHeader, "vt") == 0) {

      readLine(vf);
      updateValues('t', k++);
    } else if (strcmp(lineHeader, "vn") == 0) {

      readLine(vf);
      updateValues('n', m++);
    }
  }
  fclose(vf);
  TOTAL_FACES = o;
}

