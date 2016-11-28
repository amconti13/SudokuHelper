//
//  main.cpp
//  SudokuHelper
//
//  Created by Arianna on 9/27/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "game.hpp"


void gameTest(){
    cout << "\nIn gameTest(): Sets up the game.\n";
    Game game;
    game.run();
}

void boardTest() {
    cout << "\nIn boardTest(): Takes input file and sets up the board.";
    Board board("sudo-test1.txt");
    cout << "Original clusters\n" << board << endl;
    
    cout << "Make move 2 into (9,7): possiblity should be deleted, value should"
            <<" change.\n";
    board.sub(9,7).move('2');
    cout << board << endl;

    cout << "Make move - into (1,1): nothing should change\n";
    board.sub(1,1).move('-');
    cout << board << endl;

    cout << "Make move 5 into (8,8): nothing should change\n";
    board.sub(8,8).move('5');
    cout << board << endl;
}

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
    cout << "Run boardTest() [now creates clusters]\n";
    //stateTest();
    //squareTest();
    //boardTest();
    gameTest();
    bye();
}
