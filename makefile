audio: main.cpp menu.o
	g++ -std=c++11 main.cpp menu.o -o audio

menu.o: menu.cpp menu.h
	g++ -c -std=c++11 menu.cpp

clean:
	rm *.o audio
