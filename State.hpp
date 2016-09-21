//
//  State.hpp
//  P1_AriannaConti
//
//  Created by Arianna on 9/18/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include "tools.hpp"

class State{
private:
    char v; //value
    short p;//possibilities
    bool f; //fixed flag. [true = fixed]
    
public:
    //Did I initialize correctly and use ternary condition okay?
    State( char value ) :
        v( value ),
        p( (value == '-') ? 0x3fe : 0 ),
        f( (value == '-') ? false : true ){}
    
    ~State() = default;
    
    void move(char ch);
    void del();//cant write delete()
    ostream& print( ostream& out );
    
    
    
    
};

//inline

inline ostream& operator<< (ostream& out) {
    //print( out );
    return out;
}












#endif /* State_hpp */
