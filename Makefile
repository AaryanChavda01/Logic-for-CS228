all: main.o

main.o: main.cpp prop.cpp
	g++ main.cpp prop.cpp -o main.o

clean:
	rm *.o