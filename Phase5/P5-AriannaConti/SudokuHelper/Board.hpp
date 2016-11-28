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

enum ClusterT{row, column, box};

class Board {
private:
    Square bd[81];
    ifstream inFile;
    void makeCluster();
    vector<Cluster*> c;
    static const char* type[3];
    int counter = 0;
public:
    ~Board();
    Board(const char* filename);
    Square& sub(int j, int k);
    ostream& print( ostream& out);
    bool isDone();
    void move(int r, int c, char v);
};

inline ostream& operator<< (ostream& out, Board& b){
    b.print(out);
    return out;
}

#endif /* Board_hpp */
