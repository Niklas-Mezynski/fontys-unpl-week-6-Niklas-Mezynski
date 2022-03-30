CC=gcc
CFLAGS=-I.

cOBJ = client.o 
sOBJ = server.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

client: $(cOBJ)
	$(CC) -o $@ $^ $(CFLAGS)

server: $(sOBJ)
	$(CC) -o $@ $^ $(CFLAGS)
