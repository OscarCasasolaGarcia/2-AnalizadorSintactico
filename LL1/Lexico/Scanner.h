#ifndef _SCANNER_HPP_
#define _SCANNER_HPP_

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h> 
#endif

namespace C_1{
    class Scanner : public yyFlexLexer{
    public:
        Scanner(std::istream *in) : yyFlexLexer(in) {
            
        };
        using FlexLexer::yylex;
        virtual int yylex();

    private:
        const int ERROR = -1;
    };
}
#endif /* END __SCANNER_H__ */