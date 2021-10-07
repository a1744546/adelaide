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
        uint16_t c1_c6 = instruction >> 6;
        c1_c6 = c1_c6 << 9;
        c1_c6 = c1_c6 >> 9;
        return aluop(c1_c6);
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
        // D&A only need PC++
        if ( c1_c6 == 0 )
        {
            write_PC(read_PC()+1);
        }
        //M-1
        else if ( c1_c6 == 114 )
        {
            write_PC(read_PC()+1);
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

