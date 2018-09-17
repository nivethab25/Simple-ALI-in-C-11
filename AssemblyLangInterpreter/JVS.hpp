//
//  JVS.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef JVS_hpp
#define JVS_hpp

#include <stdio.h>
#include "SAL.hpp"
#include "State.hpp"
#include <string>

// Transfers program control to the address (number) in memory if Overflow Bit is set
class JVS: public SAL{
public:
    State *state;
    int number;
    string memInstr;
    
    JVS();
    virtual ~JVS();
    void setMemInstr();
    virtual void execute();
    
};

#endif /* JVS_hpp */
