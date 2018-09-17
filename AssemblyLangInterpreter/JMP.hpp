//
//  JMP.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef JMP_hpp
#define JMP_hpp

#include <stdio.h>
#include "SAL.hpp"
#include "State.hpp"
#include<string>

// Transfers program control to the address (number) in memory
class JMP: public SAL{
public:
    State *state;
    int number;
    string memInstr;
    
    JMP();
    virtual ~JMP();
    void setMemInstr();
    virtual void execute();
    
};
#endif /* JMP_hpp */
