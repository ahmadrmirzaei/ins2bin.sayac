#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include "driver.hh"

using namespace std;

int main(int argc, char* argv[]) {
    try {
        driver drv;
        drv.parse("insts.txt");
        drv.make_file("insts.bin");
        return 0;
    }
    catch(string exp) {
        cout << exp << endl;
        return 1;
    }
    



}