/**
 * Este es el archivo principal del sistema de inventario
 * Autores:
 *  - Douglas Barreto C.I:29.966.810
 *  - Luis Lima C.I:30.242.817
 *  - Diego Perez C.I:30.346.809
 * Seccion: FL-1410612
 */
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::stoi;
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

//hay que arreglar esto para que se vea menos sacado de internet xd
std::string getSubstring(const string& str, size_t pos)
{
    std::string result;
    for (size_t i = pos; i < str.length(); ++i)
    {
        result += str[i];
    }
    return result;
}

// esta funcion elimina el espacio en blanco al final de la cadena de texto
static inline void ltrim(string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

void registro()
{
    while (true)
    {
        system("cls");
        if (!archivoActivo.is_open())
            archivoActivo.open(nombre_archivo, std::ios::app);

        cout << "Ingrese los siguientes datos:" << endl;
        cout << "- Identificador: ";
        cin >> camposInv.NBP;
        ltrim(camposInv.NBP);
        cout << "- Marca: ";
        cin >> camposInv.MARCA;
        ltrim(camposInv.MARCA);
        cout << "- Departamento: ";
        cin >> camposInv.DEPTO;
        ltrim(camposInv.DEPTO);
        cout << "- Usuario: ";
        getline(cin, camposInv.USUARIO);
        ltrim(camposInv.USUARIO);

        tiempo_b << std::put_time(&tlocal, "%d/%m/%Y");
        camposInv.FECHAREGISTRO = tiempo_b.str();
        camposInv.FECHADESIN = "00/00/0000";
        camposInv.FECHAMOD = "00/00/0000";

        cout << "Estos son los datos ingresados: " << endl;
        cout << camposInv.toString() << endl;

        char select;
        cout << "Desea ingresar otro registro? " << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cin >> select;
        cout << endl;
        if (select == '1')
        {
            archivoActivo << camposInv.toString().c_str() << endl;
            continue;
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
    int i = 0;

    system("cls");
    if (!archivoActivo.is_open())
        archivoActivo.open(nombre_archivo, std::ios::in);

    std::vector<string> lineas;
    string linea;
    string select;

    while (archivoActivo >> linea)
        lineas.push_back(linea);

    cout << "Ingrese el numero de bien publico que desea buscar: ";
    cin >> select;
    cout << select << endl;
    for (int i = 0; i < lineas.size(); i++)
    {
    size_t pos = lineas[i].find(select.c_str());
    string substring = getSubstring(lineas[i], pos);
    std::stringstream ss(substring);

    cout << "- Identificador: " << lineas[i].NBP << endl;
    cout << "- Marca: " << lineas[i].MARCA << endl; 
    cout << "- Departamento: " << lineas[i].DEPTO << endl;
    cout << "- Usuario: " << lineas[i].USUARIO << endl;
    cout << "- Fecha de Registro: " << lineas[i].FECHAREGISTRO << endl;
    cout << "- Fecha de Modificación: " << lineas[i].FECHAMOD << endl;
    cout << "- Fecha de Desincorporación: " << lineas[i].FECHADESIN << endl;
    }

    system("pause");

    return;
}

void modificar()
{
    system("cls");
    return;
}

void editar()
{
    system("cls");
    return;
}

int main()
{
    system("mkdir data");
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
            modificar();
            break;

        case 4:
            editar();
            break;

        default:
            system("cls");
            break;
        }
    } while (select < 4);

    return 0;
}
