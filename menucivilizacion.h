#include <iostream>
#include "civilizacion.h"
#include "aldeano.h"

using namespace std;
Civilizacion c;

Aldeano capturar()
{
    Aldeano a;
    string nombre;
    size_t edad;
    size_t salud;
    string genero;

    cout << "Nombre: ";
    getline(cin, nombre);
    a.setAldeano(nombre);

    cout << "Edad: ";
    cin >> edad;
    a.setEdad(edad);
    cin.ignore();

    cout << "Genero: ";
    getline(cin, genero);
    a.setGenero(genero);

    cout << "Salud: ";
    cin >> salud;
    a.setSalud(salud);
    cin.ignore();

    return a;
}

void menu()
{

    while (true)
    {
        string opc;

        cout << "1) Agregar aldeano" << endl;
        cout << "2) Eliminar aldeano" << endl;
        cout << "3) Clasificar aldeanos" << endl;
        cout << "4) Buscar aldeano" << endl;
        cout << "5) Modificar aldeano" << endl;
        cout << "6) Mostrar aldeanos" << endl;
        cout << "0) Salir" << endl;
        getline(cin, opc);

        if (opc == "1")
        {
            cout << "1) Agregar al inicio." << endl;
            cout << "2) Agregar al final." << endl;
            getline(cin, opc);

            if (opc == "1")
            {
                Aldeano a = capturar();
                c.agregarInicio(a);
                c.setPuntos(c.getPuntos() + 100);
            }
            else if (opc == "2")
            {
                Aldeano a = capturar();
                c.agregarFinal(a);
                c.setPuntos(c.getPuntos() + 100);
            }
        }
        else if (opc == "2")
        {
            string opc;

            cout << "1) Eliminar por nombre." << endl;
            cout << "2) Eliminar por salud." << endl;
            cout << "3) Eliminar por edad." << endl;
            getline(cin, opc);

            if (opc == "1")
            {
                string nombre;
                cout << "Nombre: ";
                getline(cin, nombre);
                c.eliminarNombre(nombre);
            }
            else if (opc == "2")
            {
                size_t salud;
                cout << "Salud: ";
                cin >> salud;
                c.eliminarSalud(salud);
            }
            else if (opc == "3")
            {
                c.eliminarEdad();
            }
        }
        else if (opc == "3")
        {
            string opc;

            cout << "1) Ordenar por nombre." << endl;
            cout << "2) Ordenar por edad." << endl;
            cout << "3) Ordenar por salud." << endl;
            getline(cin, opc);

            if (opc == "1")
            {
                c.ordenarNombre();
            }
            else if (opc == "2")
            {
                c.ordenarEdad();
            }
            else if (opc == "3")
            {
                c.ordenarSalud();
            }
        }
        else if (opc == "4")
        {
            string nombre;

            cout << "Nombre: ";
            getline(cin, nombre);

            c.buscar(nombre);
        }
        else if (opc == "5")
        {
            string nombre;

            cout << "Nombre: ";
            getline(cin, nombre);
            c.modificar(nombre);
            c.eliminarNombre(nombre);
            Aldeano a = capturar();
            c.agregarFinal(a);
        }
        else if (opc == "6")
        {
            if (c.empty())
            {
                cout << "Lista vacia." << endl;
            }
            else
            {
                c.print();
            }
        }
        else if (opc == "0")
        {
            break;
        }
    }
}