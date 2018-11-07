a.out: main.o user.o admin.o prof.o server.o menu.o warehouse.o shipment.o recipe.o item.o timer.o date.o 
	g++ main.o user.o admin.o prof.o server.o menu.o warehouse.o shipment.o recipe.o item.o timer.o date.o
mian.o: main.cpp user.h admin.h prof.h server.h menu.h warehouse.h shipment.h recipe.h item.h timer.h date.h
	g++ -c main.cpp
server.o: server.cpp server.h user.h admin.h prof.h menu.h warehouse.h shipment.h recipe.h item.h timer.h date.h
	g++ -c server.cpp
menu.o: menu.cpp menu.h
	g++ -c menu.cpp
warehouse.o: warehouse.cpp warehouse.h shipment.h
	g++ -c warehouse.cpp
shipment.o: shipment.cpp shipment.h item.h date.h
	g++ -c shipment.cpp
recipe.o: recipe.cpp recipe.h 
	g++ -c recipe.cpp
item.o: item.cpp item.h
	g++ -c item.cpp
timer.o: timer.cpp timer.h
	g++ -c timer.cpp
date.o: date.cpp date.h
	g++ -c date.cpp
user.o: user.cpp user.h
	g++ -c user.cpp
admin.o: admin.cpp admin.h user.h
	g++ -c admin.cpp
prof.o: prof.cpp prof.h user.h timer.h
	g++ -c prof.cpp
	