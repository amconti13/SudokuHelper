//
//  Stack.hpp
//  SudokuHelper
//
//  Created by Arianna on 12/13/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include "BoardState.hpp"

template<class T>
class Stack : vector<T>{
private:
    
public:
    inline Stack() = default;
    inline ~Stack() = default;
    
    inline void pop(){this->pop_back();}
    inline T top(){return this->back();}
    inline void push( T t ){this->push_back( t );}
    inline int size() {return (int)vector<T>::size();}
    inline void zap() {for(int x = size() ; x > 0 ; --x) pop(); };
};

#endif /* Stack_hpp */
