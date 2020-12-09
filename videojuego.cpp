#include "videojuego.h"

Videojuego::Videojuego()
{
}

Videojuego::Videojuego(const string &usuario)
{
    this->usuario = usuario;
}

void Videojuego::setUsuario(const string &v)
{
    usuario = v;
}

string Videojuego::getUsuario()
{
    return usuario;
}

size_t Videojuego::size()
{
    return civilizaciones.size();
}

size_t Videojuego::empty()
{
    return civilizaciones.empty();
}

void Videojuego::agregar(const Civilizacion &c)
{
    civilizaciones.push_back(c);
}

void Videojuego::insertar(const Civilizacion &c, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin() + pos, c);
}

void Videojuego::crear(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

void Videojuego::primera()
{
    Civilizacion &c = civilizaciones.front();
    cout << c;
}

void Videojuego::ultima()
{
    Civilizacion &c = civilizaciones.back();
    cout << c;
}

void Videojuego::ordenar()
{
    string opc;
    cout << "1) Ordenar por nombre" << endl;
    cout << "2) Ordenar por ubicacion X" << endl;
    cout << "3) Ordenar por ubicacion Y" << endl;
    cout << "4) Ordenar por puntos" << endl;
    cout << "5) Salir" << endl;
    getline(cin, opc);

    if (opc == "1")
    {
        ordenarNombre();
    }
    else if (opc == "2")
    {
        ordenarX();
    }
    else if (opc == "3")
    {
        ordenarY();
    }
    else if (opc == "4")
    {
        ordenarPuntos();
    }
    else if (opc == "5")
    {
    }
}

void Videojuego::respaldar()
{
    ofstream archivo("civilizaciones.txt");
    if (archivo.is_open())
    {
        for (size_t i = 0; i < civilizaciones.size(); ++i)
        {
            Civilizacion &c = civilizaciones[i];
            archivo << c.getNombre() << endl;
            archivo << c.getUbicX() << endl;
            archivo << c.getUbicY() << endl;
            archivo << c.getPuntos() << endl;
            c.respaldar_aldeanos();
        }
    }
    archivo.close();
}

void Videojuego::recuperar()
{
    ifstream archivo("civilizaciones.txt");
    if (archivo.is_open())
    {
        Civilizacion c;
        string temp;
        int ux;
        int uy;
        int puntos;

        while (true)
        {
            getline(archivo, temp);
            if (archivo.eof())
            {
                break;
            }
            c.setNombre(temp);

            getline(archivo, temp);
            ux = stoi(temp);
            c.setUbicX(ux);

            getline(archivo, temp);
            uy = stoi(temp);
            c.setUbicY(uy);

            getline(archivo, temp);
            puntos = stoi(temp);
            c.setPuntos(puntos);

            agregar(c);
            c.recuperar_aldeanos();
        }
    }
    archivo.close();
}

void Videojuego::ordenarNombre()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getNombre() < c2.getNombre(); });
}
void Videojuego::ordenarX()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getUbicX() < c2.getUbicX(); });
}
void Videojuego::ordenarY()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getUbicY() < c2.getUbicY(); });
}
void Videojuego::ordenarPuntos()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getPuntos() > c2.getPuntos(); });
}

Civilizacion *Videojuego::eliminar(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if (it == civilizaciones.end())
    {
        return nullptr;
    }
    else
    {
        civilizaciones.erase(it);
        return 0;
    }
}

Civilizacion *Videojuego::buscar(const Civilizacion &c)
{

    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if (it == civilizaciones.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}

void Videojuego::total()
{
    cout << endl;
    cout << "Numero de civilizaciones: " << civilizaciones.size() << endl
         << endl;
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(17) << "Ubicacion en X";
    cout << setw(17) << "Ubicacion en Y";
    cout << setw(12) << "Puntuacion";
    cout << endl;
    for (size_t i = 0; i < civilizaciones.size(); i++)
    {
        Civilizacion &c = civilizaciones[i];
        cout << c;
    }
}
