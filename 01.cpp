#include <iostream>
#include <cmath>
using namespace std;

/* int main()
{
    int *puntero;
    int valor = 8;
    puntero = &valor;

    cout << *puntero << endl;

    cout << "Cambiando valor de valor a 20" << endl;
    valor = 20;
    cout << *puntero << endl;

    return 0;
}

class Persona
{
public:
    Persona(string _nombre)
    {
        nombre = _nombre;
    }
    Persona(string _nombre, int _edad)
    {
        nombre = _nombre;
        edad = _edad;
    }
    Persona()
    {
    }
    int edad;
    string nombre;
};

class Rectangulo
{
public:
    Rectangulo()
    {
    }
    int area()
    {
        return (largo * ancho);
    }
    int perimetro()
    {
        return (2 * largo + 2 * ancho);
    }
    int largo, ancho;
};

class Nombre
{
public:
    // atributos y metodos
    string nombre;
};

class Rectangulo // nombre
{
public: //acceso
    int largo, ancho; // atributos
    int area(); // metodo
    int perimetro(); // metodo
};

int main (){
    Rectangulo rec; // creacion de objeto
    rec.largo = 10; // valor a atributo
    rec.ancho = 5; // valor a atributo
    rec.area(); // llamada a metodo
} */

class Rectangulo
{
public:
    int largo, ancho;

    Rectangulo(int L, int A)
    {
        largo = L;
        ancho = A;
    };
    Rectangulo()
    {
    }
    int area()
    {
        return (largo * ancho);
    }
    int perimetro()
    {
        return (2 * largo + 2 * ancho);
    }
};

int AreaMayor(Rectangulo r1, Rectangulo r2)
{
    if (r1.area() > r2.area())
    {
        return r1.area();
    }
    else
    {
        return r2.area();
    }
}

class PuntoCartesiano
{
public:
    int varX;
    int varY;

    PuntoCartesiano(int x, int y)
    {
        varX = x;
        varY = y;
    }

    int distanciaOrigen()
    {
        return sqrt(varX * varX + varY * varY);
    }
};

int DistanciaEntrePuntos(PuntoCartesiano p1, PuntoCartesiano p2)
{
    int dx = p2.varX - p1.varX;
    int dy = p2.varY - p1.varY;
    return sqrt(dx * dx + dy * dy);
}

class Producto
{
public:
    float precio;
    string nombre;
    Producto(float p, string n)
    {
        precio = p;
        nombre = n;
    }

    float AplicarDescuento(float porcentaje)
    {
        return precio - (precio * porcentaje / 100.0);
    }
};

void compararPrecios(Producto p1, Producto p2)
{
    float precio2 = p2.AplicarDescuento(20); 

    if (p1.precio < precio2)
    {
        cout << p1.nombre << " es más barato que " << p2.nombre << endl;
    }
    else if (p1.precio > precio2)
    {
        cout << p2.nombre << " es más barato que " << p1.nombre << endl;
    }
    else
    {
        cout << "Ambos productos tienen el mismo precio." << endl;
    }
}

int main()
{
    /* Rectangulo r1(10, 5);
    Rectangulo r2(8, 6);
    int areaMayor = AreaMayor(r1, r2);
    cout << "El area mayor es: " << areaMayor << endl;
    return 0; */
}