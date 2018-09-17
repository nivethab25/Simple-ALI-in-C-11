{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf400
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 This a an ALI for a SAL.\
\
The environment used for building this ALI is Mac.\
\
This ALI provides an option to execute each instruction of the SAL program loaded into the internal ALI memory either one line at a time starting from the current value of PC \
Or the entire program starting from the current value of PC.\
\
The ALI stops SAL program execution once it executes a \'93HLT\'94 instruction by setting the PC = -1. Any subsequent runs will display an error message \'93Control has reached end of SAL program\'94 and hence next execution can be performed only after a read of the program from file \'91input.sal\'92.\
\
It shows the status of Memory, Accumulator, Additional Register, PC, Overflow Bit and Zero Result Bit on the console after each execution.\
\
It also provides a command line option to save the state of the program into a file named \'91output.txt\'92\
\
The Memory is limited to 256 instructions (32-Bit each).\
\
If the SAL program execution exceeds 256 instructions, the ALI displays an error on console saying \'93Memory overflow!\'94.}