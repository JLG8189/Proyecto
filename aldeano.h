#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Aldeano
{
public:
    Aldeano() {}
    Aldeano(const string &nombre, size_t edad, const string &genero, size_t salud)
        : nombre(nombre), edad(edad), genero(genero), salud(salud) {}

    void setAldeano(const string &nombre);
    string getAldeano() const;

    void setEdad(size_t edad);
    size_t getEdad() const;

    void setGenero(const string &genero);
    string getGenero() const;

    void setSalud(size_t salud);
    size_t getSalud() const;

    friend ostream &operator<<(ostream &out, const Aldeano &a)
    {
        out << left;
        out << setw(15) << a.getAldeano();
        out << setw(15) << a.getEdad();
        out << setw(15) << a.getGenero();
        out << setw(15) << a.getSalud();

        return out;
    }

    bool operator<(const Aldeano &a) const
    {
        return nombre < a.getAldeano();
    }

private:
    string nombre;
    size_t edad;
    string genero;
    size_t salud;
};

#endif