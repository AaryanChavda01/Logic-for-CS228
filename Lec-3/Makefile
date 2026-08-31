all: main.o
	./main.o

main.o: main.cpp prop.cpp parse.cpp semantic.cpp
	g++ main.cpp prop.cpp parse.cpp semantic.cpp -o main.o

clean:
	rm main.o