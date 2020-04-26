# 433MHz sender for quigg remote switches

### Installing
* clone this repository
* cd into this repository
* run
```
make
```

### Usage
```
./send WiringPiPin repeatings systemCode unitCode commandToAllDevices switchDimmer switchDimmerMode
```

## System code
The systemCode is a fixed code per remote and its switches. I don't know, if the code can be changed.

I used this tool to find my systemCode: [https://www.instructables.com/id/Super-Simple-Raspberry-Pi-433MHz-Home-Automation/](https://www.instructables.com/id/Super-Simple-Raspberry-Pi-433MHz-Home-Automation/)
The first 12 bits represent the system code.

## Unit codes
The unit codes on my remote had a weird order:
Unit 1: 0
Unit 2: 2
Unit 3: 3
Unit 4: 1

## commandToAllDevices
0 = switch only the unit selected by unitCode
1 = switch all units

## switchDimmer
0 = switch off
1 = switch on

## switchDimmerMode
Set this to 0 to control switches.

## Example
Switch unit 2 on
```
./send 0 3 1234 1 0 1 0
```