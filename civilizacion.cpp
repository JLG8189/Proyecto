#include "civilizacion.h"
//#include "menucivilizacion.h"


Civilizacion::Civilizacion()
{
}

/*Civilizacion::Civilizacion(const string &nombre, int ubicX, int ubicY, int puntos)
{
    this->nombre = nombre;
    this->ubicX = ubicX;
    this->ubicY = ubicY;
    this->puntos = puntos;
}*/

void Civilizacion::setNombre(const string &v)
{
    nombre = v;
}

size_t Civilizacion::empty()
{
    return aldeanos.empty();
}

string Civilizacion::getNombre()
{
    return nombre;
}

void Civilizacion::setUbicX(int v)
{
    ubicX = v;
}

int Civilizacion::getUbicX()
{
    return ubicX;
}

void Civilizacion::setUbicY(int v)
{
    ubicY = v;
}

int Civilizacion::getUbicY()
{
    return ubicY;
}
void Civilizacion::setPuntos(int v)
{
    puntos = v;
}

int Civilizacion::getPuntos()
{
    return puntos;
}

void Civilizacion::agregarFinal(const Aldeano &a)
{
    aldeanos.push_back(a);
}

void Civilizacion::agregarInicio(const Aldeano &a)
{
    aldeanos.push_front(a);
}

void Civilizacion::print()
{
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        cout << *it << endl;
    }
}

void Civilizacion::eliminarNombre(const string &nombre)
{
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        Aldeano &a = *it;

        if (nombre == a.getAldeano())
        {
            aldeanos.erase(it);
            break;
        }
    }
}

bool comparador(const Aldeano &a)
{
    return a.getEdad() >= 60;
}

void Civilizacion::eliminarEdad()
{
    aldeanos.remove_if(comparador);
}

void Civilizacion::eliminarSalud(size_t salud)
{
    aldeanos.remove_if([salud](const Aldeano &a) { return a.getEdad() == salud; });
}

void Civilizacion::ordenarNombre()
{
    aldeanos.sort();
}

bool comparadorEdad(const Aldeano &a1, const Aldeano &a2)
{
    return a1.getEdad() > a2.getEdad();
}

void Civilizacion::ordenarEdad()
{
    aldeanos.sort(comparadorEdad);
}

void Civilizacion::ordenarSalud()
{
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2) { return a1.getSalud() > a2.getSalud(); });
}

void Civilizacion::buscar(const string &nombre)
{
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        Aldeano &a = *it;

        if (nombre == a.getAldeano())
        {
            cout << *it << endl;
        }
        else
        {
            cout << "No encontrado." << endl;
        }
    }
}

void Civilizacion::modificar(const string &nombre)
{
    for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
    {
        Aldeano &a = *it;

        if (nombre == a.getAldeano())
        {
            cout << *it << endl;
        }
        else if (nombre != a.getAldeano())
        {
            cout << "No encontrado." << endl;
        }
    }
}

void Civilizacion::respaldar_aldeanos()
{
    ofstream archivo(getNombre() + ".txt", ios::out);
    if(archivo.is_open())
    {
        for (auto it = aldeanos.begin(); it != aldeanos.end(); it++)
        {
            Aldeano &a = *it;
            archivo << a.getAldeano() << endl;
            archivo << a.getEdad() << endl;
            archivo << a.getGenero() << endl;
            archivo << a.getSalud() << endl;
        }
    }
    archivo.close();
}

void Civilizacion::recuperar_aldeanos()
{
    ifstream archivo(getNombre() + ".txt");
    if (archivo.is_open())
    {
        Aldeano a;
        string temp;
        int edad;
        string genero;;
        int salud;

        while (true)
        {
            getline(archivo, temp);
            if (archivo.eof())
            {
                break;
            }
            a.setAldeano(temp);

            getline(archivo, temp);
            edad = stoi(temp);
            a.setEdad(edad);

            getline(archivo, temp);
            a.setGenero(genero);

            getline(archivo, temp);
            salud = stoi(temp);
            a.setSalud(salud);

            agregarFinal(a);
        }
    }
    archivo.close();
}