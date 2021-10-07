//a1744546
// emulate executing Hack CPU instructions
#include "iobuffer.h"
#include "symbols.h"
#include "hack_computer.h"
#include <bitset>
#include <vector>
#include <iostream>

// to make out programs a bit neater
using namespace std ;

using namespace CS_IO_Buffers ;
using namespace CS_Symbol_Tables ;
using namespace Hack_Computer ;

// This program must emulate the execution of Hack CPU instructions
//
// To read from registers A, D or PC, use read_A(), read_D() or read_PC()
// To write to registers A, D or PC, use write_A(value), write_D(value) or write_PC(value)
//
// To read from ROM use read_ROM(address)
// To read from RAM use read_RAM(address)
// To write to RAM use write_RAM(address,value)
//
// All values returned by a read_*() function are 16-bit unsigned integers
// All parameters passed to a write_*() function are 16-bit unsigned integers
//

/*****************   REPLACE THE FOLLOWING CODE  ******************/
static void jump1(uint16_t jmp,uint16_t value)
{
    switch (jmp) {
            //JGT
        case 1:
                if(value > 0 && value<32768)
                {
                    write_PC(read_A());
                }else{
                    write_PC(read_PC()+1);
                }
            break;
            //JEQ
        case 2:
            if(value == 0)
            {
                write_PC(read_A());
            }else{
                write_PC(read_PC()+1);
            }
            break;
            //JGE
        case 3:
            if(value >= 0 && value<32768)
            {
                write_PC(read_A());
            }else{
                write_PC(read_PC()+1);
            }
            break;
            //JLT
        case 4:
            if(value > 32768)
            {
                write_PC(read_A());
            }else{
                write_PC(read_PC()+1);
            }
            break;
            //JNE
        case 5:
            if(value != 0)
            {
                write_PC(read_A());
            }else{
                write_PC(read_PC()+1);
            }
            break;
            //JLE
        case 6:
            if(value > 32768 || value ==0)
            {
                write_PC(read_A());
            }else{
                write_PC(read_PC()+1);
            }
            break;
            //Jmp
        case 7:
            write_PC(read_A());
            break;
        default:
            write_PC(read_PC()+1);
    }
}
static void write_memory(uint16_t des, uint16_t value)
{
    switch (des)
    {
        case 4: write_A(value);
            break;
        case 2: write_D(value);
            break;
        case 1: write_RAM(read_A(),value);
            break;
        default:
            break;
    }
}
// disassemble an instruction - convert binary to symbolic form
// A instructions should be "@" followed by the value in decimal
// C instructions should be dest=alu;jump
// omit dest= if all destination bits are 0
// omit ;jump if all jump bits are 0
string disassemble_instruction(uint16_t instruction)
{
    int ainst = instruction >> 15;
    uint16_t cinst = instruction >> 13;
    if ( ainst == 0 )
    {
        return "@"+to_string(instruction);
    }
    if ( cinst == 7 )
    {
        //c1-c6
        uint16_t c1_c6 = instruction >> 6;
        c1_c6 = c1_c6 << 9;
        c1_c6 = c1_c6 >> 9;
        
        //des
        uint16_t des = instruction >> 3;
        des = des << 13;
        des = des >> 13;
        
        //jmp
        uint16_t jmp = instruction << 13;
        jmp = jmp >> 13;
        return destination(des)  + aluop(c1_c6) + jump(jmp);
    }
    return "" ;
}

// emulate a cpu instruction - the Hack Computer has been initialised
// the PC contains the address in ROM of the instruction to execute
// if you want to produce additional output, use write_to_traces()
static void emulate_instruction()
{
    uint16_t inst = read_ROM(read_PC() );
    int ainst = inst >> 15;
    uint16_t cinst = inst >> 13;
    
    if ( ainst == 0 )
    {
        write_A(inst);
        write_PC(read_PC()+1);
    }
    if ( cinst == 7 )
    {
        uint16_t c1_c6 = inst >> 6;
        c1_c6 = c1_c6 << 9;
        c1_c6 = c1_c6 >> 9;
        
        uint16_t des = inst >> 3;
        des = des << 13;
        des = des >> 13;
        
        uint16_t jmp = inst << 13;
        jmp = jmp >> 13;
        // D&A
        if ( c1_c6 == 0 )
        {
            write_memory(des,read_A());
            write_PC(read_PC()+1);
        }
        //M-1
        if ( c1_c6 == 114 )//1110010
        {
            write_PC(read_PC()+1);
        }
        // A=0
        if ( c1_c6 == 42 )//101010
        {
            write_memory(des,0);
            write_PC(read_PC()+1);
        }
        //-A
        if ( c1_c6 == 51 )//110011
        {
            write_memory(des,~read_A() + 1);
            jump1(jmp,~read_A()+1);
        }
        //A+1
        if ( c1_c6 == 55 )//110111
        {
            write_memory(des,read_A() + 1);
            jump1(jmp,read_A() + 1);
        }
        //M = -1
        if ( c1_c6 == 58 )//111010
        {
            write_memory(des,-1);
            jump1(jmp,-1);
        }
        //M = 1
        if ( c1_c6 == 63 )//111111
        {
            write_memory(des,1);
            jump1(jmp,1);
        }
        //D&M
        if ( c1_c6 == 64 )//1000000
        {
            write_memory(des,read_D()&read_RAM(read_A()));
            jump1(jmp,read_D()&read_RAM(read_A()));
        }
    }
}


/*****************        DOWN TO HERE         ******************/

// if the first command line argument is "D" the test output must display disassembled instructions
bool display_disassembled_instructions = false ;

// this function only calls disassemble_instruction if required
// it is called from more_cpu_tests() and is passed the instruction being emulated
string disassemble(uint16_t instruction)
{
    if ( display_disassembled_instructions ) return disassemble_instruction(instruction) ;

    // default is to display instruction in binary
    return "\"" + std::bitset<16>(instruction).to_string() + "\"" ;
}



// main program
int main(int argc,char **argv)
{
    // force all output to be immediate - the test scripts will override this
    config_output(iob_immediate) ;
    config_errors(iob_immediate) ;

    // is the first command line argument "D", ie does the test output include disassembly of the instruction being emulated
    display_disassembled_instructions = argc > 1 && string(argv[1]) == "D" ;

    // more_cpu_tests() will initialise the next test and return true
    // if there are no more tests to be run, it returns false
    // more_cpu_tests() also outputs the results of the previous test
    while ( more_cpu_tests(disassemble) )
    {
        emulate_instruction() ;
    }

    // flush the output and any errors
    print_output() ;
    print_errors() ;
}

