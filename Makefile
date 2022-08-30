all: main

main: BufferProcessing.o StringProcessing.o Buffer.o main.o
	g++ -o main main.o Buffer.o BufferProcessing.o StringProcessing.o

main.o: main.cpp
	g++ -c main.cpp -std=c++20

Buffer.o: Buffer.cpp
	g++ -c Buffer.cpp -pthread -std=c++20
	
BufferProcessing..o: BufferProcessing.cpp
	g++ -c BufferProcessing.cpp -std=c++20
	
StringProcessing.o: StringProcessing.cpp
	g++ -c StringProcessing.cpp -std=c++20
clean:
	rm main.o Buffer.o BufferProcessing.o StringProcessing.o main
