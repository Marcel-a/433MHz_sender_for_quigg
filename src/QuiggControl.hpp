#ifndef H_QUIGG_CONTROL
#define H_QUIGG_CONTROL

class QuiggControl {
    int pin = -1;
    
public:
    void init(int pin);
    void send(int repeatings, int systemCode, int unitCode, int allDevices, int switchDimmer, int switchDimmerMode, int internal);

};

#endif