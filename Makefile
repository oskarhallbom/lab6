CC = gcc
CFLAGS = -Wall -std=c99
LIBS = -lm

SDIR=src
ODIR=obj
LDIR=lib
TDIR=src/test
CUNIT=-I$(TDIR)/inc -L$(TDIR)/lib -lcunit
all: test

lib: libcomponent.so

libcomponent: $(SDIR)/libcomponent.c $(SDIR)/libcomponent.h
	$(CC) $(CFLAGS) -c $(SDIR)/libcomponent.c -o $(ODIR)/libcomponent.o $(LIBS)

libcomponent.so: $(SDIR)/libcomponent.c $(SDIR)/libcomponent.h
	$(CC) $(CFLAGS) -fPIC -c $(SDIR)/libcomponent.c -o $(ODIR)/libcomponent.o $(LIBS)
	$(CC) -shared -fPIC -o $(LDIR)/libcomponent.so $(ODIR)/libcomponent.o

libcomponent_test: libcomponent $(TDIR)/libcomponent_test.c
	$(CC) $(CFLAGS) $(TDIR)/libcomponent_test.c $(ODIR)/libcomponent.o -o libcomponent_test $(CUNIT) $(LIBS)

test: libcomponent_test
	./libcomponent_test

clean:
	rm -f $(ODIR)/*.o libcomponent_test
