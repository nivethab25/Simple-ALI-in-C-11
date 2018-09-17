//
//  LDA.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef LDA_hpp
#define LDA_hpp

#include <stdio.h>
#include <string>
#include "SAL.hpp"
#include "State.hpp"

// Loads the value at address of symbol specified in memory into Register A
class LDA: public SAL{
public:
    State *state;
    string symbol;
    string memInstr;
    
    LDA();
    virtual ~LDA();
    void setMemInstr();
    virtual void execute();
    
};

#endif /* LDA_hpp */
