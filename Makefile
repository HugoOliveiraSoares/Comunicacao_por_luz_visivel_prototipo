DEBUG	= -g
CC	= gcc
INCLUDE	= -I/usr/local/include
CFLAGS	= $(DEBUG) -Wall $(INCLUDE)

LDFLAGS	= -L/usr/local/lib
MYLIBS = -lmodpcf8591 -lsmbus
LDLIBS = -lwiringPi -lwiringPiDev 


BINS	=	$(SRC:.c=)

emisor:
	$(CC) emisor.c -o $@ $(LDFLAGS) $(LDLIBS) $(CFLAGS)

receptor: 
	$(CC) receptor.c -o $@ $(LDFLAGS) $(LDLIBS) $(CFLAGS)

regulador: 
	$(CC) regulador.c -o $@ $(LDFLAGS) $(LDLIBS) $(CFLAGS)


