//
//  Board.hpp
//  SudokuHelper
//
//  Created by Arianna on 10/2/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include "State.hpp"
#include "Cluster.hpp"
#include "CanView.hpp"

class BoardState;
enum ClusterT{row, column, box, diag};

class Board: public CanView {
protected:
    vector<Cluster*> c;
    static const char* type[4];
    Square bd[81];

private:
    ifstream inFile;
    void makeCluster();
    int counter = 0;
public:
    ~Board();
    Board(const char* filename, int clusters = 27) throw ( badStream );
    Square& sub(int j, int k);
    ostream& print( ostream& out) const;
    const bool isDone();
    void move(int r, int c, char v);
    char getMarkChar(int row, int col) const;
    string getPossibilityString(int row, int col) const;
    void restoreState( BoardState* b );
    
    inline Square operator [] (int x) {return bd[x];}
    inline State getState(int x){return bd[x];}
};

inline ostream& operator<< (ostream& out, Board& b){
    b.print(out);
    return out;
}

class diagBoard : private Board{
    public:
    diagBoard();
    diagBoard(const char* filename, int clusts) ;
};

#endif /* Board_hpp */
