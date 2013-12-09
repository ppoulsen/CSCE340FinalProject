CC=gcc

ODIR=obj
BINDIR=bin

LIBS=-lm

_OBJ = rk4.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c
	$(CC) -c -o $@ $<

$(BINDIR)/rk4: $(OBJ)
	$(CC) -o $@ $(ODIR)/rk4.o $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o $(BINDIR)/* *~ core

$(BINDIR):
	mkdir -p $(BINDIR)

$(ODIR):
	mkdir -p $(ODIR)

all: $(BINDIR) $(ODIR) $(BINDIR)/rk4
