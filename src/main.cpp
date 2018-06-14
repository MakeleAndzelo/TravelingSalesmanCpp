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

/**
 * Typ wyliczeniowy reprezentujacy zastosowane metody
 */
enum SolverType {
    Greedy,
    Bruteforce
};

/**
 * @var result Zmienna globalna przechowujaca wyniki dzialania algorytmow
 */
SolverResult result;

/**
 * Funkcja tworzaca obiekt szukajacy drogi
 *
 * @param type zmienna opisuje, ktory sposob wybrac
 */
IPathSolver *createSolver(enum SolverType type);

/**
 * Funkcja wypisuje poczatek menu, pobiera opcje od uzytkownika
 */
SolverResult startMenu();

/**
 * Funkcja wypisuje koniec menu, wypisuje wyniki dzialania algorytmu
 */
void endMenu(SolverResult result);

/**
 * Funkcja inicjujaca okno OpenGl
 */
void displayWindow();

/**
 * Funkcja odpowiedzialna za zmienianie rozmiaru okna OpenGl
 */
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
    system("clear");
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

