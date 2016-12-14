//
//  Cluster.hpp
//  SudokuHelper
//
//  Created by Arianna on 10/10/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#ifndef Cluster_hpp
#define Cluster_hpp

#include "State.hpp"


class Cluster{
private:
    const char* type;
    Square* square[9];
public:
    void shoop(char val);
    Cluster( const char* ClusterType, Square* sq[] );
    ostream& print( ostream& out);
};

inline ostream& operator<< (ostream& out, Cluster& c){
    c.print(out);
    return out;
}

#endif /* Cluster_hpp */
