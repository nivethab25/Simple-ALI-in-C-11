//
//  State.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include "State.hpp"

using namespace std;

void State::setSymbol(string symbol, int addr){
    symbolTable.insert(pair <string, int> (symbol, addr));
}

State::~State(){
    for(int i=0;i<256;i++)
        delete memory.at(i);
    for(map<string,SAL*>::iterator it = instructionTable.begin(); it!=instructionTable.end();it++)
        delete it->second;
}

int State::getSymbol(string symbol){
    map<string, int>::iterator itr;
    
    itr = symbolTable.find(symbol);
    if(itr != symbolTable.end())
        return itr->second;
    else
        return 0;
}

void State::perform(){
    SAL* instrPtr = instructionTable.find(*(memory.at(programCounter)))->second;
    instrPtr->execute();
    
}
