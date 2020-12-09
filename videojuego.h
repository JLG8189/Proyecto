#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <vector>
#include <fstream>
#include <algorithm>

#include "civilizacion.h"
//#include "aldeano.h"

class Videojuego
{
    string usuario;
    vector<Civilizacion> civilizaciones;

public:
    Videojuego();
    Videojuego(const string &usuario);
    void setUsuario(const string &v);
    string getUsuario();
    size_t size();
    size_t empty();
    void agregar(const Civilizacion &c);
    void insertar(const Civilizacion &c, size_t pos);
    void crear(const Civilizacion &c, size_t n);
    void primera();
    void ultima();
    void ordenarNombre();
    void ordenarX();
    void ordenarY();
    void ordenarPuntos();
    void ordenar();
    void respaldar();
    void recuperar();
    Civilizacion *eliminar(const Civilizacion &c);
    Civilizacion *buscar(const Civilizacion &c);
    void total();

    friend Videojuego &operator<<(Videojuego &v, const Civilizacion &c)
    {
        v.agregar(c);
        return v;
    }
};

#endif