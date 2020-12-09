#include <iostream>
#include <algorithm>

#include "videojuego.h"
#include "menucivilizacion.h"

using namespace std;

int main()
{
    Videojuego v;
    Civilizacion c;
    string opc;

    while (true)
    {
        cout << "1) Usuario" << endl;
        cout << "2) Agregar civilizacion" << endl;
        cout << "3) Insertar civilizacion" << endl;
        cout << "4) Crear civilizacion" << endl;
        cout << "5) Primera civilizacion" << endl;
        cout << "6) Ultima civilizacion" << endl;
        cout << "7) Ordenar" << endl;
        cout << "8) Eliminar civilizacion" << endl;
        cout << "9) Buscar" << endl;
        cout << "10) Modificar" << endl;
        cout << "11) Resumen" << endl;
        cout << "12) Respaldar" << endl;
        cout << "13) Recuperar" << endl;
        cout << "0) Salir" << endl;
        getline(cin, opc);

        if (opc == "1")
        {
            string u;
            cout << "Usuario: ";
            getline(cin, u);
            v.setUsuario(u);
        }
        else if (opc == "2")
        {
            Civilizacion c;
            cin >> c;

            v.agregar(c);
            cin.ignore();
        }
        else if (opc == "3")
        {
            Civilizacion c;
            cin >> c;
            size_t pos;
            cout << "Posicion: ";
            cin >> pos;
            cin.ignore();
            if (pos >= v.size())
            {
                cout << "Posicion no valida" << endl;
            }
            else
            {
                v.insertar(c, pos);
            }
        }
        else if (opc == "4")
        {
            Civilizacion c;
            cin >> c;

            size_t n;
            cout << "n: ";
            cin >> n;
            cin.ignore();

            v.crear(c, n);
        }
        else if (opc == "5")
        {
            if (v.empty())
            {
                cout << "Vector esta vacio" << endl;
            }
            else
            {
                v.primera();
            }
        }
        else if (opc == "6")
        {
            if (v.empty())
            {
                cout << "Vector esta vacio" << endl;
            }
            else
            {
                v.ultima();
            }
        }
        else if (opc == "7")
        {
            v.ordenar();
        }
        else if (opc == "8")
        {
            Civilizacion c;
            cin >> c;
            cin.ignore();

            Civilizacion *ptr = v.eliminar(c);
            if (ptr == nullptr)
            {
                cout << "No encontrado" << endl;
            }
        }
        else if (opc == "9")
        {
            string opc;
            Civilizacion c;
            cin >> c;
            cin.ignore();

            Civilizacion *ptr = v.buscar(c);

            if (ptr == nullptr)
            {
                cout << "No encontrado" << endl;
            }
            else
            {
                cout << *ptr << endl;
                menu();
            }
        }
        else if (opc == "10")
        {
            Civilizacion c;
            cin >> c;
            cin.ignore();

            Civilizacion *ptr = v.buscar(c);

            if (ptr == nullptr)
            {
                cout << "No encontrado" << endl;
            }
            else
            {
                cout << "Modificar." << endl;
                cout << *ptr << endl;
                v.eliminar(c);
                cin >> c;
                v.agregar(c);
                cin.ignore();
            }
        }
        else if (opc == "11")
        {
            v.total();
        }
        else if (opc == "12")
        {            
            v.respaldar();
        }
        else if (opc == "13")
        {
            v.recuperar();
        }

        else if (opc == "0")
        {
            break;
        }
    }

    return 0;
}