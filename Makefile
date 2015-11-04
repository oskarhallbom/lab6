CC = gcc
CFLAGS = -Wall -std=c99
LIBS = -lm

SDIR=src
ODIR=obj
LDIR=lib

all: test

lib: libcomponent.so

libcomponent: $(SDIR)/libcomponent.c $(SDIR)/libcomponent.h
	$(CC) $(CFLAGS) -c $(SDIR)/libcomponent.c -o $(ODIR)/libcomponent.o $(LIBS)

libcomponent.so: $(SDIR)/libcomponent.c $(SDIR)/libcomponent.h
	$(CC) $(CFLAGS) -fPIC -c $(SDIR)/libcomponent.c -o $(ODIR)/libcomponent.o $(LIBS)
	$(CC) -shared -fPIC -o $(LDIR)/libcomponent.so $(ODIR)/libcomponent.o

libcomponent_test: libcomponent $(SDIR)/libcomponent_test.c
	$(CC) $(CFLAGS) $(SDIR)/libcomponent_test.c $(ODIR)/libcomponent.o -o libcomponent_test -lcunit -lm

test: libcomponent_test
	./libcomponent_test

clean:
	rm -f $(ODIR)/*.o $(LDIR)/*.so libcomponent_test
