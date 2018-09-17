//
//  XCH.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef XCH_hpp
#define XCH_hpp

#include <stdio.h>
#include <string>
#include "SAL.hpp"
#include "State.hpp"

// Exchanges the contents of Register A amd Register B
class XCH: public SAL{

public:
    State *state;
    string memInstr;
    
    XCH();
    virtual ~XCH();
    void setMemInstr();
    virtual void execute();
    
};
#endif /* XCH_hpp */
