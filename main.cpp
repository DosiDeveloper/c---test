/**
 * Este es el archivo principal del sistema de inventario
 * Autores:
 *  - Douglas Barreto C.I:29.966.810
 *  - Luis Lima C.I:30.242.817
 *  - Diego Perez C.I:30.346.809
 * Seccion: FL-1410612
 */
#include <iostream>
#include "inventario.cpp"

using std::cout;
using std::cin;

int main()
{   
    int select;
    do
    {
        system("cls");
        cout.setf(std::ios::right, std::ios::left);
        cout.width(50);
        cout << std::left << "Elija una de las acciones que desee realizar en el sistema de inventario"
             << endl;
        cout << std::left << "- Crear un nuevo registro en el inventario ( 1 )"
             << endl;
        cout << std::left << "- Consultar un registro en el inventario ( 2 )"
             << endl;
        cout << std::left << "- Eliminar un registro existente en el inventario ( 3 )"
             << endl;
        cout << std::left << "- Editar un registro existente en el inventario ( 4 )"
             << endl;
        cout << std::left << "- Salir del programa, cualquier otro numero para salir"
             << endl;
        cout << std::right << "* Su seleccion: ";
        cin >> select;

        switch (select)
        {
        case 1:
            registro();
            break;
        case 2:
            consulta();
            break;
        case 3:
            break;
        
        case 4:
            break;

        default:
            system("cls");
            std::cout << "Hasta la proxima!";
            break;
        }
    } while (select < 4);

    return 0;
}
