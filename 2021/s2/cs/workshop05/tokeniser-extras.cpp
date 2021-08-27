// convert Text into Tokens wrapped up in XML
#include "iobuffer.h"
#include "tokeniser-extras.h"
#include <unordered_map>
#include <iostream>
#include <vector>

// to shorten the code
using namespace std ;
using namespace CS_IO_Buffers ;

namespace Workshop_Tokeniser
{
    // check if a char matches another char or is a member of a character group
    // eg char_isa('3',cg_digit) returns true
    bool char_isa(int ch,int cg)
    {
        // first check for single character match
        if ( ch == cg ) return true ;

        switch(cg)
        {
        case cg_wspace:              // characters that start rule wspace
            switch(ch)
            {
                case '\n':
                case '\t':
                case '\r':
                case ' ':
                return true ;
            default:
                return false ;
            }
        case cg_identifier:          // characters that start rule identifier
            switch(ch)
            {
                
                case 'a' ... 'z':
                case 'A' ... 'Z':
                return true ;
            default:
                return false ;
            }
        case cg_letter:              // characters that start rule letter
            switch(ch)
            {
                case 'a' ... 'z':
                case 'A' ... 'Z':
                return true ;
            default:
                return false ;
            }
        case cg_alnum:               // characters that start rule alnum
            switch(ch)
            {
                case 'a' ... 'z':
                case 'A' ... 'Z':
                case '0' ... '9':
                return true ;
            default:
                return false ;
            }
        case cg_integer:             // characters that start rule integer
            switch(ch)
            {
                case '0' ... '9':
                return true ;
            default:
                return false ;
            }
        case cg_digit19:             // characters that start rule digit19
            switch(ch)
            {
                case '1' ... '9':
                return true ;
            default:
                return false ;
            }
        case cg_digit:               // characters that start rule digit
            switch(ch)
            {
                case '0' ... '9':
                return true ;
            default:
                return false ;
            }
        case cg_op:                  // characters that start rule op
            switch(ch)
            {
                case '+':
                case '-':
                case '*':
                case '/':
                return true ;
            default:
                return false ;
            }
        case cg_varop:               // characters that start rule varop
            switch(ch)
            {
                case '<':
                //case '<=':
                case '=':
                //case '==':
                case '!':
                //case '!=':
                case '>':
                //case '>=':
                return true ;
            default:
                return false ;
            }
        case cg_symbol:              // characters that start rule symbol
            switch(ch)
            {
                case '@':
                case '{':
                case '}':
                case ':':
                case ';':
                case '.':
                case ',':
                case '"':
                return true ;
            default:
                return false ;
            }
        default:
            return false ;
        }
    }

    // work out the kind of a parsed token
    // this calls keyword_or_identifier(spelling) to check if an identifier is really a keyword
    // the spelling is a valid token
    // this is only called by new_token()
    TokenKind classify_spelling(string spelling)
    {
        if ( spelling == "" ) return tk_eoi ;
        switch(spelling[0])                    // ch is always the next char to read
        {
            case ' ':       return tk_space;
//                case '\':
//                if (spelling[1] == 't') {
//                    return tk_tab;
//                } else if(spelling[1] == 'r')
//                {
//                    return tk_carriage_return;
//                }else if(spelling[1] == 'n')
//                {
//                    return tk_newline;
//                }
            case '\t':      return tk_tab;
            case '\r':      return tk_carriage_return;
            case '\n':      return tk_newline;

                    //Single Character Symbols
            case '@':       return tk_at;
            case '{':       return tk_lcb;
            case '}':       return tk_rcb;
            case '(':       return tk_label;
            case ')':       return tk_label;
            case ':':       return tk_colon;
            case ';':       return tk_semi;
            case '.':       return tk_dot;
            case ',':       return tk_comma;
            case '"':       return tk_dquote;

                    //Multi Character Symbols
            case '=':
                if (spelling[1]=='=') {
                    return tk_eq;
                }else
                {
                    return tk_assign;
                }
            case '>':
                if (spelling[1]=='=') {
                    return  tk_ge;
                }else
                {
                    return tk_gt;
                }
            case '<':
                if (spelling[1]=='=') {
                    return tk_le;
                }else
                {
                    return tk_lt;
                }
            case '!':
                if (spelling[1]=='=') {
                    return tk_ne;
                }else
                {
                    return tk_not;
                }

                    //Math
            case '+':       return tk_add;
            case '-':       return tk_sub;
            case '*':       return tk_times;
            case '/':       return tk_divide;

                    //Identifiers
            case 'a' ... 'z': return keyword_or_identifier(spelling);

            case 'A' ... 'Z': return keyword_or_identifier(spelling);


                    //Digits
            case '0' ... '9': return tk_integer;
                
//                // keyword
//            case 'var': return tk_var;
//            case 'while': return tk_while;
//            case 'if': return tk_if;
//            case 'else': return tk_else;
//            case 'let': return tk_let;
        }
        return tk_identifier ;
    }

    // work out the correct spelling to use in the Token object being created by new_token()
    // the spelling is a valid token and kind is the token's kind
    // this is only called by new_token()
    string correct_spelling(TokenKind kind,string spelling)
    {
        if(kind == tk_label)
        {
            int length = spelling.length();

            for(int i = 0; i < length; i++){
                spelling[i] = spelling[i+1];
            }
            
            spelling.pop_back();
            spelling.pop_back();
            return spelling ;
            
        }else return spelling ;
    }

}
