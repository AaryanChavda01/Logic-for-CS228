all: main.o

main.o: main.cpp prop.cpp parse.cpp
	g++ main.cpp prop.cpp parse.cpp -o main.o
	./main.o

clean:
	rm main.o