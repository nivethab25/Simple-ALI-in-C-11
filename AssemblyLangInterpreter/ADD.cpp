//
//  ADD.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "ADD.hpp"

ADD::ADD(): state(), memInstr("ADD") {}

ADD::~ADD(){
    delete state;
}

void ADD::setMemInstr(){
}

void ADD::execute(){
    int tempA, tempB, temp, sum, flag;
    state->programCounter = (state->programCounter + 1);
    tempA = state->registerA;
    tempB = state->registerB;
    
    flag = 0;
    
    sum  = tempA + tempB;
    
    if(tempA > 0 && tempB > 0 && sum < 0){
        state->overflowBit = 1;
        state->registerA = sum;
        flag = 1;
    }
    
    else if(tempA < 0 && tempB <0 && sum > 0){
        state->overflowBit = 1;
        state->registerA = sum;
        flag = 1;
    }
    
    else
        state->registerA = sum;
    
    temp = sum;
    
    if(flag == 0)
        state->overflowBit = 0;
    
    if (temp == 0)
        state->zeroResultBit = 1;
    else
        state->zeroResultBit = 0;
}
