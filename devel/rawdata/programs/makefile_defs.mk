## output file name
MAIN=main

## suffixes used:
#.SUFFIXES: .cpp .o .x .h

## software directories
#### include: *.h  obj: *.o  lib: *.a  src: *.cpp
SOFT=../software
IDIR=$(SOFT)/include
ODIR=$(SOFT)/build
LDIR=$(SOFT)/lib
SDIR=$(SOFT)/src

## compiler and compiler flags
CC=g++
CFLAGS=-g -std=c++11
AFLAGS=-I$(IDIR) #-fast -W -Wall -WShadow -Wconversion

## additional libraries to link
LIBS=

## dependecies
#### pattern substition adds folder location to *.h files
#_DEPS=coshfunc.h analysis.h system.h emulator.h mcmc.h parametermap.h
_DEPS=system.h parametermap.h balancemodel.h analysis.h emulator.h mcmc.h coshfunc.h
DEPS=$(patsubst %, $(IDIR)/%, $(_DEPS))

## object files
#### pattern substition adds folder location to *.o files
#_OBJ=coshfunc.o analysis.o system.o emulator.o mcmc.o parametermap.o $(MAIN).o
_OBJ=system.o parametermap.o balancemodel.o analysis.o emulator.o mcmc.o coshfunc.o $(MAIN).o
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))
