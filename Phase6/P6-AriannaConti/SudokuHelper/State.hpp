//
//  State.hpp
//  SudokuHelper
//
//  Created by Arianna on 9/18/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include "tools.hpp"
#include "streamExceptions.hpp"
#include "gameExceptions.hpp"
class Cluster;

class State {
protected:
    char v; //value
    bool f; //fixed flag. [true = fixed]
    short p;//possibilities
    
public:
    State( char value );
    ~State() = default;
    void move(char ch);
    void erase();//cant write delete()
    ostream& print( ostream& out );
};

inline ostream& operator<< (ostream& out, State& state) {
    state.print(out);
    //print( out );
    return out;
}

//----------------------------------------------------------------
//Square
//Includes information: row, column, relationship
//Relationship: with other squares in the same row, column and box
class Square : public State {
private:
    short r;    //row
    short c;    //column
    short int possCount;
    vector<Cluster*> clues; //vector of cluster pointers
    
public:
    Square();
    Square( char ch, short row, short column );
    ~Square();
    ostream& print( ostream& out );
    inline void addCluster(Cluster* cluster) {
        //cout << "3\t in addCluster\n";
        clues.push_back(cluster);
        //cout << "3.1\t pushed back cluster*\n" ;
    };
    void move(char ch);
    void turnOff( int n );
    char getValue() { return v; }
};


/* OR HERE
inline void addCLuster(Cluster* cluster){
    cV.push_back(cluster);
}
*/

inline ostream& operator<< (ostream& out, Square& square){
    square.print(out);
    return out;
}

#endif /* State_hpp */
