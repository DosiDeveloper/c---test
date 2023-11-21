/**
 * Este es el archivo que contiene las principales funciones del sistema de inventario
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

std::fstream archivoActivo;
time_t tiempo = time(0);
auto tlocal = *localtime(&tiempo);
std::ostringstream tiempo_b;
string nombre_archivo = "data/data.txt";

struct inventario
{
    string NBP;
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
            archivoActivo.open(nombre_archivo, std::ios::app);

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
        cout << "¿Desea ingresar otro registro? (y/n)? ";
        cin >> select;
        cout << endl;
        if (select == 'y' || select == 'Y')
        {
            archivoActivo << camposInv.toString().c_str() << endl;
        }
        else
        {
            archivoActivo << camposInv.toString().c_str() << endl;
            archivoActivo.close();
            break;
        }
    }

    return;
}

void consulta()
{

    system("cls");
    if (!archivoActivo.is_open())
        archivoActivo.open(nombre_archivo, std::ios::in);

    std::vector<string> lineas;
    string linea;
    string select;

    while (archivoActivo >> linea) lineas.push_back(linea);
    
    cout << "Ingrese el numero de bien publico que desea buscar: ";
    cin >> select;


    system("pause");

    return;
}
