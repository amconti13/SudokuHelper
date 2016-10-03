//
//  Board.cpp
//  SudokuHelper
//
//  Created by Arianna on 10/2/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "Board.hpp"

ostream& Board::print(ostream& out){
    for (int j = 1; j <= 9 ; ++j) {
        for (int k = 1; k <= 9 ; ++k) {
            out << sub(j,k);
            
        }
        out << "\n";
    }
    return out;
}


//-------------------------------------------------------------------------
//sub function: gets the array reference to the square at row j and column j
Square& Board::sub(int j, int k){
    return bd[ (j - 1) * 9 + (k - 1) ];
}

//-------------------------------------------------------------------------
//Constructor
Board::Board(const char* filename) {
    cout << "In Board constructor.\n";
    cout << filename;
    inFile.open(filename);
    if (!inFile) fatal ("Error while trying to open ", filename);//syntax?
        else cout << "File: " << filename << " opened.\n";
    char c;
    for (int j = 1; j <= 9 ; ++j) {
        for (int k = 1; k <= 9 ; ++k) {
            inFile.get(c);
            if (c == '-' || ('1' <= c && c <= '9')) sub(j, k) = Square(c, j, k);
        }
        inFile.get(c);
        if ( c != '\n' ) fatal( "Error: Not new line character.\n");
    }
    inFile.get(c);
    cout << c;
    if ( !inFile.eof() ) fatal("Error: Not end of file.\n");
    
}

//-------------------------------------------------------------------------
//Destructor
Board::~Board() {
    cout << "Deleting Board...\n";
}
