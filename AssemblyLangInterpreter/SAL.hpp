//
//  SAL.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef SAL_hpp
#define SAL_hpp

#include <stdio.h>

// SAL Mixin class for SAL instruction
class SAL{
    
public:
    virtual ~SAL();
    virtual void execute()=0;
};

#endif /* SAL_hpp */
