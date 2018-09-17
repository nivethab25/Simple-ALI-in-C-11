//
//  DEC.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "DEC.hpp"

DEC::DEC(): state(), memInstr("DEC"){}

DEC::~DEC(){
    delete state;
}

void DEC::setMemInstr(){
    memInstr += " " + var;
}

void DEC::execute(){
    state->programCounter = (state->programCounter + 1);
    state->setSymbol(var, addr);
    state->memory.at(addr) = &var;
}
