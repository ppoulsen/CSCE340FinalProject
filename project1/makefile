CC=gcc

ODIR=obj
BINDIR=bin

LIBS=-lm

_OBJ = bisection.o newton.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $<

$(BINDIR)/bisection: $(OBJ)
	$(CC) -o $@ $(ODIR)/bisection.o $(LIBS)

$(BINDIR)/newton: $(OBJ)
	$(CC) -o $@ $(ODIR)/newton.o $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BINDIR)/* *~ core

$(BINDIR):
	mkdir -p $(BINDIR)

$(ODIR):
	mkdir -p $(ODIR)

all: $(BINDIR) $(ODIR) $(BINDIR)/bisection $(BINDIR)/newton
