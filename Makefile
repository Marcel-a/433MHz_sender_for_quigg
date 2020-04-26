main: src/main.cpp src/QuiggControl.hpp src/QuiggControl.cpp
	g++ -o send src/main.cpp src/QuiggControl.hpp src/QuiggControl.cpp -lwiringPi
