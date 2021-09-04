#include "iobuffer.h"
#include "tokeniser-extras.h"

// to shorten the code
using namespace std ;
using namespace CS_IO_Buffers ;

namespace Assignment_Tokeniser
{
    // check if a char matches another char or is a member of a character group
    // eg char_isa('3',cg_digit) returns true
    bool char_isa(int ch,int cg)
    {
        // single character groups use their character as their value
        // do not add them to the switch statement

        if ( ch == cg ) return true ;

        switch(cg)
        {
        case cg_wspace:              // characters that start rule wspace
            switch(ch)
            {
            case '\t':
            case '\n':
            case '\r':
            case ' ':
                return true ;
            default:
                return false ;
            }
                                    // complete a switch statement for each of the following
        case cg_identifier:// characters that start rule identifier
                switch(ch)
                {
                    case '.':
                    case '-':
                    case '$':
                    case 'a' ... 'z':
                    case 'A' ... 'Z':
                    case '0' ... '9':
                    return true ;
                default:
                    return false ;
                }
        case cg_letter:             // characters that start rule letter
                switch(ch)
            {
                case '.':
                case '-':
                case '$':
                case 'a' ... 'z':
                case 'A' ... 'Z':
                case '0' ... '9':
                return true ;
            default:
                return false ;
            }
        case cg_number:             // characters that start rule number
                switch(ch)
            {
            case '0' ... '9':
            case '.':
            case 'e':
            case 'E':
            case '+':
            case '-':
                return true ;
            default:
                return false ;
            }
        case cg_integer:// characters that start rule integer
                switch(ch)
                {
                    case '0' ... '9':
                    return true ;
                default:
                    return false ;
                }
            case cg_scientific:         // characters that start rule scientific
                switch(ch)
            {
            case '.':
            case 'e':
            case 'E':
            case '+':
            case '-':
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
        case cg_exponent:           // characters that start rule exponent
                switch(ch)
                {
                    case 'e':
                    case 'E':
                    case '+':
                    case '-':
                    case '0' ... '9':
                    return true ;
                default:
                    return false ;
                }
        case cg_eee:                // characters that start rule eee
                switch(ch)
                {
                    case 'e':
                    case 'E':
                    return true ;
                default:
                    return false ;
                }
        case cg_sign:               // characters that start rule eee
                switch(ch)
                {
                    case '+':
                    case '-':
                    return true ;
                default:
                    return false ;
                }
        case cg_instring:           // characters that start rule instring
                switch(ch)
            {
                case ' ':
                case '!':
                case '#':
                case '-':
                case '~':
                case '0x0C00' ... '0x0C7F':
                return true ;
            default:
                return false ;
            }
        case cg_telegu:             // characters that start rule telegu
                switch(ch)
            {
                case '0x0C00' ... '0x0C7F':
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
        case cg_comment_char:       // characters that start rule comment_char
                switch(ch)
            {
                case '\t':
                case '\r':
                case ' ':
                case '-':
                case '~':
                case '0x0530' ... '0x058F':
                case '0xFB13' ... '0xFB17':
                return true ;
            default:
                return false ;
            }
            case cg_armenian:           // characters that start rule armenian
                switch(ch)
            {
                case '0xFB13' ... '0xFB17':
                return true ;
            default:
                return false ;
            }

        default:
            return false ;
        }
    }

    // work out the kind of a parsed token, this may call keyword_or_identifier()
    // the spelling is a valid token or "" if at end of input
    TokenKind classify_spelling(string spelling)
{
    if ( spelling == "" ) return tk_eoi ;
    switch(spelling[0])                    // ch is always the next char to read
    {
        case ' ':       return tk_space;
        case '\t':      return tk_tab;
        case '\r':      return tk_carriage_return;
        case '\n':      return tk_newline;

                // the single character symbol tokens
        case '@':       return tk_at;
        //case '~':       return tk_not;
       

            
        case '{':       return tk_lcb;
        case '}':       return tk_rcb;
        case '(':       return tk_lrb;
        case ')':       return tk_rrb;
        case '[':       return tk_lsb;
        case ']':       return tk_rsb;
        //case '.':       return tk_dot;
            
            //Math
        case '+':       return tk_add;
        case '-':       return tk_sub;
        case '/':       return tk_div;
            
            //Identifiers
        case 'a' ... 'z': return keyword_or_identifier(spelling);

        case 'A' ... 'Z': return keyword_or_identifier(spelling);


            //Digits
        case '0' ... '9': return tk_integer;
        case '.':
            if (spelling[1]== '1'|'2'|'3'|'4'|'5'|'6'|'7'|'8'|'9') {
                return tk_scientific;
            }else
            {
                return tk_dot;
            }
            

        case '=':
            if (spelling[1]=='=') {
                return tk_eq;
            }else
            {
                return tk_assign;
            }
        case '>':
            if (spelling[1]=='>') {
                if(spelling[2]=='>')
                {
                    return  tk_ra_shift;
                }else
                {
                    return tk_rl_shift;
                }
            }
        case '<':
            if (spelling[1]=='<') {
                if(spelling[2]=='<')
                {
                    return  tk_ll_shift;
                }else
                {
                    return tk_la_shift;
                }
            }
        case '~':
            if (spelling[1]=='=') {
                return tk_ne;
            }else
            {
                return tk_not;
            }
        case '*':
            if (spelling[1]=='=') {
                return tk_mult;
            }

//            tk_constructor,     // 'constructor'
//            tk_function,        // 'function'
//            tk_if_goto,         // 'if-goto'
//            tk_procedure,       // 'procedure'
//            tk_this,
//            tk_hash_comment,    // '#' comment_char* '\n', '#' and '\n' are not part of the spelling
//            tk_eol_comment,     // '//' comment_char* '\n', '//' and '\n' are not part of the spelling
//
//            tk_string,          // '"' instring* '"', '"' and '"' are not part of the spelling


            
    }
    return tk_identifier ;
}

    // work out the correct spelling to use in the Token object being created by new_token()
    // the spelling is a valid token and kind is its kind
string correct_spelling(TokenKind kind,string spelling)
{
    if(kind == tk_lrb)
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
