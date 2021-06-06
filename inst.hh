#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <bitset>

using namespace std;

typedef vector<int> registers;
typedef vector<int> immediates;

class Inst {
public:
    virtual string str() = 0;
};


class LDR : public Inst {
private:
    bool io;
    int rs;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    LDR(string opt, registers regs, immediates imms);
    string str();
};


class STR : public Inst {
private:
    bool io;
    int rs;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    STR(string opt, registers regs, immediates imms);
    string str();
};


class JMR : public Inst {
private:
    bool s;
    int rs;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    JMR(string opt, registers regs, immediates imms);
    string str();
};


class JMI : public Inst {
private:
    int imm;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    JMI(string opt, registers regs, immediates imms);
    string str();
};


class ANR : public Inst {
private:
    int rs1;
    int rs2;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    ANR(string opt, registers regs, immediates imms);
    string str();
};


class ANI : public Inst {
private:
    int imm;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    ANI(string opt, registers regs, immediates imms);
    string str();
};


class MSI : public Inst {
private:
    int imm;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    MSI(string opt, registers regs, immediates imms);
    string str();
};


class MHI : public Inst {
private:
    int imm;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    MHI(string opt, registers regs, immediates imms);
    string str();
};


class SLR : public Inst {
private:
    int rs1;
    int rs2;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    SLR(string opt, registers regs, immediates imms);
    string str();
};


class SAR : public Inst {
private:
    int rs1;
    int rs2;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    SAR(string opt, registers regs, immediates imms);
    string str();
};


class ADR : public Inst {
private:
    int rs1;
    int rs2;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    ADR(string opt, registers regs, immediates imms);
    string str();
};



class SUR : public Inst {
private:
    int rs1;
    int rs2;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    SUR(string opt, registers regs, immediates imms);
    string str();
};


class ADI : public Inst {
private:
    int imm;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    ADI(string opt, registers regs, immediates imms);
    string str();
};


class SUI : public Inst {
private:
    int imm;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    SUI(string opt, registers regs, immediates imms);
    string str();
};


class MUL : public Inst {
private:
    int rs1;
    int rs2;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    MUL(string opt, registers regs, immediates imms);
    string str();
};


class DIV : public Inst {
private:
    int rs1;
    int rs2;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    DIV(string opt, registers regs, immediates imms);
    string str();
};


class CMR : public Inst {
private:
    int rs1;
    int rs2;

    void check_params(string opt, registers regs, immediates imms);

public:
    CMR(string opt, registers regs, immediates imms);
    string str();
};


class CMI : public Inst {
private:
    int imm;
    int rs;

    void check_params(string opt, registers regs, immediates imms);

public:
    CMI(string opt, registers regs, immediates imms);
    string str();
};


class BRC : public Inst {
private:
    int imm;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    BRC(string opt, registers regs, immediates imms);
    string str();
};


class BRR : public Inst {
private:
    int imm;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    BRR(string opt, registers regs, immediates imms);
    string str();
};


class SHI : public Inst {
private:
    bool la;
    int imm;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    SHI(string opt, registers regs, immediates imms);
    string str();
};


class NTR : public Inst {
private:
    bool c;
    int rs;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    NTR(string opt, registers regs, immediates imms);
    string str();
};


class NTD : public Inst {
private:
    bool c;
    int rd;

    void check_params(string opt, registers regs, immediates imms);

public:
    NTD(string opt, registers regs, immediates imms);
    string str();
};