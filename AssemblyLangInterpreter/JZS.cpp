//
//  JZS.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "JZS.hpp"

JZS::JZS(): state(), memInstr("JZS"){}

JZS::~JZS(){
    delete state;
}

void JZS::setMemInstr(){
    memInstr += " " + to_string(number);
}

void JZS::execute(){
    int temp;
    temp = state->zeroResultBit;
    if (temp>0)
        state->programCounter = number;
    else
        state->programCounter = (state->programCounter + 1);
}
