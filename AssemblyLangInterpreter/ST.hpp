//
//  ST.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef ST_hpp
#define ST_hpp

#include <stdio.h>
#include<string>
#include "SAL.hpp"
#include "State.hpp"

// Stores the content of register A into memory at address of symbol
class ST: public SAL{

public:
    State *state;
    string symbol;
    string regA;
    string memInstr;
    
    ST();
    virtual ~ST();
    void setMemInstr();
    virtual void execute();
    
};

#endif /* ST_hpp */
