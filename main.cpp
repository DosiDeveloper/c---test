#include <iostream>
#include "inventario.cpp"

using namespace std;

int main()
{
    Inventario ivnt = Inventario("data.txt");
    ivnt.menu();

    return 0;
}
