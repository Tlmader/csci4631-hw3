/**
 * Contains the main function.
 * @author Ted Mader
 * @date 2016-09-11
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <math.h>
#include <stdlib.h>
#include <GLUT/glut.h>

void getVertices() {
  glBegin(GL_LINE_STRIP);
  glVertex3f(-0.5, -0.5, 0);
  glVertex3f(0.5, -0.5, 0);
  glVertex3f(0.0, sqrt(0.75) - 0.5, 0);
  glVertex3f(-0.5, -0.5, 0);
  glEnd();
}

void display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  drawTriangle();
  glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
  case 033:
    exit(EXIT_SUCCESS);
    break;
  }
}

/**
 * Called at program startup
 *
 * @param argc the number of arguments
 * @param argv the array of arguments
 */
int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(512, 512);
  glutCreateWindow("csci4631-hw3");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
}
