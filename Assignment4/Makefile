a.out: main.o bank.o transaction.o customer.o account.o
	g++ main.o bank.o transaction.o customer.o account.o
main.o: main.cpp bank.h transaction.h customer.h account.h
	g++ -c main.cpp
bank.o: bank.h bank.cpp transaction.h customer.h account.h
	g++ -c bank.cpp
transaction.o: transaction.h transaction.cpp account.h
	g++ -c transaction.cpp
customer.o: customer.cpp customer.h transaction.h
	g++ -c customer.cpp
account.o: account.cpp account.h transaction.h customer.h
	g++ -c account.cpp