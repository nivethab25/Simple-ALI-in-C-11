//
//  LDB.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "LDB.hpp"

LDB::LDB(): state(), memInstr("LDB"){}

LDB::~LDB(){
    delete state;
}

void LDB::setMemInstr(){
    memInstr += " " + symbol;
}

void LDB::execute(){
    int temp;
    state->programCounter = (state->programCounter + 1) ;
    temp = state->getSymbol(symbol);
    state->registerB = stoi(*state->memory[temp]) ;
}
