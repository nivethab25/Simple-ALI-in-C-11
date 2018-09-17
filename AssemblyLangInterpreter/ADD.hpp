//
//  ADD.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef ADD_hpp
#define ADD_hpp

#include <stdio.h>
#include "SAL.hpp"
#include "State.hpp"
#include <string>

// Adds contents of register A and register B and stores the sum in register A
class ADD: public SAL{
    
public:
    State *state;
    string memInstr;
    
    ADD();
    virtual ~ADD();
    void setMemInstr();
    virtual void execute();
    
};

#endif /* ADD_hpp */
