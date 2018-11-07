a.out:main.o function.o pair.o
	g++ main.o function.o pair.o
main.o:main.cpp function.h pair.h 
	g++ -c main.cpp
function.o:function.cpp function.h pair.h exception.h
	g++ -c function.cpp
pair.o:pair.cpp pair.h
	g++ -c pair.cpp