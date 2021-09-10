//a1744546
//
//
#include "iobuffer.h"
#include "tokeniser-extras.h"

// to shorten the code
using namespace std ;
using namespace CS_IO_Buffers ;

// we are extending the Assignment_Tokeniser namespace
namespace Assignment_Tokeniser
{
    //identifier parsing
    static void parse_identifier()
    {
        next_char_mustbe(cg_letter);
        while (next_char_isa(cg_letter)){
            read_next_char();
        }
    }

    //number parsing
    static void parse_number()
    {
        if ( next_char_isa('0') )
        {
            next_char_mustbe('0');
            if ( next_char_isa('.') )
            {
                next_char_mustbe('.');
                while(next_char_isa(cg_digit))
                {
                    read_next_char();
                }
                if (next_char_isa(cg_eee))
                {
                    next_char_mustbe(cg_eee);
                }
                if (next_char_isa(cg_sign))
                {
                    next_char_mustbe(cg_sign);
                }
                while (next_char_isa(cg_integer))
                {
                    next_char_mustbe(cg_integer);
                }
            }
        }else if ( next_char_isa(cg_digit19) )
        {
            next_char_mustbe(cg_digit19);
            if (next_char_isa(cg_digit)){
                while (next_char_isa(cg_digit))
                {
                    read_next_char();
                }
                if ( next_char_isa('.') )
                {
                    next_char_mustbe('.');
                    while(next_char_isa(cg_digit))
                    {
                        read_next_char();
                    }
                    if (next_char_isa(cg_eee))
                    {
                        next_char_mustbe(cg_eee);
                    }
                    if (next_char_isa(cg_sign))
                    {
                        next_char_mustbe(cg_sign);
                    }
                    while (next_char_isa(cg_integer))
                    {
                        next_char_mustbe(cg_integer);
                    }
                }
            }else if ( next_char_isa('.') )
            {
                next_char_mustbe('.');
                while(next_char_isa(cg_digit))
                {
                    read_next_char();
                }
                if (next_char_isa(cg_eee))
                {
                    next_char_mustbe(cg_eee);
                }
                if (next_char_isa(cg_sign))
                {
                    next_char_mustbe(cg_sign);
                }
                while (next_char_isa(cg_integer))
                {
                    next_char_mustbe(cg_integer);
                }
            }
        }
    }

//string
    static void parse_instring()
    {
            next_char_mustbe('"');
        while (next_char_isa(cg_instring))
        {
            read_next_char();
        }
            next_char_mustbe('"');
    }


//symbol
    static void parse_symbol()
    {
        if (next_char_isa('*'))
        {
            next_char_mustbe('=');
        }else{
            read_next_char();
        }
    }

    // token ::= ...
    static void parse_token()
    {
        if ( next_char_isa(EOF) ) ; else
        if ( next_char_isa(cg_wspace) ) read_next_char();else
        if ( next_char_isa(cg_identifier) ) parse_identifier(); else
        if ( next_char_isa(cg_number) ) parse_number(); else
        if ( next_char_isa('"') ) parse_instring(); else
//        if ( next_char_isa('#') ) parse_hash_comment(); else
//        if ( next_char_isa('/')) parse_eol_comment(); else
        if ( next_char_isa(cg_symbol) ) parse_symbol(); else
        

        did_not_find_start_of_token();
    }



    // parse the next token in the input and return a new
    // Token object that describes its kind and spelling
    // Note: you must not call new_token() anywhere else in your program
    // Note: you should not modify this function
    Token read_next_token()
    {
        parse_token() ;

        return new_token() ;
    }
}

