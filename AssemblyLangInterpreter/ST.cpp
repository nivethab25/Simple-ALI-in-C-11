//
//  ST.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "ST.hpp"

ST::ST(): state(), memInstr("ST"), regA(){}

ST::~ST(){
    delete state;
}

void ST::setMemInstr(){
    memInstr += " " + symbol;
}

void ST::execute(){
    int temp;
    state->programCounter = (state->programCounter + 1) ;
    temp = state->getSymbol(symbol);
    regA = to_string(state->registerA);
    state->memory[temp] = &regA;
}
