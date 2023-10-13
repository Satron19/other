all: programa

programa: main lista
	g++ -o Ejec main.o lista.o

main: main.cpp
	g++ -c main.cpp
lista: lista.cpp
	g++ -c lista.cpp


