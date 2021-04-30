audiomanagement: noiseGate.o echo.o main.cpp menu.cpp menu.h
	g++ -std=c++11 noiseGate.o main.cpp menu.cpp menu.h -o audiomanagement
noiseGate.o: noiseGate.cpp noiseGate.h processor.h
	g++ -std=c++11 -c noiseGate.cpp
echo.o: echo.cpp echo.h processor.h
	g++ -std=c++11 -c echo.cpp
