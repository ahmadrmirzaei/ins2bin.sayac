%skeleton "lalr1.cc"
%require "3.7.6"

%defines
%define api.token.raw
%define api.token.constructor
%define api.value.type variant
%define parse.assert

%code requires {
    #include <iostream>
    #include <string>
    #include <vector>

    using namespace std;
    class driver;
}

%param {driver& drv}
%locations
%define parse.trace
%define parse.error detailed
%define parse.lac full

%code {
    #include "driver.hh"
}


%token
  REG 	    "reg"
;
%token <string> OPCODE  "opc"
%token <string> OPTION  "opt"
%token <int>    NUMBER  "number"

%nterm <int> reg
%nterm <int> imm
%nterm <vector<int>> regs
%nterm <vector<int>> imms

%%

%start lines;
lines:
	line
|   lines line
;

line:
    "opc" regs {drv.make_inst($1, "", $2, {});}
|   "opc" "opt" regs {drv.make_inst($1, $2, $3, {});}
|   "opc" regs imms {drv.make_inst($1, "", $2, $3);}
|   "opc" imms regs {drv.make_inst($1, "", $3, $2);}
|   "opc" "opt" regs imms {drv.make_inst($1, $2, $3, $4);}
|   "opc" "opt" imms  regs {drv.make_inst($1, $2, $4, $3);}
|   "opc" regs imms "opt" {drv.make_inst($1, $4, $2, $3);}
|   "opc" imms regs "opt" {drv.make_inst($1, $4, $3, $2);}
;

regs:
    reg {$$ = {$1};}
|   regs reg {$1.push_back($2);$$=$1;}
;

imms:
    imm {$$ = {$1};}
|   imms imm {$1.push_back($2);$$=$1;}
;

reg:
    "reg" "number" {$$=$2;}
;

imm:
    "number" {$$=$1;}
;

%%

void yy::parser::error (const location_type& l, const std::string& m) {
  std::cerr << l << ": " << m << '\n';
}