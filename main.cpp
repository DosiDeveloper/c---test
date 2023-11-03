/**
 * Este es el archivo principal del sistema de inventario
 * Author: Douglas Barreto
 * Seccion: FL-1410612+
*/
#include <iostream>
#include "inventario.cpp"

using namespace std;

int main()
{
    Inventario ivnt = Inventario("data.txt");
    ivnt.menu();

    return 0;
}
