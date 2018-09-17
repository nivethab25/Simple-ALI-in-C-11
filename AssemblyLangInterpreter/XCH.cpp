//
//  XCH.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "XCH.hpp"

XCH::XCH(): state(), memInstr("XCH"){}

XCH::~XCH(){
    delete state;
}

void XCH::setMemInstr(){
    
}

void XCH::execute(){
    int temp;
    state->programCounter = (state->programCounter + 1) ;
    temp = state->registerA;
    state->registerA = state->registerB;
    state->registerB = temp;
}
