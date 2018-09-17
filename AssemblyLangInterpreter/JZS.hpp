//
//  JZS.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef JZS_hpp
#define JZS_hpp

#include <stdio.h>
#include <string>
#include "SAL.hpp"
#include "State.hpp"

// Transfers program control to the address (number) in memory if Zero Result Bit is set
class JZS: public SAL{
public:
    State *state;
    int number;
    string memInstr;
    
    JZS();
    virtual ~JZS();
    void setMemInstr();
    virtual void execute();
    
};


#endif /* JZS_hpp */
