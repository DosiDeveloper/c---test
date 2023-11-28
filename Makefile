# Project: Chukuto inventory
# Makefile created by Dev-C++ 4.9.9.2

CPP  = g++.exe
CC   = gcc.exe
WINDRES = windres.exe
RES  = sistema_de_inventario_universidad_private.res
OBJ  = main.o inventario.o $(RES)
LINKOBJ  = main.o inventario.o $(RES)
LIBS =  -L"C:/MinGW/lib"  
INCS =  -I"C:/MinGW/include" 
CXXINCS =  -I"C:/MinGW/include" 
BIN  = "sistema de inventario universidad.exe"
CXXFLAGS = $(CXXINCS)   -O3
CFLAGS = $(INCS)   -O3
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before run all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

run: $(OBJ)
	$(CPP) main.cpp -o "sistema de inventario universidad.exe"

main.o: main.cpp
	g++ -c main.cpp -o main.o $(CXXFLAGS)
