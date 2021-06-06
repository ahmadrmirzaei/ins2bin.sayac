#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "parser.hh"
#include "inst.hh"

using namespace std;

#define YY_DECL yy::parser::symbol_type yylex (driver& drv)
YY_DECL;

class driver {
public:
    yy::location location;

    vector<Inst*> insts;

public:
    void parse(string file);
    void scan_begin(string file);
    void scan_end();

    void make_inst(string opc, string opt, registers regs, immediates imms);
    void make_file(string file_name);
};