//
//  main.cpp
//  1-Sudoku-AConti
//
//  Created by Arianna on 9/27/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "State.hpp"



void unitTest(){
    char c = '2';
    State state(c);
    cout << state << endl;
}


int main(void) {
    banner();
    
    unitTest();
    
    bye();
}
