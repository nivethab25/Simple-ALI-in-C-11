//
//  State.hpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>
#include <map>
#include <string>
#include <array>
#include "SAL.hpp"

using namespace std;

// ALI machine state class 
class State{
    
public:
    int registerA;
    int registerB;
    array<string*, 256> memory;
    u_int8_t programCounter;
    u_int8_t zeroResultBit;
    u_int8_t overflowBit;
    map<string,int> symbolTable;
    map<string,SAL*> instructionTable;
    
    ~State();
    void perform();
    int getSymbol(string);
    void setSymbol(string,int);
    
};

#endif /* State_hpp */
