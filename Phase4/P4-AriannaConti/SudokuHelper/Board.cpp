//
//  Board.cpp
//  SudokuHelper
//
//  Created by Arianna on 10/2/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "Board.hpp"

const char* Board::type[] = { "row", "column", "box" };

//PRINT-------------------------------------------------------------------------
ostream& Board::print(ostream& out){
    for(Cluster* cl : c) out << (*cl) << endl;
    return out;
}

//SUB---------------------------------------------------------------------------
//gets the array reference to the square at row j and column j
Square& Board::sub(int j, int k) { return bd[ (j - 1) * 9 + (k - 1) ]; }

//CONSTRUCTOR-------------------------------------------------------------------
//Creates squares and their states and makes the clusters
Board::Board(const char* filename) {
    inFile.open(filename);
    if (!inFile){
        inFile.close();
        fatal ("Error while trying to open ", filename);//syntax?
    }else cout << "File: " << filename << " opened.\n";
    char c;
    for (int j = 1; j <= 9 ; ++j) { //row
        for (int k = 1; k <= 9 ; ++k) { //column
            inFile.get(c);
            if (c == '-' || ('1' <= c && c <= '9')) sub(j, k) = Square(c, j, k);
        }
        inFile.get(c);
        if ( c != '\n' ){
            inFile.close();
            fatal( "Error: Not new line character.\n");
        }
    }
    inFile >> c;
    if ( !inFile.eof() ) {
        inFile.close();
        fatal("Error: Not end of file.\n");
    }
    makeCluster();
    for(int k = 0; k < 81; ++k) bd[k].move('-');
}

//DESTRUCTOR-------------------------------------------------------------------------
Board::~Board() {
    //cout << "Deleting Board...\n";
    for (Cluster* cl: c) delete cl;
}

//MAKE CLUSTER------------------------------------------------------------------
void Board::makeCluster(){
    Square* squareArray[9];
    //Row Clusters:
    for( int j = 1; j <= 9; ++j ) { //j = row, k = column
        for( int k = 1; k <= 9; ++k ) squareArray[ k-1 ] = &sub( j,k );
        c.push_back(new Cluster(type[row],squareArray));
    }
    //Column Clusters:
    for( int j = 1; j <= 9; ++j ) { //j = column, k = row
        for( int k = 1; k <= 9; ++k ) squareArray[ k-1 ] = &sub( k,j );
        c.push_back(new Cluster(type[column],squareArray));
    }
    //Box Clusters: for(row)|for(column)
    for( int a = 0; a < 9; a+=3 ) {
        for( int b = 0; b < 9; b+=3 ){     //Boxes
            for( int c = 1; c <= 3; ++c ) {
                for( int d = 1; d <= 3; ++d ){ //Squares
                squareArray[ (c-1)*3+(d-1) ] = &sub( a+c, b+d );
                }
            }
            c.push_back(new Cluster(type[box],squareArray));

        }
        
    }
}
