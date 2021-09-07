// tokeniser implementation for the workshop example language

#include "iobuffer.h"
#include "tokeniser-extras.h"

// to shorten the code
using namespace std ;
using namespace CS_IO_Buffers ;

// we are extending the Assignment_Tokeniser namespace

namespace Assignment_Tokeniser
{
//static void parse_wspace ()
//{
//    read_next_char();
//    if(next_char_isa('\t'))
//    {
//        next_char_mustbe('\t');
//    }
//    else if(next_char_isa('\n'))
//    {
//        next_char_mustbe('\n');
//    }
//    else if(next_char_isa('\r'))
//    {
//        next_char_mustbe('r');
//    }
//    else if(next_char_isa(' '))
//    {
//        next_char_mustbe(' ');
//    }
//    else did_not_find_char(cg_wspace);
//}

static void parse_identifier()
{
    next_char_mustbe(cg_identifier);
    while(next_char_isa(cg_letter))
    {
        next_char_mustbe(cg_letter);
    };
}

static void parse_number()
{
    if(next_char_isa('0') )
    {
        next_char_mustbe('0');
//        if(next_char_isa('.'))
//        {
//            next_char_mustbe('.');
//            read_next_char();
//            while(next_char_isa(cg_digit))
//            {
//                read_next_char();
//            }
//            while(next_char_isa(cg_eee))
//            {
//                read_next_char();
//            }
//            while(next_char_isa(cg_sign))
//            {
//                read_next_char();
//            }
//            while(next_char_isa(cg_integer))
//            {
//                read_next_char();
//            }
        //}
    }else
        {
            next_char_mustbe(cg_digit19);
            while(next_char_isa(cg_digit))
            {
                read_next_char();
            }
//            while(next_char_isa(cg_scientific))
//            {
//                read_next_char();
//            }
        }
}

static void parse_string()
{

}

//static void parse_keyword()
//{
//    read_next_char();
//    if(next_char_isa('='))
//    read_next_char();
//}

static void parse_symbol()
{
    read_next_char();
    if(next_char_isa('@'))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa('~'))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa('='))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa('-'))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa('+'))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa('/'))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa('<'))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa('>'))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa('{'))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa('}'))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa('('))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa(')'))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa('['))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa(']'))
    {
        next_char_mustbe(cg_symbol);
    }else if(next_char_isa('.'))
    {
        next_char_mustbe(cg_symbol);
    }
    read_next_char();
}

//static void parse_eol_comment()
//{
//    read_next_char();
//    if(next_char_isa('='))
//    read_next_char();
//}
//
//static void parse_hash_comment()
//{
//    read_next_char();
//    if(next_char_isa('='))
//    read_next_char();
//}
    // token ::= ...
    static void parse_token()
    {
        if ( next_char_isa(EOF) ) ; else
        if ( next_char_isa(cg_symbol) ) read_next_char(); else
        if ( next_char_isa(cg_wspace) ) read_next_char(); else
        if ( next_char_isa(cg_identifier) ) parse_identifier(); else
        if ( next_char_isa(cg_number) ) parse_number(); else
        if ( next_char_isa('"') ) parse_string(); else
        did_not_find_start_of_token() ;
    }

    // parse the next token in the input and return a new
    // Token object that describes its kind and spelling
    // Note: you must not call new_token() anywhere else in your program
    // Note: you should not modify this function
    //
    Token read_next_token()
    {
        parse_token() ;

        return new_token() ;
    }
}

