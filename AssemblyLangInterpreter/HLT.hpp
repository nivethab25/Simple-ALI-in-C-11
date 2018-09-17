//
//  HLT.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef HLT_hpp
#define HLT_hpp

#include <stdio.h>
#include "SAL.hpp"
#include "State.hpp"

// Halts the SAL program execution by setting the PC = -1
class HLT: public SAL{

public:
    State *state;
    string memInstr;
    
    HLT();
    virtual ~HLT();
    void setMemInstr();
    virtual void execute();
    
};

#endif /* HLT_hpp */
