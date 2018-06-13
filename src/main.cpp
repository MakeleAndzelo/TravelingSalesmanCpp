#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "../headers/IPathSolver.h"
#include "../headers/CitySeed.h"
#include "../headers/GreedySolver.h"
#include "../headers/BruteforceSolver.h"
#include "../headers/Drawer.h"


using namespace std;
using namespace ts;

enum SolverType {
    Greedy,
    Bruteforce
};

SolverResult result;

IPathSolver *createSolver(enum SolverType type);

SolverResult startMenu();

void endMenu(SolverResult result);

void displayWindow();

void reshapeWindow(int, int);

int main(int argc, char **argv) {
    result = startMenu();
    endMenu(result);

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

SolverResult startMenu() {
    int citiesCout, solverType;
    cout << "Podaj liczbe miast";
    cin >> citiesCout;
    cout << "Podaj algorytm wykonania" << endl
         << "0: greedy" << endl
         << "1: bruteforce";
    cin >> solverType;

    IPathSolver *solver = createSolver((enum SolverType) solverType);

    CitySeed citySeed;

    vector<City> startCities = citySeed.SeedData(citiesCout);
    SolverResult solverResult = solver->Solve(startCities, 0);

    delete (solver);

    return solverResult;
}

void endMenu(SolverResult result) {
    cout << "KONIEC" << endl;
    cout << "Liczba permutacji:" << endl;
    cout << result.permutationCount << endl;
    cout << "Czas:" << endl;
    cout << result.time << " ms" << endl;

    cout << "Trasa: ";
    for (auto city : result.result) {
        cout << city.name + " ";
    }
}

IPathSolver *createSolver(enum SolverType type) {
    switch (type) {
        case Greedy:
            return new GreedySolver();
        case Bruteforce:
            return new BruteforceSolver();
    }
}

void displayWindow() {
    glClear(GL_COLOR_BUFFER_BIT);
    Drawer drawer(result.result);
    drawer.drawPath();
    drawer.drawCities();
    glutSwapBuffers();
}

void reshapeWindow(int width, int height) {
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 400, 0.0, 400, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

