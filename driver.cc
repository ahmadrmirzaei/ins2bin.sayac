#include "driver.hh"

void driver::parse(string file) {
    location.initialize(&file);
    scan_begin(file);
    yy::parser parse(*this);
    parse();
    scan_end();
}

void driver::make_inst(string opc, string opt, registers regs, immediates imms) {
    Inst* inst;
    if(opc == "LDR") inst = new LDR(opt, regs, imms);
    if(opc == "STR") inst = new STR(opt, regs, imms);
    if(opc == "JMR") inst = new JMR(opt, regs, imms);
    if(opc == "JMI") inst = new JMI(opt, regs, imms);
    if(opc == "ANR") inst = new ANR(opt, regs, imms);
    if(opc == "ANI") inst = new ANI(opt, regs, imms);
    if(opc == "MSI") inst = new MSI(opt, regs, imms);
    if(opc == "MHI") inst = new MHI(opt, regs, imms);
    if(opc == "SLR") inst = new SLR(opt, regs, imms);
    if(opc == "SAR") inst = new SAR(opt, regs, imms);
    if(opc == "ADR") inst = new ADR(opt, regs, imms);
    if(opc == "SUR") inst = new SUR(opt, regs, imms);
    if(opc == "ADI") inst = new ADI(opt, regs, imms);
    if(opc == "SUI") inst = new SUI(opt, regs, imms);
    if(opc == "MUL") inst = new MUL(opt, regs, imms);
    if(opc == "DIV") inst = new DIV(opt, regs, imms);
    if(opc == "CMR") inst = new CMR(opt, regs, imms);
    if(opc == "CMI") inst = new CMI(opt, regs, imms);
    if(opc == "BRC") inst = new BRC(opt, regs, imms);
    if(opc == "BRR") inst = new BRR(opt, regs, imms);
    if(opc == "SHI") inst = new SHI(opt, regs, imms);
    if(opc == "NTR") inst = new NTR(opt, regs, imms);
    if(opc == "NTD") inst = new NTD(opt, regs, imms);
    insts.push_back(inst);
}

void driver::make_file(string file_name) {
    ofstream out(file_name);
    for(auto& a : insts)
        out << a->str() << endl;
    out.close();
}