#include "QuiggControl.hpp"

#include <iostream>
#include <wiringPi.h>

using std::cout;
using std::cerr;
using std::endl;

void QuiggControl::init(int pin) {
    this->pin = pin;
}

void QuiggControl::send(int repeatings, int systemCode, int unitCode, int allDevices, int switchDimmer, int switchDimmerMode) {
    if (pin < 0) {
        cerr << "call QuiggControl::init first!" << endl;
        exit(1);
    }

    unsigned int msg = 0;

    msg |= systemCode << 8;
    msg |= unitCode << 6;
    msg |= allDevices << 5;
    msg |= switchDimmer << 4;
    msg |= switchDimmerMode << 3;
    // bits 1 and 2 (always zero and internal) are 0

    // parity
    int onesInMsg = 0;
    for (int i = 0; i < 20; i++) {
        if (msg & (0b1 << i)) {
            onesInMsg++;
        }
    }
    if (onesInMsg % 2 == 0) {
        // set last bit (parity bit) to one
        msg |= 0b1;
    }

    // send
    pinMode(pin, OUTPUT);

    for (int u = 0; u < repeatings; u++) {
        //cout << "send: ";

        digitalWrite(pin, HIGH);
        delayMicroseconds(700);
        
        for (int i = 19; i >= 0; i--) {
            int bit = msg & (0b1 << i);

            if (bit) {
                cout << "1";
                digitalWrite(pin, LOW);
                delayMicroseconds(1400);
                digitalWrite(pin, HIGH);
                delayMicroseconds(700);
            } else {
                cout << "0";
                digitalWrite(pin, LOW);
                delayMicroseconds(700);
                digitalWrite(pin, HIGH);
                delayMicroseconds(1400);
            }
        }
        cout << endl;
        
        digitalWrite(pin, LOW);
        delayMicroseconds(81000);
    }
}