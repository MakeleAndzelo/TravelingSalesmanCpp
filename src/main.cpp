#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

#include "../headers/PathDrawer.h"

using namespace std;
using namespace ts;

void displayWindow();
void reshapeWindow(int, int);

vector<City> cities;

int main(int argc, char **argv)
{
    HamiltonianPath hamiltonianPath;
    CitySeed citySeed;

    cities = citySeed.SeedData(5);
    hamiltonianPath.GetUsingBruteforce(cities, 0);

    cities = hamiltonianPath.GetBruteforceResult();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Travelling Salesman");
    glutDisplayFunc(displayWindow);
    glutIdleFunc(displayWindow);
    glutReshapeFunc(reshapeWindow);
    glutMainLoop();

    return 0;
}

void displayWindow()
{
    glClear(GL_COLOR_BUFFER_BIT);
    PathDrawer drawer;
    drawer.draw(cities);
    glutSwapBuffers();
}

void reshapeWindow(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 400, 0.0, 400, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}
