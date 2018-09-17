//
//  DEC.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef DEC_hpp
#define DEC_hpp

#include <stdio.h>
#include <string>
#include "SAL.hpp"
#include "State.hpp"

// Declares a symbol (var) at the address (addr) of the instruction in memory
class DEC: public SAL{
    
public:
    State *state;
    string var;
    int addr;
    string memInstr;
    
    DEC();
    virtual ~DEC();
    void setMemInstr();
    virtual void execute();
    
};

#endif /* DEC_hpp */
