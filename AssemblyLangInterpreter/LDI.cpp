//
//  LDI.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "LDI.hpp"

LDI::LDI(): state(), memInstr("LDI"){}

LDI::~LDI(){
    delete state;
}

void LDI::setMemInstr(){
    memInstr += " " + to_string(number);
}

void LDI::execute(){
    state->programCounter = (state->programCounter + 1);
    state->registerA = number;
}
