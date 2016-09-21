//
//  State.hpp
//  SudokuHelper
//
//  Created by Arianna on 9/21/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include "tools.hpp"

class State{
private:
    char v; //value
    bool f; //fixed flag. [true = fixed]
    short p;//possibilities
    
public:
    //Did I initialize correctly and use ternary condition okay?
    State( char value );
    
    ~State() = default;
    
    void move(char ch);
    void erase();//cant write delete()
    ostream& print( ostream& out );
    
    
    
    
};

//inline

inline ostream& operator<< (ostream& out, State& state) {
    state.print(out);
    //print( out );
    return out;
}

#endif /* State_hpp */