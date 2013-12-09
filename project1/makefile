CC=gcc

ODIR=obj
BINDIR=bin

LIBS=-lm

_OBJ = bisection.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $<

$(BINDIR)/bisection: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core

$(BINDIR):
	mkdir -p $(BINDIR)

$(ODIR):
	mkdir -p $(ODIR)

all: $(BINDIR) $(ODIR) $(BINDIR)/bisection
