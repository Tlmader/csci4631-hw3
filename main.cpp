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

/**
 * Rotates a point around a pivot via translation to the origin.
 *
 * @param p a pointer to the point to be rotated
 * @param pivot a pointer to the point used as the pivot
 * @param angle a double for determining rotation
 * @return the pointer to the rotated point
 */
Point* getRotatedPoint(Point* p, Point* pivot, double angle) {
  p->setX(p->getX() - pivot->getX());
  p->setY(p->getY() - pivot->getY());
  p->setX(p->getX() * cos(angle) - (p->getY() * sin(angle)) + pivot->getX());
  p->setY(p->getX() * sin(angle) + (p->getY() * cos(angle)) + pivot->getY());
  return p;
}

/**
 * Iteratively gets the Koch curve for two given points.
 *
 * @param iter the number of times to run
 * @param p1 a pointer to a first point
 * @param p2 a pointer to a second point
 * @return the vector of pointers to the vertices
 */
std::vector<Point*> getKochCurveWithIteration(int iter, Point* p1, Point* p2) {
  std::vector<Point*> currentVertices;
  currentVertices.push_back(p1);
  currentVertices.push_back(p2);
  for (int i = 0; i < iter; i++) {
    std::vector<Point*> tempVertices;
    for (int j = 0; j < currentVertices.size() - 1; j++) {
      Point* p1 = currentVertices[j];
      Point* p5 = currentVertices[j + 1];
      Point* p2 = new Point((p1->getX() * 2 / 3) + (p5->getX() / 3), (p1->getY() * 2 / 3) + (p5->getY() / 3)); // 1/3 of distance
      Point* p4 = new Point((p1->getX() / 3) + (p5->getX() * 2 / 3), (p1->getY() / 3) + (p5->getY() * 2 / 3)); // 2/3 of distance
      Point* p3 = getRotatedPoint(p2, p4, -60);
      tempVertices.push_back(p1);
      tempVertices.push_back(p2);
      tempVertices.push_back(p3);
      tempVertices.push_back(p4);
    }
    tempVertices.push_back(currentVertices[currentVertices.size() - 1]);
    currentVertices = tempVertices;
  }
  return currentVertices;
}

/**
* Draws a line strip based on given vertices.
*
* @param vertices a vector of pointers to vertices
*/
void draw(std::vector<Point*> vertices) {
  glBegin(GL_LINE_STRIP);
  glClear(GL_COLOR_BUFFER_BIT);
  for (int i = 0; i < vertices.size(); i++) {
    glVertex2f(vertices[i]->getX(), vertices[i]->getY());
  }
  glEnd();
  glFlush();
}

/**
 * Passed to glutDisplayFunc() as the display callback function.
 */
void display()
{
  draw(getKochCurveWithIteration(3, new Point(-0.5, -0.5), new Point(0.5, -0.5)));
  draw(getKochCurveWithIteration(3, new Point(0.5, -0.5), new Point(0.0, sqrt(0.75) - 0.5)));
  draw(getKochCurveWithIteration(3, new Point(0.0, sqrt(0.75) - 0.5), new Point(-0.5, -0.5)));
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
