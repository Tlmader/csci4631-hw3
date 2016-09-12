/**
 * Contains the main function.
 * @author Ted Mader
 * @date 2016-09-11
 */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <GLUT/glut.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include "point.hpp"

Point* getKoch(Point* p1, Point* p2) {
  // TODO: Math here
}

void getVertices(int iter, Point* p1, Point* p2) {
  std::vector<Point*> currentVertices;
  std::vector<Point*> kochVertices;
  std::vector<Point*> tempVertices;
  currentVertices.push_back(p1);
  currentVertices.push_back(p2);
  for (int i = 0; i < currentVertices.size() - 1; i++) {
    kochVertices.push_back(getKoch(currentVertices[i], currentVertices[i + 1]));
  }
  for (int i = 0; i < currentVertices.size(); i++) {
    tempVertices.push_back(currentVertices[i]);
    if (i < currentVertices.size() - 1) {
      tempVertices.push_back(kochVertices[i]);
    }
  }
  glEnd();
}

void display()
{
  glBegin(GL_LINE_STRIP);
  glClear(GL_COLOR_BUFFER_BIT);
  getVertices(3, new Point(-0.5, -0.5), new Point(0.5, -0.5));
  // glVertex3f(0.0, sqrt(0.75) - 0.5, 0);
  // glVertex3f(-0.5, -0.5, 0);
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
