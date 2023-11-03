/**
 * Este es el archivo que contiene las principales funciones del sistema de inventario
 *
 *
 */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

std::ofstream archivoActivo;
time_t tiempo = time(0);
auto tlocal = *localtime(&tiempo);
std::ostringstream tiempo_b;

struct inventario
{
    int NBP;
    string MARCA;
    string DEPTO;
    string USUARIO;
    string FECHAREGISTRO;
    string FECHAMOD;
    string FECHADESIN;
    string toString()
    {
        return NBP + " | " + MARCA + " | " + DEPTO + " | " + USUARIO + " | " + FECHAREGISTRO + " | " + FECHAMOD + " | " + FECHADESIN;
    }
} camposInv;


void registro()
{
    while (true)
    {
        system("cls");
        if (!archivoActivo.is_open())
            archivoActivo.open("data/data.txt", std::ios::app);

        cout << "Ingrese los siguientes datos: " << endl;
        cout << "- Identificador: ";
        cin >> camposInv.NBP;
        cout << "- Marca: ";
        cin >> camposInv.MARCA;
        cout << "- Departamento: ";
        cin >> camposInv.DEPTO;
        cout << "- Usuario: ";
        cin >> camposInv.USUARIO;

        tiempo_b << std::put_time(&tlocal, "%d/%m/%Y");
        camposInv.FECHAREGISTRO = tiempo_b.str();
        camposInv.FECHADESIN = "00/00/0000";
        camposInv.FECHAMOD = "00/00/0000";

        cout << "Estos son los datos ingresados: " << endl;
        cout << camposInv.toString() << endl;

        char select;
        cout << "¿Desea ingresar otro registro?";
        cin >> select;
        if (select == 'y' || select == 'Y')
        {
            archivoActivo.write(camposInv.toString().c_str(), sizeof camposInv.toString().c_str());
            archivoActivo.close();
        }
        else
        {
            break;
        }
    }

    return;
}
