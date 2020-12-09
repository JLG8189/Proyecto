#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
#include <list>
#include <algorithm>
#include <fstream>

#include "aldeano.h"

using namespace std;

class Civilizacion
{
    string nombre;
    int ubicX;
    int ubicY;
    int puntos;
    list<Aldeano> aldeanos;

public:
    Civilizacion();
    Civilizacion(const string &nombre, int ubicX, int ubicY, int puntos){}
    size_t empty();
    void setNombre(const string &v);
    string getNombre();
    void setUbicX(int v);
    int getUbicX();
    void setUbicY(int v);
    int getUbicY();
    void setPuntos(int v);
    int getPuntos();

    void agregarFinal(const Aldeano &a);
    void agregarInicio(const Aldeano &a);
    void print();

    void eliminarNombre(const string &nombre);
    void eliminarEdad();
    void eliminarSalud(size_t salud);

    void ordenarNombre();
    void ordenarEdad();
    void ordenarSalud();

    void buscar(const string &nombre);
    void modificar(const string &nombre);

    void respaldar_aldeanos();
    void recuperar_aldeanos();

    friend ostream &operator<<(ostream &out, const Civilizacion &c)
    {
        out << left;
        out << setw(20) << c.nombre;
        out << setw(17) << c.ubicX;
        out << setw(17) << c.ubicY;
        out << setw(12) << c.puntos << endl;
        return out;
    }

    friend istream &operator>>(istream &in, Civilizacion &c)
    {
        cout << "Nombre: ";
        getline(cin, c.nombre);
        cout << "Ubicacion en X: ";
        cin >> c.ubicX;
        cout << "Ubicacion en Y: ";
        cin >> c.ubicY;
        cout << "Puntaje: ";
        cin >> c.puntos;
        return in;
    }

    bool operator==(const Civilizacion &c)
    {
        return nombre == c.nombre;
    }
    bool operator==(const Civilizacion &c) const
    {
        return nombre == c.nombre;
    }

    bool operator<(const Civilizacion &c)
    {
        return nombre < c.nombre;
    }
    bool operator<(const Civilizacion &c) const
    {
        return nombre < c.nombre;
    }
};

#endif