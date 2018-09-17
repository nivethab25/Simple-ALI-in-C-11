//
//  HLT.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "HLT.hpp"

HLT::HLT(): state(), memInstr("HLT"){}

HLT::~HLT(){
    delete state;
}

void HLT::setMemInstr(){
}

void HLT::execute(){
    state->programCounter = -1;
}
