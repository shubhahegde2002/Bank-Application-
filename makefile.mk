a:App.o Clients.o
	gcc App.o Clients.o
App.o:App.c Servers.h
	gcc -c App.c Servers.h
Clients.o:Clients.c Servers.h
	gcc -c Clients.c Servers.h