//
//  LDB.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef LDB_hpp
#define LDB_hpp

#include <stdio.h>
#include<string>
#include "SAL.hpp"
#include "State.hpp"

// Loads the value at address of symbol specified in memory into Register B
class LDB: public SAL{

public:
    State *state;
    string symbol;
    string memInstr;
    
    LDB();
    virtual ~LDB();
    void setMemInstr();
    virtual void execute();
    
};

#endif /* LDB_hpp */
