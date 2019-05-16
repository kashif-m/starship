
#define MAX_VERTICES 7500
#define MAX_TEXTURES 7500
#define MAX_NORMALS 7500
#define MAX_FACES 7500
#define MAX_POINTS 7500

struct Model {
  float vertex[MAX_VERTICES][3];
  float texture[MAX_TEXTURES][3];
  float normal[MAX_NORMALS][3];
  int faces[MAX_FACES][MAX_POINTS][3], TOTAL_FACES;
  int cx, cy, cz,
    xMax, xMin,
    yMax, yMin,
    zMax, zMin,
    sizeX, sizeY, sizeZ;
};

char lineHeader[128];
struct Model starship, asteroid;

void readLine(FILE *fp) {
  fscanf(fp, "%[^\n]", lineHeader);
}

void plotPoints(float x, float y, float z, float u, float v, float w, float nx, float ny, float nz) {
  
  glNormal3f(nx, ny, nz);
  glTexCoord2f(u, v);
  glVertex3f(x, y, z);
}

void plotModel(struct Model* model, char type) {

  int i;

  for(i = 0; i < model->TOTAL_FACES; i++) {
    int j;
    
    if(type == 'P')
      glBegin(GL_POLYGON);
    else if(type == 'L')
      glBegin(GL_LINE_LOOP);
    for(j = 1; j <= model->faces[i][0][0]; j++) {

      int v = model->faces[i][j][0] - 1,
        t = model->faces[i][j][1] - 1,
        n = model->faces[i][j][2] - 1;

      plotPoints(model->vertex[v][0], model->vertex[v][1], model->vertex[v][2],
        model->texture[t][0], model->texture[t][1], model->texture[t][2],
        model->normal[n][0], model->normal[n][1], model->normal[n][2]);
    }
    glEnd();
  }
}

int min(int a, int b) {
  return a < b ? a : b;
}

int max(int a, int b) {
  return a > b ? a : b;
}

void computeMinMax(struct Model* model, int x, int y, int z) {

  model->xMin = min(model->xMin, x);
  model->xMax = max(model->xMax, x);

  model->yMin = min(model->yMin, y);
  model->yMax = max(model->yMax, y);

  model->zMin = min(model->zMin, z);
  model->zMax = max(model->zMax, z);
}

void updateValues(struct Model* model, char type, int i, float *ptr) {

  float v[3];
  int j;
  sscanf(lineHeader, "%f %f %f", &v[0], &v[1], &v[2]);
  switch(type) {
    case 'v': computeMinMax(model, v[0], v[1], v[2]);
              for(j = 0; j < 3; j++)
                *(ptr + (i*3) + j) = v[j];
              break;
    case 't': for(j = 0; j < 3; j++)
                *(ptr + (i*3) + j) = v[j];
              break;
    case 'n': for(j = 0; j < 3; j++)
                *(ptr + (i*3) + j) = v[j];
              break;
  }
}

void translate(struct Model* model, char axis, float val) {
  switch(axis) {
    case 'x':
        model->xMax += val;
        model->xMin += val;
        break;
    case 'y':
        model->yMax += val;
        model->yMin += val;
        break;
    case 'z':
        model->zMax += val;
        model->zMin += val;
        break;
  }
}

void scale(struct Model* model, char axis, float val) {
  switch(axis) {
    case 'x':
        model->xMax /= val;
        model->xMin /= val;
        break;
    case 'y':
        model->yMax /= val;
        model->yMin /= val;
        break;
    case 'z':
        model->zMax /= val;
        model->zMin /= val;
        break;
  }
}

void computeCenter(struct Model* model, char type) {

  model->cx = (model->xMax + model->xMin) / 2;
  model->cy = (model->yMax + model->yMin) / 2;
  model->cz = (model->zMax + model->zMin) / 2;

  model->sizeX = fabs(model->xMax - model->xMin);
  model->sizeY = fabs(model->yMax - model->yMin);
  model->sizeZ = fabs(model->zMax - model->zMin);

  printf("%d %d %d\n", model->sizeX, model->sizeY, model->sizeZ);
  printf("%d %d %d\n", model->cx, model->cy, model->cz);
}

void loadModel(struct Model* model, char filename[]) {

  char file[] = "./models/";
  strcat(file, filename);
  FILE* fv = fopen(file, "r");

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
          model->faces[o][p][j] = f[j];

        char ch = fgetc(fv);
        if(ch == 13 || ch == -1)
          break;
      }
      model->faces[o][0][0] = p;
      o++;
    } else if (strcmp(lineHeader, "v") == 0) {

      readLine(fv);
      updateValues(model, 'v', i++, &model->vertex[0][0]);
    } else if (strcmp(lineHeader, "vt") == 0) {

      readLine(fv);
      updateValues(model, 't', k++, &model->texture[0][0]);
    } else if (strcmp(lineHeader, "vn") == 0) {

      readLine(fv);
      updateValues(model, 'n', m++, &model->normal[0][0]);
    }
  }
  fclose(fv);
  model->TOTAL_FACES = o;
  if (!strcmp(filename, "Starship.obj"))
    computeCenter(model, 's');
  else
    computeCenter(model, 'a');
}
