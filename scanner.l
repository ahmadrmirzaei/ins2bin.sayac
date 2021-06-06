%{
    #include "driver.hh"
    #include "parser.hh"
    using namespace std;
%}

%option noyywrap

word    [a-zA-Z][a-zA-Z_0-9]*
number  [0-9]+
blank   [ \t\r\n]
opcode "LDR"|"STR"|"JMR"|"JMI"|"ANR"|"ANI"|"MSI"|"MHI"|"SLR"|"SAR"|"ADR"|"SUR"|"ADI"|"SUI"|"MUL"|"DIV"|"CMR"|"CMI"|"BRC"|"BRR"|"SHI"|"NTR"|"NTD"
option "io"|"s"|"la"|"2c"

%%

%{
    yy::location& loc = drv.location;
    loc.step();
%}

{blank}+            loc.step();
{opcode}            return yy::parser::make_OPCODE(yytext, loc);
{option}            return yy::parser::make_OPTION(yytext, loc);
"r"                 return yy::parser::make_REG(loc);
{number}			return yy::parser::make_NUMBER(atoi(yytext), loc);
<<EOF>>             return yy::parser::make_YYEOF(loc);
.   throw yy::parser::syntax_error(loc, "invalid character: " + std::string(yytext));

%%

void driver::scan_begin(string file) {
    if(!(yyin = fopen(file.c_str(), "r"))) {
        exit(EXIT_FAILURE);
    }
}

void driver::scan_end() {
    fclose(yyin);
}