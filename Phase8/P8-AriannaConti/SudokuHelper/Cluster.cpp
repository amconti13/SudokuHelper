//
//  Cluster.cpp
//  SudokuHelper
//
//  Created by Arianna on 10/10/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "Cluster.hpp"

//CONSTRUCTOR-------------------------------------------------------------------
//Creates an instance of a cluser
//puts squares in the cluster and lets each square know what cluser it is in
Cluster::Cluster( const char* t, Square* sq[] ) : type(t) {
    for(int k = 0; k < 9; ++k){
        square[k] = sq[k];
        square[k]->addCluster(this);
    }
}

//SHOOP-------------------------------------------------------------------------
//Takes the input and takes away the posibility of that spot replaces it with
//to show it is no longer possible
void Cluster::shoop(char val){
    int x = int(val) - 48;
    for(int k = 0; k < 9; ++k){
        square[k]->turnOff(x);
    }
}

//PRINT-------------------------------------------------------------------------
ostream& Cluster::print(ostream& out){
    for(int k = 0; k < 9; ++k){
        out << "Type: " << type << "   ";
        out << (*square[k]);
    }
    return out;
}
