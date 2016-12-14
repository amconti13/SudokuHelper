//
//  Board.cpp
//  SudokuHelper
//
//  Created by Arianna on 10/2/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "Board.hpp"
#include "BoardState.hpp"

const char* Board::type[] = { "row", "column", "box", "diag" };

//PRINT-------------------------------------------------------------------------
ostream& Board::print(ostream& out) const{
    out << "Non dash count: " << counter << endl;
    for(Cluster* cl : c) out << (*cl) << endl;
    return out;
}

//SUB---------------------------------------------------------------------------
//gets the array reference to the square at row j and column j
Square& Board::sub(int j, int k) { return bd[ (j - 1) * 9 + (k - 1) ]; }

//CONSTRUCTOR-------------------------------------------------------------------
//Creates squares and their states and makes the clusters
Board::Board(const char* filename, int clusts) throw ( badStream ) {
    //cout << "reopening in board class" << endl;
    inFile.open(filename);
    if (!inFile){
        inFile.close();
        throw fileNotOpening(filename);
    }
    
    char c, bType;
    inFile.get(bType);
    inFile.get(c);
    
    if ( c != '\n' ){
        inFile.close();
        throw notNewLine(filename);
    }
    //cout << bType << endl;
    for (int j = 1; j <= 9 ; ++j) { //row
        for (int k = 1; k <= 9 ; ++k) { //column
            inFile.get(c);
            //cout << c << endl;
            if ( c == '-') sub(j, k) = Square(c, j, k);
            else if('1' <= c && c <= '9'){
                sub(j, k) = Square(c, j, k);
                counter++;
            }
        }
        inFile.get(c);
        //cout << "c: " << c << endl;
        if ( c != '\n' && j == 9){
            inFile.close();
            throw notNewLine(filename);
        }
    }
    
    inFile >> c;
    if ( !inFile.eof() ) {
        inFile.close();
        throw endOfFileErr(filename);
    } else{
        inFile.close();
    }
   
    makeCluster();
    for(int k = 0; k < 81; ++k) bd[k].move('-');
}

//DESTRUCTOR--------------------------------------------------------------------
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

//ISDONE------------------------------------------------------------------------
const bool
Board::isDone(){
    if(counter >= 81) return true;
    return false;
}

//MOVE--------------------------------------------------------------------------
void
Board::move(int r, int c, char v){
    char before = sub(r,c).getValue();
    //cout << "in move(" << r << ", " << c << ", " << v << ")\n";
    sub(r,c).move(v);
    char after = sub(r,c).getValue();
    if((after != '-') && (before == '-')) counter++;
    if((after == '-') && (before != '-')) counter--;

}

//---------------------
char Board::getMarkChar(int row, int col) const {
    return bd[ (row - 1) * 9 + (col - 1) ].getValue();
}

//----------
string Board::getPossibilityString(int row, int col) const {
    short temp = bd[ (row - 1) * 9 + (col - 1) ].getPossibilities();
    string pString = "";
    
    for (int k = 0; k < 10; ++k) {
        pString += ((temp >> k) & 1) ? (char)('0' + k) : '-';
    }
    
    return pString;
}

//------------------------------------------------------------------------------
//DIAGONAL BOARD

diagBoard::diagBoard(const char* filename, int clusts): Board(filename, clusts){
    Square* squareArray1[9];
    Square* squareArray2[9];
    for(int x = 1, y = 9; x <= 9 ; ++x, --y){
        squareArray1[x-1] = &sub(x,x);
        squareArray2[x-1] = &sub(x,y);
    }
    c.push_back(new Cluster(type[diag],squareArray1));
    c.push_back(new Cluster(type[diag],squareArray2));
}

void Board::restoreState(BoardState *b){
    for(int x = 0; x < 81; ++x){
        bd[x] = (*b)[x];
    }
}









