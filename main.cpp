/**
 * Contains the main function and program logic for drawing a Koch Snowflake.
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
 * Returns a point by a distance between two points.
 *
 * @param p1 a start point
 * @param p2 an end point
 * @param dist a double used for distance
 * @return the point between p1 and p2
 */
Point* getPointByDistance(Point* p1, Point* p2, double dist) {
  Point* p = new Point();
  p->setX((p1->getX() * (1.0 - dist)) + (p2->getX() * dist));
  p->setY((p1->getY() * (1.0 - dist)) + (p2->getY() * dist));
  return p;
}

/**
 * Returns a point rotated around a pivot via translation to the origin.
 *
 * @param point a point to be rotated
 * @param pivot a point used as the pivot
 * @param angle a double for determining rotation
 * @return the rotated point
 */
Point* getPointByRotation(Point* point, Point* pivot, double angle) {
  Point* temp = new Point();
  Point* p = new Point();
  temp->setX(point->getX() - pivot->getX());
  temp->setY(point->getY() - pivot->getY());
  p->setX((temp->getX() * cos(angle)) - (temp->getY() * sin(angle)));
  p->setY((temp->getX() * sin(angle)) + (temp->getY() * cos(angle)));
  p->setX(p->getX() + pivot->getX());
  p->setY(p->getY() + pivot->getY());
  return p;
}

/**
 * Iteratively gets the Koch curve for two given points.
 *
 * @param iter the number of times to run
 * @param p1 a start point
 * @param p2 an end point
 * @return the vector of vertices
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
      Point* p2 = getPointByDistance(p1, p5, 1.0 / 3.0);
      Point* p4 = getPointByDistance(p1, p5, 2.0 / 3.0);
      Point* p3 = getPointByRotation(p4, p2, -60 * (M_PI / 180));
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
 * Recursively gets the Koch curve for two given points.
 *
 * @param iter the number of times to run
 * @param p1 a start point
 * @param p2 an end point
 * @param vertices a vector of vertices
 * @return the updated vector of vertices
 */
std::vector<Point*> getKochCurveWithRecursion(int iter, Point* p1, Point* p5, std::vector<Point*> vertices) {
  if (iter == 0) {
    vertices.push_back(p1);
    vertices.push_back(p5);
  } else {
    iter--;
    Point* p2 = getPointByDistance(p1, p5, 1.0 / 3.0);
    Point* p4 = getPointByDistance(p1, p5, 2.0 / 3.0);
    Point* p3 = getPointByRotation(p4, p2, -60 * (M_PI / 180));
    vertices = getKochCurveWithRecursion(iter, p1, p2, vertices);
    vertices = getKochCurveWithRecursion(iter, p2, p3, vertices);
    vertices = getKochCurveWithRecursion(iter, p3, p4, vertices);
    vertices = getKochCurveWithRecursion(iter, p4, p5, vertices);
  }
  return vertices;
}

/**
 * Begins the recursive process for getting the Koch curve for two given points.
 *
 * @param iter the number of times to run
 * @param p1 a start point
 * @param p2 an end point
 * @return the vector of vertices
 */
std::vector<Point*> getKochCurveWithRecursion(int iter, Point* p1, Point* p2) {
  std::vector<Point*> vertices;
  return getKochCurveWithRecursion(iter, p1, p2, vertices);
}

/**
* Draws a line strip based on given vertices.
*
* @param vertices a vector of pointers to vertices
*/
void draw(std::vector<Point*> vertices) {
  glBegin(GL_LINE_STRIP);
  for (int i = 0; i < vertices.size(); i++) {
    glVertex2f(vertices[i]->getX(), vertices[i]->getY());
  }
  glEnd();
}

/**
 * Passed to glutDisplayFunc() as the display callback function.
 */
void displayWithIteration()
{
  glClear(GL_COLOR_BUFFER_BIT);
  draw(getKochCurveWithIteration(5, new Point(-0.5, -0.5), new Point(0.5, -0.5)));
  draw(getKochCurveWithIteration(5, new Point(0.5, -0.5), new Point(0.0, sqrt(0.75) - 0.5)));
  draw(getKochCurveWithIteration(5, new Point(0.0, sqrt(0.75) - 0.5), new Point(-0.5, -0.5)));
  glFlush();
}

/**
 * Passed to glutDisplayFunc() as the display callback function.
 */
void displayWithRecursion()
{
  glClear(GL_COLOR_BUFFER_BIT);
  // draw(getKochCurveWithIteration(5, new Point(-0.5, -0.5), new Point(0.5, -0.5)));
  // draw(getKochCurveWithIteration(5, new Point(0.5, -0.5), new Point(0.0, sqrt(0.75) - 0.5)));
  // draw(getKochCurveWithIteration(5, new Point(0.0, sqrt(0.75) - 0.5), new Point(-0.5, -0.5)));
  draw(getKochCurveWithRecursion(5, new Point(-0.5, -0.5), new Point(0.5, -0.5)));
  draw(getKochCurveWithRecursion(5, new Point(0.5, -0.5), new Point(0.0, sqrt(0.75) - 0.5)));
  draw(getKochCurveWithRecursion(5, new Point(0.0, sqrt(0.75) - 0.5), new Point(-0.5, -0.5)));
  glFlush();
}

/**
 * Passed to glutKeyboardFunc() as the keyboard callback.
 *
 * @param key the input received via keystroke
 * @param x the x-coordinate of the mouse location
 * @param y the y-coordinate of the mouse location
 */
void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
  case 033:
    exit(EXIT_SUCCESS);
    break;
  }
}

/**
 * Called at program startup.
 *
 * @param argc the number of arguments
 * @param argv the array of arguments
 */
int main(int argc, char *argv[]) {
  std::string arg = argv[1];
  bool useRecursion = false;
  if (arg != "-i" || arg!= "--iterative") {
    useRecursion = false;
  } else if (arg!= "-r" || arg != "--recursive") {
    useRecursion = true;
  } else {
    std::cout << "usage: ./koch.exe [-i | --iterative] [-r | --recursive]\n" << std::endl;
  }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize(512, 512);
  glutCreateWindow("csci4631-hw3");
  if (useRecursion) {
    glutDisplayFunc(displayWithIteration);
  } else {
    glutDisplayFunc(displayWithRecursion);
  }
  glutKeyboardFunc(keyboard);
  glutMainLoop();
}
