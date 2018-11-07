a.out: main.o tree.o node.o operator.o and.o or.o xor.o not.o arithmetic_and.o arithmetic_or.o arithmetic_xor.o arithmetic_not.o bitwise_and.o bitwise_or.o bitwise_xor.o bitwise_not.o operand.o binary.o octal.o decimal.o hex.o
	g++ main.o tree.o node.o operator.o and.o or.o xor.o not.o arithmetic_and.o arithmetic_or.o arithmetic_xor.o arithmetic_not.o bitwise_and.o bitwise_or.o bitwise_xor.o bitwise_not.o operand.o binary.o octal.o decimal.o hex.o
main.o: main.cpp tree.h node.h operand.h binary.h octal.h decimal.h hex.h operator.h and.h or.h xor.h not.h bitwise_and.h bitwise_or.h bitwise_xor.h bitwise_not.h arithmetic_or.h arithmetic_and.h arithmetic_xor.h arithmetic_not.h exception.h
	g++ -c main.cpp
tree.o: tree.h tree.cpp node.h operand.h binary.h octal.h decimal.h hex.h operator.h and.h or.h xor.h not.h bitwise_and.h bitwise_or.h bitwise_xor.h bitwise_not.h arithmetic_or.h arithmetic_and.h arithmetic_xor.h arithmetic_not.h exception.h
	g++ -c tree.cpp
node.o: node.h node.cpp exception.h
	g++ -c node.cpp
operator.o: operator.h operator.cpp node.h exception.h 
	g++ -c operator.cpp
not.o: not.h not.cpp operator.h node.h exception.h
	g++ -c not.cpp
arithmetic_not.o: arithmetic_not.h arithmetic_not.cpp not.h operator.h node.h exception.h
	g++ -c arithmetic_not.cpp
bitwise_not.o: bitwise_not.h bitwise_not.cpp not.h operator.h node.h exception.h
	g++ -c bitwise_not.cpp
xor.o: xor.h xor.cpp operator.h node.h exception.h
	g++ -c xor.cpp
arithmetic_xor.o: arithmetic_or.h arithmetic_or.cpp xor.h operator.h node.h exception.h
	g++ -c arithmetic_xor.cpp
bitwise_xor.o: bitwise_xor.h bitwise_xor.cpp xor.h operator.h node.h exception.h
	g++ -c bitwise_xor.cpp
or.o: or.h or.cpp operator.h node.h exception.h
	g++ -c or.cpp
bitwise_or.o: bitwise_or.h bitwise_or.cpp or.h operator.h node.h exception.h
	g++ -c bitwise_or.cpp
arithmetic_or.o: arithmetic_or.h arithmetic_or.cpp or.h operator.h node.h exception.h
	g++ -c arithmetic_or.cpp
and.o: and.h and.cpp operator.h node.h exception.h
	g++ -c and.cpp
bitwise_and.o: bitwise_and.h bitwise_and.cpp and.h operator.h node.h exception.h
	g++ -c bitwise_and.cpp
arithmetic_and.o: arithmetic_and.h arithmetic_and.cpp and.h operator.h node.h exception.h
	g++ -c arithmetic_and.cpp 
operand.o: operand.h operand.cpp node.h exception.h
	g++ -c operand.cpp
hex.o: hex.h hex.cpp operand.h node.h exception.h
	g++ -c hex.cpp
decimal.o: decimal.h decimal.cpp operand.h node.h exception.h
	g++ -c decimal.cpp
octal.o: octal.h octal.cpp operand.h node.h exception.h
	g++ -c octal.cpp
binary.o: binary.h binary.cpp operand.h node.h exception.h
	g++ -c binary.cpp