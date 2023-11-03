/**
 * Este es el archivo que contiene la clase de Inventario
 *
 * Contiene _ metodos (procedimientos), que realizan las siguientes funciones
 *
 *
 */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

struct camposInv
{
    int NBP;
    string MARCA;
    string DEPTO;
    string USUARIO;
    string FECHAREGISTRO;
    string FECHAMOD;
    string FECHADESIN;
    string toStringFormat()
    {
        return NBP + "|" + MARCA + "|" + DEPTO + "|" + USUARIO + "|" + FECHAREGISTRO + "|" + FECHAMOD + "|" + FECHADESIN;
    }
};

class Inventario
{
private:
    string nombreArchivo;
    std::ofstream archivoActivo;
    camposInv campInv;
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    std::ostringstream tiempo_b;


public:
    Inventario(string NombreArchivo)
    {
        system("cls");
        cout.setf(std::ios::adjustfield);
        cout.width(50);
        this->nombreArchivo = NombreArchivo;
        cout << "Bienvenido al Sistema de Inventario" << endl;
    }

    void insertarDataArchivo(string Data)
    {

        if (this->archivoActivo.fail())
        {
            cout << "No se pudo abrir el archivo";
            exit(1);
        }

        if (this->archivoActivo.is_open())
        {
            this->archivoActivo.write(Data.c_str(), sizeof Data.c_str());
        }
        else
        {
            this->archivoActivo.open(this->nombreArchivo);
            this->archivoActivo.write(Data.c_str(), sizeof Data.c_str());
        }
        return;
    }

    void insertarNuevoRegistro()
    {
        system("cls");
        while (true)
        {
            cout << "Ingrese los siguientes datos: " << endl;
            cout << "- Identificador: ";
            cin >> this->campInv.NBP;
            cout << "- Marca: ";
            cin >> this->campInv.MARCA;
            cout << "- Departamento: ";
            cin >> this->campInv.DEPTO;
            this->tiempo_b << std::put_time(&this->tlocal, "%d/%m/%Y");
            this->campInv.FECHAREGISTRO = this->tiempo_b.str();
            this->campInv.FECHAMOD = "00/00/0000";
            this->campInv.FECHADESIN = "00/00/0000";
            
            cout
                << "Estos son los datos ingresados: " << endl;


            cout << "Desea guardar e ingresar otro registro? (y / n): ";
            char select;
            cin >> select;
            if (select == 'y' || select == 'Y')
            {
                this->insertarDataArchivo(this->campInv.toStringFormat());
            }
            else
            {
                break;
            }
        }
        return;
    }

    void menu()
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
                this->insertarNuevoRegistro();

            case 2:
                break;

            case 3:
                break;

            default:
                std::cout << "Seleccione una opcion valida";
                break;
            }
        } while (true);
        return;
    }
};
