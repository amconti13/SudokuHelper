//
//  main.cpp
//  Sudoku Helper
//
//  Created by Arianna on 9/18/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "State.hpp"

void stateTest() {
    char c = '2';
    cout << "\nIn stateTest(): Creates the state of an object including value,"
         << " possibilities and if it is fixed or not.\n";
    State state(c);
    cout << "Created state object: state(" << c << ")\n";
    cout << "Output (list of possibilities): ";
    cout << state << endl;
}

void squareTest() {
    char a = '1';
    cout << "\nIn squareTest(): Creates a square object including value, row"
         << " and column.\n";
    Square square1, square2(a,1,1);
    cout << "Created square objects: square1 and square2(" << a << ", 1, 1)\n";
    cout << "Output (square1): ";
    cout << square1 << endl;
    cout << "Output (square2): ";
    cout << square2 << endl;
}

int main(void) {
    banner();
    cout << "Run stateTest() and squareTest()\n";
    stateTest();
    squareTest();
    
    bye();
}
