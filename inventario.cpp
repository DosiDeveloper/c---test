#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <typeinfo>

using std::string;
using std::vector;

struct camposInv
{
    int idn;
    string marca;
    string nota;
};

class Inventario
{
private:
    string nombreArchivo;
    std::ofstream archivoActivo;
    vector<camposInv> registros;

public:
    Inventario(string NombreArchivo)
    {
        std::cout.setf(std::ios::left, std::ios::right);
        std::cout.width(50);
        this->nombreArchivo = NombreArchivo;
        std::cout << std::endl;
        std::cout << std::setfill('*') << "Bienvenido al Sistema de Inventario" << std::setfill('*') << std::endl;
        std::cout << std::endl;
    }

    insertarDataArchivo(string Data)
    {

        if (this->archivoActivo.fail())
        {
            std::cout << "No se pudo abrir el archivo";
            exit(1);
        }

        if (this->archivoActivo.is_open())
        {
            this->archivoActivo.write(Data.c_str(), sizeof Data);
        }
        else
        {
            this->archivoActivo.open(this->nombreArchivo);
            this->archivoActivo.write(Data.c_str(), sizeof Data);
        }
    }

    insertarNuevoRegistro()
    {
        while (true)
        {
            int idn;
            string marca, nota;
            std::cout << "Ingrese los siguientes datos: " << std::endl;
            std::cout << "- Identificador: ";
            std::cin >> idn;
            std::cout << "- Marca: ";
            std::cin >> marca;
            std::cout << "- Nota: ";
            std::cin >> nota;
            std::cout << "Estos son los datos ingresados: " << format << std::endl;
            std::cout << "Desea guardar e ingresar otro registro? (y / n): ";
            char select;
            std::cin >> select;
            if (select == 'y' || select == 'Y')
            {
                this->registros.push_back(camposInv{
                    idn,
                    marca,
                    nota});
            }
            else
            {
                break;
            }
        }
    }

    menu()
    {
        while (true)
        {

            int select;
            std::cin.setf(std::ios::right);
            std::cout << std::left << "Elija una de las acciones que desee realizar en el sistema de inventario"
                      << std::endl;
            std::cout << std::left << "Crear un nuevo registro en el inventario ( 1 )"
                      << std::endl;
            std::cout << std::left << "Eliminar un registro existente en el inventario ( 2 )"
                      << std::endl;
            std::cout << std::left << "Editar un registro existente en el inventario ( 3 )"
                      << std::endl;
            std::cout << std::left << "Salir del programa ( 4 )"
                      << std::endl;
            std::cout << std::right << "Su seleccion: ";
            std::cin >> select;

            switch (select)
            {
            case 1:
                this->insertarNuevoRegistro();

            case 2:
                break;

            case 3:
                break;

            default:
                std::cout << "Seleccione una opcion valida";
            }
        }
    }
};
