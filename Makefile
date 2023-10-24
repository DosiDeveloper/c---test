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

all: all-before "sistema de inventario universidad.exe" all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "sistema de inventario universidad.exe" $(LIBS)

main.o: main.cpp
	g++ -c main.cpp -o main.o $(CXXFLAGS)

inventario.o: inventario.cpp
	g++ -c inventario.cpp -o inventario.o $(CXXFLAGS)
