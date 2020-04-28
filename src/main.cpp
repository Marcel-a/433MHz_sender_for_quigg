#include <iostream>
#include <cstdlib>
#include <wiringPi.h>

#include "QuiggControl.hpp"

using std::cout;
using std::cerr;
using std::endl;

using std::atoi;

int main(int argc, char* argv[])
{
    wiringPiSetup();

    if (argc < 9) {
        std::cerr << "Usage: " << argv[0] << " WiringPiPin repeatings systemCode unitCode commandToAllDevices switchDimmer switchDimmerMode internal" << std::endl;
        return 1;
    }

    int pin = atoi(argv[1]);
    if (pin < 0 || pin > 27) {
        cerr << "WiringPiPin must be between 0 and 25" << endl;
        return 1;
    }

    int repeatings = atoi(argv[2]);
    if (repeatings < 1 || repeatings > 100000) {
        cerr << "repeatings must be between 1 and 100000" << endl;
        return 1;
    }

    int systemCode = atoi(argv[3]);
    if (systemCode < 0 || systemCode > 4096) {
        cerr << "systemCode must be between 0 and 4096" << endl;
        return 1;
    }

    int unitCode = atoi(argv[4]);
    if (unitCode < 0 || unitCode > 3) {
        cerr << "unitCode must be between 0 and 3" << endl;
        return 1;
    }

    int allDevices = atoi(argv[5]);
    if (allDevices < 0 || allDevices > 1) {
        cerr << "commandToAllDevices must be 0 or 1" << endl;
        return 1;
    }

    int switchDimmer = atoi(argv[6]);
    if (switchDimmer < 0 || switchDimmer > 1) {
        cerr << "switchDimmer must be 0 or 1" << endl;
        return 1;
    }

    int switchDimmerMode = atoi(argv[7]);
    if (switchDimmerMode < 0 || switchDimmerMode > 1) {
        cerr << "switchDimmerMode must be 0 or 1" << endl;
        return 1;
    }

    int internal = atoi(argv[8]);
    if (internal < 0 || internal > 1) {
        cerr << "internal must be 0 or 1" << endl;
        return 1;
    }

    QuiggControl qc;
    qc.init(pin);
    qc.send(repeatings, systemCode, unitCode, allDevices, switchDimmer, switchDimmerMode, internal);

}