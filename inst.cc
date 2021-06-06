#include "inst.hh"

LDR::LDR(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    if(opt == "io") io = true;
    else io = false;
    rd = regs[0];
    rs = regs[1];
}

void LDR::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty() && opt != "io")
        throw string("Wrong option! : LDR");
    if(regs.size() != 2)
        throw string("Expected 2 regs, found "+to_string(regs.size())+"! : LDR");
    if(!imms.empty())
        throw string("Didn't expect immediate! : LDR");
}

string LDR::str() {
    string out;
    out += "001000";
    if(io) out += "1";
    else out += "0";
    out += "0";
    out += bitset<4>(rs).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}




STR::STR(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    if(opt == "io") io = true;
    else io = false;
    rd = regs[0];
    rs = regs[1];
}

void STR::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty() && opt != "io")
        throw string("Wrong option! : STR");
    if(regs.size() != 2)
        throw string("Expected 2 regs, found "+to_string(regs.size())+"! : STR");
    if(!imms.empty())
        throw string("Didn't expect immediate! : STR");
}

string STR::str() {
    string out;
    out += "001001";
    if(io) out += "1";
    else out += "0";
    out += "0";
    out += bitset<4>(rs).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}



JMR::JMR(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    if(opt == "s") s = true;
    else s = false;
    rd = regs[0];
    rs = regs[1];
}

void JMR::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty() && opt != "s")
        throw string("Wrong option! : JMR");
    if(regs.size() != 2)
        throw string("Expected 2 regs, found "+to_string(regs.size())+"! : JMR");
    if(!imms.empty())
        throw string("Didn't expect immediate! : JMR");
}

string JMR::str() {
    string out;
    out += "001010";
    if(s) out += "1";
    else out += "0";
    out += "0";
    out += bitset<4>(rs).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}



JMI::JMI(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    imm = imms[0];
}

void JMI::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : JMI");
    if(regs.size() != 1)
        throw string("Expected 1 reg, found "+to_string(regs.size())+"! : JMI");
    if(imms.size() != 1)
        throw string("Expected 1 immediate, found "+to_string(regs.size())+"! : JMI");
}

string JMI::str() {
    string out;
    out += "001011";
    out += bitset<6>(imm).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}



ANR::ANR(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    rs1 = regs[1];
    rs2 = regs[2];
}

void ANR::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : ANR");
    if(regs.size() != 3)
        throw string("Expected 3 regs, found "+to_string(regs.size())+"! : ANR");
    if(!imms.empty())
        throw string("Didn't expect immediate! : ANR");
}

string ANR::str() {
    string out;
    out += "0011";
    out += bitset<4>(rs1).to_string();
    out += bitset<4>(rs2).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}


ANI::ANI(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    imm = imms[0];
}

void ANI::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : ANI");
    if(regs.size() != 1)
        throw string("Expected 1 reg, found "+to_string(regs.size())+"! : ANI");
    if(imms.size() != 1)
        throw string("Expected 1 immediate, found "+to_string(regs.size())+"! : ANI");
}

string ANI::str() {
    string out;
    out += "0100";
    out += bitset<8>(imm).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}




MSI::MSI(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    imm = imms[0];
}

void MSI::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : MSI");
    if(regs.size() != 1)
        throw string("Expected 1 reg, found "+to_string(regs.size())+"! : MSI");
    if(imms.size() != 1)
        throw string("Expected 1 immediate, found "+to_string(regs.size())+"! : MSI");
}

string MSI::str() {
    string out;
    out += "0101";
    out += bitset<8>(imm).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}



MHI::MHI(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    imm = imms[0];
}

void MHI::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : MHI");
    if(regs.size() != 1)
        throw string("Expected 1 reg, found "+to_string(regs.size())+"! : MHI");
    if(imms.size() != 1)
        throw string("Expected 1 immediate, found "+to_string(regs.size())+"! : MHI");
}

string MHI::str() {
    string out;
    out += "0110";
    out += bitset<8>(imm).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}



SLR::SLR(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    rs1 = regs[1];
    rs2 = regs[2];
}

void SLR::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : SLR");
    if(regs.size() != 3)
        throw string("Expected 3 regs, found "+to_string(regs.size())+"! : SLR");
    if(!imms.empty())
        throw string("Didn't expect immediate! : SLR");
}

string SLR::str() {
    string out;
    out += "0111";
    out += bitset<4>(rs1).to_string();
    out += bitset<4>(rs2).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}


SAR::SAR(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    rs1 = regs[1];
    rs2 = regs[2];
}

void SAR::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : SAR");
    if(regs.size() != 3)
        throw string("Expected 3 regs, found "+to_string(regs.size())+"! : SAR");
    if(!imms.empty())
        throw string("Didn't expect immediate! : SAR");
}

string SAR::str() {
    string out;
    out += "1000";
    out += bitset<4>(rs1).to_string();
    out += bitset<4>(rs2).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}



ADR::ADR(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    rs1 = regs[1];
    rs2 = regs[2];
}

void ADR::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : ADR");
    if(regs.size() != 3)
        throw string("Expected 3 regs, found "+to_string(regs.size())+"! : ADR");
    if(!imms.empty())
        throw string("Didn't expect immediate! : ADR");
}

string ADR::str() {
    string out;
    out += "1001";
    out += bitset<4>(rs1).to_string();
    out += bitset<4>(rs2).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}



SUR::SUR(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    rs1 = regs[1];
    rs2 = regs[2];
}

void SUR::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : SUR");
    if(regs.size() != 3)
        throw string("Expected 3 regs, found "+to_string(regs.size())+"! : SUR");
    if(!imms.empty())
        throw string("Didn't expect immediate! : SUR");
}

string SUR::str() {
    string out;
    out += "1010";
    out += bitset<4>(rs1).to_string();
    out += bitset<4>(rs2).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}



ADI::ADI(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    imm = imms[0];
}

void ADI::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : ADI");
    if(regs.size() != 1)
        throw string("Expected 1 reg, found "+to_string(regs.size())+"! : ADI");
    if(imms.size() != 1)
        throw string("Expected 1 immediate, found "+to_string(regs.size())+"! : ADI");
}

string ADI::str() {
    string out;
    out += "1011";
    out += bitset<8>(imm).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}


SUI::SUI(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    imm = imms[0];
}

void SUI::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : SUI");
    if(regs.size() != 1)
        throw string("Expected 1 reg, found "+to_string(regs.size())+"! : SUI");
    if(imms.size() != 1)
        throw string("Expected 1 immediate, found "+to_string(regs.size())+"! : SUI");
}

string SUI::str() {
    string out;
    out += "1100";
    out += bitset<8>(imm).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}



MUL::MUL(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    rs1 = regs[1];
    rs2 = regs[2];
}

void MUL::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : MUL");
    if(regs.size() != 3)
        throw string("Expected 3 regs, found "+to_string(regs.size())+"! : MUL");
    if(!imms.empty())
        throw string("Didn't expect immediate! : MUL");
}

string MUL::str() {
    string out;
    out += "1101";
    out += bitset<4>(rs1).to_string();
    out += bitset<4>(rs2).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}


DIV::DIV(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    rs1 = regs[1];
    rs2 = regs[2];
}

void DIV::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : DIV");
    if(regs.size() != 3)
        throw string("Expected 3 regs, found "+to_string(regs.size())+"! : DIV");
    if(!imms.empty())
        throw string("Didn't expect immediate! : DIV");
}

string DIV::str() {
    string out;
    out += "1110";
    out += bitset<4>(rs1).to_string();
    out += bitset<4>(rs2).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}



CMR::CMR(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rs1 = regs[0];
    rs2 = regs[1];
}

void CMR::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : CMR");
    if(regs.size() != 2)
        throw string("Expected 2 regs, found "+to_string(regs.size())+"! : CMR");
    if(!imms.empty())
        throw string("Didn't expect immediate! : CMR");
}

string CMR::str() {
    string out;
    out += "11110000";
    out += bitset<4>(rs2).to_string();
    out += bitset<4>(rs1).to_string();
    return out;
}



CMI::CMI(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rs = regs[0];
    imm = imms[0];
}

void CMI::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : CMI");
    if(regs.size() != 1)
        throw string("Expected 1 reg, found "+to_string(regs.size())+"! : CMI");
    if(imms.size() != 1)
        throw string("Expected 1 immediate, found "+to_string(regs.size())+"! : CMI");
}

string CMI::str() {
    string out;
    out += "1111001";
    out += bitset<5>(imm).to_string();
    out += bitset<4>(rs).to_string();
    return out;
}



BRC::BRC(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    imm = imms[0];
}

void BRC::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : BRC");
    if(regs.size() != 1)
        throw string("Expected 1 reg, found "+to_string(regs.size())+"! : BRC");
    if(imms.size() != 1)
        throw string("Expected 1 immediate, found "+to_string(regs.size())+"! : BRC");
}

string BRC::str() {
    string out;
    out += "1111010";
    out += bitset<5>(imm).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}




BRR::BRR(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    rd = regs[0];
    imm = imms[0];
}

void BRR::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty())
        throw string("Didn't expect option! : BRR");
    if(regs.size() != 1)
        throw string("Expected 1 reg, found "+to_string(regs.size())+"! : BRR");
    if(imms.size() != 1)
        throw string("Expected 1 immediate, found "+to_string(regs.size())+"! : BRR");
}

string BRR::str() {
    string out;
    out += "1111011";
    out += bitset<5>(imm).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}




SHI::SHI(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    if(opt == "la") la = true;
    else la = false;
    rd = regs[0];
    imm = imms[0];
}

void SHI::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty() && opt != "la")
        throw string("Wrong option! : SHI");
    if(regs.size() != 1)
        throw string("Expected 1 reg, found "+to_string(regs.size())+"! : SHI");
    if(imms.size() != 1)
        throw string("Expected 1 immediate, found "+to_string(regs.size())+"! : SHI");
}

string SHI::str() {
    string out;
    out += "111110";
    if(la) out += "1";
    else out += "0";
    out += bitset<5>(imm).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}




NTR::NTR(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    if(opt == "2c") c = true;
    else c = false;
    rd = regs[0];
    rs = regs[1];
}

void NTR::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty() && opt != "2c")
        throw string("Wrong option! : NTR");
    if(regs.size() != 2)
        throw string("Expected 2 regs, found "+to_string(regs.size())+"! : NTR");
    if(!imms.empty())
        throw string("Didn't expect immediate! : NTR");
}

string NTR::str() {
    string out;
    out += "1111110";
    if(c) out += "1";
    else out += "0";
    out += bitset<4>(rs).to_string();
    out += bitset<4>(rd).to_string();
    return out;
}



NTD::NTD(string opt, registers regs, immediates imms) {
    check_params(opt, regs, imms);
    if(opt == "2c") c = true;
    else c = false;
    rd = regs[0];
}

void NTD::check_params(string opt, registers regs, immediates imms) {
    if(!opt.empty() && opt != "2c")
        throw string("Wrong option! : NTD");
    if(regs.size() != 1)
        throw string("Expected 1 reg, found "+to_string(regs.size())+"! : NTD");
    if(!imms.empty())
        throw string("Didn't expect immediate! : NTD");
}

string NTD::str() {
    string out;
    out += "1111111";
    if(c) out += "1";
    else out += "0";
    out += "0000";
    out += bitset<4>(rd).to_string();
    return out;
}