//
//  LDI.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef LDI_hpp
#define LDI_hpp

#include <stdio.h>
#include <string>
#include "SAL.hpp"
#include "State.hpp"

// Loads the integer value (number) into Register A
class LDI: public SAL{

public:
    State *state;
    int number;
    string memInstr;
    
    LDI();
    virtual ~LDI();
    void setMemInstr();
    virtual void execute();
    
};

#endif /* LDI_hpp */
