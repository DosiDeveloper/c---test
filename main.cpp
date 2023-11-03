/**
 * Este es el archivo principal del sistema de inventario
 * Author: Douglas Barreto
 * Seccion: FL-1410612+
*/
#include <iostream>
#include "inventario.cpp"

using std::cout;
using std::cin;

int main()
{
    do
    {
        system("cls");
        int select;
        cin.setf(std::ios::right);
        cout << std::left << "Elija una de las acciones que desee realizar en el sistema de inventario"
             << endl;
        cout << std::left << "- Crear un nuevo registro en el inventario ( 1 )"
             << endl;
        cout << std::left << "- Eliminar un registro existente en el inventario ( 2 )"
             << endl;
        cout << std::left << "- Editar un registro existente en el inventario ( 3 )"
             << endl;
        cout << std::left << "- Salir del programa, cualquier otro numero para salir"
             << endl;
        cout << std::right << "* Su seleccion: ";
        cin >> select;

        switch (select)
        {
        case 1:
            registro();

        case 2:
            break;

        case 3:
            break;

        default:
            std::cout << "Seleccione una opcion valida";
            break;
        }
    } while (true);

    return 0;
}
