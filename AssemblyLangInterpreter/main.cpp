//
//  main.cpp
//  AssemblyLangInterpreter
//
//  Created by Nivetha Babu on 4/29/18.
//  Copyright © 2018 Nivetha Babu. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "State.hpp"
#include "ADD.hpp"
#include "DEC.hpp"
#include "HLT.hpp"
#include "JMP.hpp"
#include "JVS.hpp"
#include "JZS.hpp"
#include "LDA.hpp"
#include "LDB.hpp"
#include "LDI.hpp"
#include "ST.hpp"
#include "XCH.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    State *aLI = new State();
    int count = 0;
    char command;
    string line;
    
    cout<<"\n---Simple Assembly Language Interpreter---";
    
    while(1){
        
        cout<<"\n\n--SAL Menu--";
        cout<<"\ni - Read SAL program from input.sal\nd - Execute in Debug mode\nr - Run the program to completion\ns - Save the program state\nq - Quit the ALI\nEnter a command : ";
        
        cin>>command;
        
        // read SAL program from input.sal and load into ALI internal memory
        if(command == 'i'){
            
            //resetting ALI state for multiple runs of the program
            count = 0;
            aLI->zeroResultBit = 0;
            aLI->programCounter = 0;
            aLI->overflowBit = 0;
            aLI->registerA = 0;
            aLI->registerB = 0;
            
            //reset memory
            aLI->memory.fill(nullptr);
            
            cout<<"\n--Contents of SAL program read from input.sal file--";
            ifstream inputFile("input.sal");
            while(getline(inputFile, line)){
                
                if(count > 255){
                    cout<<"Memory overflow!! Terminating program read operation...";
                    exit(0);
                }
                
                string opcode;
                string operand;
                istringstream iss(line);
                
                if(iss>>opcode>>operand)
                    cout<<"\n"<<opcode<<" "<<operand;
                else{
                    iss>>opcode;
                    cout<<"\n"<<opcode;
                }
                if(opcode == "ADD"){
                    ADD *add = new ADD();
                    add->state = aLI;
                    add->setMemInstr();
                    aLI->memory.at(count) = &add->memInstr;
                    aLI->instructionTable.insert(pair<string,SAL*>(add->memInstr,add));
                }
                else if(opcode == "DEC"){
                    DEC *dec = new DEC();
                    dec->var = operand;
                    dec->state = aLI;
                    dec->addr = count;
                    dec->setMemInstr();
                    aLI->memory.at(count) = &dec->memInstr;
                    aLI->instructionTable.insert(pair<string,SAL*>(dec->memInstr,dec));
                }
                else if(opcode == "HLT"){
                    HLT *hlt = new HLT();
                    hlt->state = aLI;
                    hlt->setMemInstr();
                    aLI->memory.at(count) = &hlt->memInstr;
                    aLI->instructionTable.insert(pair<string,SAL*>(hlt->memInstr,hlt));
                }
                else if(opcode == "JVS"){
                    JVS *jvs = new JVS();
                    jvs->number = stoi(operand);
                    jvs->state = aLI;
                    jvs->setMemInstr();
                    aLI->memory.at(count) = &jvs->memInstr;
                    aLI->instructionTable.insert(pair<string,SAL*>(jvs->memInstr,jvs));
                }
                else if(opcode == "JZS"){
                    JZS *jzs = new JZS();
                    jzs->number = stoi(operand);
                    jzs->state = aLI;
                    jzs->setMemInstr();
                    aLI->memory.at(count) = &jzs->memInstr;
                    aLI->instructionTable.insert(pair<string,SAL*>(jzs->memInstr,jzs));
                }
                else if(opcode == "LDA"){
                    LDA *lda = new LDA();
                    lda->symbol = operand;
                    lda->state = aLI;
                    lda->setMemInstr();
                    aLI->memory.at(count) = &lda->memInstr;
                    aLI->instructionTable.insert(pair<string,SAL*>(lda->memInstr,lda));
                }
                else if(opcode == "LDB"){
                    LDB *ldb = new LDB();
                    ldb->symbol = operand;
                    ldb->state = aLI;
                    ldb->setMemInstr();
                    aLI->memory.at(count) = &ldb->memInstr;
                    aLI->instructionTable.insert(pair<string,SAL*>(ldb->memInstr,ldb));
                }
                else if(opcode == "LDI"){
                    LDI *ldi = new LDI();
                    ldi->number = stoi(operand);
                    ldi->state = aLI;
                    ldi->setMemInstr();
                    aLI->memory.at(count) = &ldi->memInstr;
                    aLI->instructionTable.insert(pair<string,SAL*>(ldi->memInstr,ldi));
                }
                else if(opcode == "ST"){
                    ST *st = new ST();
                    st->symbol = operand;
                    st->state = aLI;
                    st->setMemInstr();
                    aLI->memory.at(count) = &st->memInstr;
                    aLI->instructionTable.insert(pair<string,SAL*>(st->memInstr,st));
                }
                else if(opcode == "XCH"){
                    XCH *xch = new XCH();
                    xch->state = aLI;
                    xch->setMemInstr();
                    aLI->memory.at(count) = &xch->memInstr;
                    aLI->instructionTable.insert(pair<string,SAL*>(xch->memInstr,xch));
                }
                else if(opcode == "JMP"){
                    JMP *jmp = new JMP();
                    jmp->number = stoi(operand);
                    jmp->state = aLI;
                    jmp->setMemInstr();
                    aLI->memory.at(count) = &jmp->memInstr;
                    aLI->instructionTable.insert(pair<string,SAL*>(jmp->memInstr,jmp));
                }
                count++;
            }
            
            inputFile.close();
            
        }
        
        // Execute one line of SAL program in debug mode
        else if(command == 'd'){
            if(count == 0)
                cout<<"\nNo SAL program preloaded in memory!!";
            else if(aLI->programCounter != (u_int8_t)-1){
                cout<<"\nExecuting instruction at current value of PC in memory...\n";
                aLI->perform();
                cout<<"\nThe Program state after the execution is...\n";
                cout<<"\nState of Memory\n";
                for (int i = 0; i<256; i++) {
                    cout<<((aLI->memory.at(i))!=nullptr?*(aLI->memory.at(i)):"null")<<"\n";
                }
                cout<<"\nProgram Counter = "<<((int)(aLI->programCounter) == 255? -1 :(int)(aLI->programCounter));
                cout<<"\nRegister A = "<<aLI->registerA;
                cout<<"\nRegister B = "<<aLI->registerB;
                cout<<"\nZero Result Bit = "<<(int)(aLI->zeroResultBit);
                cout<<"\nOverflow Bit = "<<(int)(aLI->overflowBit);
            }
            else
                cout<<"\nControl reached end of SAL profgram!! Execution terminating now...";
        }
        
        // Execute SAL program to completion
        else if(command == 'r'){
            if(count == 0)
                cout<<"\nNo SAL program preloaded in memory!!";
            else if(aLI->programCounter != (u_int8_t)-1){
                cout<<"\nExecuting all the instructions starting from the instruction at the current value of PC in memory till the end of program...\n";
                int ct = 0;
                while (aLI->programCounter != (u_int8_t)-1 && ct < 256) {
                    aLI->perform();
                    ct++;
                }
                cout<<"\nThe Program state after the execution is...\n";
                cout<<"\nState of Memory\n";
                for (int i = 0; i<256; i++) {
                    cout<<((aLI->memory.at(i))!=nullptr?*(aLI->memory.at(i)):"null")<<"\n";
                }
                cout<<"\nProgram Counter = "<<((int)(aLI->programCounter) == 255? -1 :(int)(aLI->programCounter));
                cout<<"\nRegister A = "<<aLI->registerA;
                cout<<"\nRegister B = "<<aLI->registerB;
                cout<<"\nZero Result Bit = "<<(int)(aLI->zeroResultBit);
                cout<<"\nOverflow Bit = "<<(int)(aLI->overflowBit);
                continue;
            }
            else
                cout<<"\nControl reached end of SAL profgram!! Execution terminating now...";
        }
        
        // Save program state to file output.txt
        else if(command == 's'){
            cout<<"\nSaving Program State to file output.txt ....";
            ofstream outputFile("output.txt");
            outputFile<<"State of Memory\n";
            for (int i = 0; i<256; i++) {
                outputFile<<((aLI->memory.at(i))!=nullptr?*(aLI->memory.at(i)):"null")<<"\n";
            }
            outputFile<<"\nProgram Counter = "<<((int)(aLI->programCounter) == 255? -1 :(int)(aLI->programCounter));
            outputFile<<"\nRegister A = "<<aLI->registerA;
            outputFile<<"\nRegister B = "<<aLI->registerB;
            outputFile<<"\nZero Result Bit = "<<(int)(aLI->zeroResultBit);
            outputFile<<"\nOverflow Bit = "<<(int)(aLI->overflowBit);
            outputFile.close();
        }
        
        // Quit ALI
        else if(command == 'q'){
            cout<<"\nExiting ALI....";
            exit(0);
        }
        
        else{
            cout<<"\nInvalid command!!";
        }
        
    }
    
    return 0;
}
