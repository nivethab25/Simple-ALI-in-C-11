//
//  JVS.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "JVS.hpp"

JVS::JVS(): state(), memInstr("JVS"){}

JVS::~JVS(){
    delete state;
}

void JVS::setMemInstr(){
    memInstr += " " + to_string(number);
}

void JVS::execute(){
    int temp;
    temp = state->overflowBit;
    if (temp>0)
        state->programCounter = number ;
    else
        state->programCounter = (state->programCounter + 1) ;
}
