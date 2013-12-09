CC=gcc

ODIR=obj
BINDIR=bin

LIBS=-lm

_OBJ = romberg.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $<

$(BINDIR)/romberg: $(OBJ)
	$(CC) -o $@ $(ODIR)/romberg.o $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BINDIR)/* *~ core

$(BINDIR):
	mkdir -p $(BINDIR)

$(ODIR):
	mkdir -p $(ODIR)

all: $(BINDIR) $(ODIR) $(BINDIR)/romberg
