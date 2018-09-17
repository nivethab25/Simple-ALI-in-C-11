//
//  LDA.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "LDA.hpp"

LDA::LDA(): state(), memInstr("LDA") {}

LDA::~LDA(){
    delete state;
}

void LDA::setMemInstr(){
    memInstr += " " + symbol;
}

void LDA::execute(){
    int temp;
    state->programCounter = (state->programCounter + 1);
    temp = state->getSymbol(symbol);
    state->registerA = stoi(*state->memory[temp]);
}
