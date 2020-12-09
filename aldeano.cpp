#include "aldeano.h"

void Aldeano::setAldeano(const string &nombre)
{
    this->nombre = nombre;
}

string Aldeano::getAldeano() const
{
    return nombre;
}

void Aldeano::setEdad(size_t edad)
{
    this->edad = edad;
}

size_t Aldeano::getEdad() const
{
    return edad;
}

void Aldeano::setGenero(const string &genero)
{
    this->genero = genero;
}

string Aldeano::getGenero() const
{
    return genero;
}

void Aldeano::setSalud(size_t salud)
{
    this->salud = salud;
}

size_t Aldeano::getSalud() const
{
    return salud;
}