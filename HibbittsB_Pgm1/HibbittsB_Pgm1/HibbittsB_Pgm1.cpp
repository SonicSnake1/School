// File: HibbittsB_Pgm1.cpp
// Description: Assignment 1
// Author: Hibbitts, Brandon
// Course: CS 3350, Spring 2025
#include <iostream>
#include <iomanip>
#include <string>
#include "Shapes.h"
#include "Polygon.h"

using namespace std;

void showAreaPerimeter(Polygon* p) {
    cout << setprecision(2) << fixed;
    cout << "Area is: " << p->area() << endl;
    cout << "Perimeter is: " << p->perimeter() << endl;
}

bool isNumeric(string str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int convert2Numeric(string str) {
    return stoi(str);
}

int getUserChoice() {
    string choice;
    cout << "Which Shape [1-9]\n";
    cout << "1. Generic Triangle\n";
    cout << "2. Isosceles Triangle\n";
    cout << "3. Equilateral Triangle\n";
    cout << "4. Generic Quadrilateral\n";
    cout << "5. Rectangle\n";
    cout << "6. Square\n";
    cout << "7. Pentagon\n";
    cout << "8. Hexagon\n";
    cout << "9. Octagon\n";
    cin >> choice;
    cout << endl;

    while (!isNumeric(choice) || stoi(choice) < 1 || stoi(choice) > 9) {
        cout << "Invalid input. Please enter a number between 1 and 9: ";
        cin >> choice;
        cout << endl;
    }

    return convert2Numeric(choice);
}

Polygon* createPolygon(int choice) {
    int sideA, sideB, sideC, sideD;
    double angle;
    switch (choice) {
    case 1:
        cout << "Enter three sides: ";
        cin >> sideA >> sideB >> sideC;
        return new Triangle(sideA, sideB, sideC);
    case 2:
        cout << "Enter two sides: ";
        cin >> sideA >> sideB;
        return new IsoscelesTriangle(sideA, sideB);
    case 3:
        cout << "Enter one side: ";
        cin >> sideA;
        return new EquilateralTriangle(sideA);
    case 4:
        cout << "Enter four sides and an angle: ";
        cin >> sideA >> sideB >> sideC >> sideD >> angle;
        return new Quadrilateral(sideA, sideB, sideC, sideD, angle);
    case 5:
        cout << "Enter two sides: ";
        cin >> sideA >> sideB;
        return new Rectangle(sideA, sideB);
    case 6:
        cout << "Enter one side: ";
        cin >> sideA;
        return new Square(sideA);
    case 7:
        cout << "Enter one side: ";
        cin >> sideA;
        return new Pentagon(sideA);
    case 8:
        cout << "Enter one side: ";
        cin >> sideA;
        return new Hexagon(sideA);
    case 9:
        cout << "Enter one side: ";
        cin >> sideA;
        return new Octagon(sideA);
    default:
        return nullptr;
    }
}

int main() {
    char c = 'y';
    while (tolower(c) == 'y') {
        int choice = getUserChoice();
        Polygon* p = createPolygon(choice);

        if (p != nullptr) {
            showAreaPerimeter(p);
            delete p;
        }
        else {
            cout << "Invalid choice!\n";
        }

        cout << "Another? [Y/N]: ";
        cin >> c;
        cout << endl;
    }

    return 0;
}
