###############################################
# Makefile for compiling the program skeleton
# 'make'           build executable file 'PROJ'
# 'make doxy'   build project manual in doxygen
# 'make all'       build project + manual
# 'make clean'  removes all .o, executable and doxy log
###############################################
PROJ = latinSquare-solver   # the name of the project
CC   = gcc                  # name of compiler
DOXYGEN = doxygen            # name of doxygen binary
# define any compile-time flags
CFLAGS = -std=c99 -Wall -O -Wuninitialized -Wunreachable-code -pedantic # there is a space at the end of this
LFLAGS = -lm                 # linking with math library
###############################################
# You don't need to edit anything below this line
###############################################
# list of object files
# The following includes all of them!
C_FILES := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(C_FILES))

# To create the executable file, we need the individual object files
$(PROJ): $(OBJS)
	$(CC) -g -o $(PROJ) $(OBJS) $(LFLAGS)

# To create each individual object file, we need to compile these files using the following general purpose macro
.c.o:
	$(CC) $(CFLAGS) -g -c $<

# To make all (program + manual) "make all"
all: $(PROJ) doxy

# To build the documentation "make doxy"
doxy:
	$(DOXYGEN) Doxyfile &> doxygen.log

# To clean .o files: "make clean"
clean:
	rm -rf *.o doxygen.log html $(PROJ)
