DEBUG	= -g
CC	= gcc
INCLUDE	= -I/usr/local/include
CFLAGS	= $(DEBUG) -Wall $(INCLUDE)

LDFLAGS	= -L/usr/local/lib
MYLIBS = -lmodpcf8591 -lsmbus
LDLIBS = -lwiringPi -lwiringPiDev -lm


BINS	=	$(SRC:.c=)

emisor:
	$(CC) emisor.c -o emisor.o $(LDFLAGS) $(LDLIBS) $(CFLAGS)

receptor: 
	$(CC) receptor.c -o receptor.o $(LDFLAGS) $(LDLIBS) $(CFLAGS)

regulador: 
	$(CC) regulador.c -o regulador.o $(LDFLAGS) $(LDLIBS) $(CFLAGS)


