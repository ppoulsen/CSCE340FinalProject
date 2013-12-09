CC=gcc

ODIR=obj
BINDIR=bin

LIBS=-lm

_OBJ = mc.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $<

$(BINDIR)/mc: $(OBJ)
	$(CC) -o $@ $(ODIR)/mc.o $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BINDIR)/* *~ core

$(BINDIR):
	mkdir -p $(BINDIR)

$(ODIR):
	mkdir -p $(ODIR)

all: $(BINDIR) $(ODIR) $(BINDIR)/mc
