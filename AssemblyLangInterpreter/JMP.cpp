//
//  JMP.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "JMP.hpp"

JMP::JMP(): state(), memInstr("JMP"){}

JMP::~JMP(){
    delete state;
}

void JMP::setMemInstr(){
   memInstr +=  " " + to_string(number);
}

void JMP::execute(){
    state->programCounter = number ;
}

