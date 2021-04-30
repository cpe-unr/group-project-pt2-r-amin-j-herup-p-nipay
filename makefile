audiomanagement: main.cpp wav.o
	g++ -std=c++11 main.cpp wav.o -o audiomanagement

wav.o: wav.cpp wav.h wavHeader.h
	g++ -c -std=c++11 wav.cpp

clean:
	rm *.o audiomanagement


