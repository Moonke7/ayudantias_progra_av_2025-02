#include <iostream>
using namespace std;

// ------------------ EJERCICIO 1 --------------------
class CuentaBancaria
{
private:
    string titular;
    int saldo;

public:
    CuentaBancaria(string _titular)
    {
        titular = _titular;
        saldo = 0;
    }
    void Depositar(int cantidad)
    {
        saldo += cantidad;
        cout << "Deposito exitoso, nuevo saldo: " << saldo << endl;
    }
    void Retirar(int cantidad)
    {
        if (cantidad > saldo)
        {
            cout << "Fondos insuficientes" << endl;
            return;
        }
        saldo -= cantidad;
        cout << "Retiro exitoso, nuevo saldo: " << saldo << endl;
    }
    void setTitular(string _titular)
    {
        titular = _titular;
    }
    string getTitular()
    {
        return titular;
    }
    int getSaldo()
    {
        return saldo;
    }
};

// ------------------ EJERCICIO 2 --------------------
class Alumno
{
private:
    string nombre, rut;
    float notas[10];

public:
    Alumno(string _nombre, string _rut)
    {
        nombre = _nombre;
        rut = _rut;
        for (int i = 0; i < 10; i++)
        {
            notas[i] = 0;
        }
    }
    // getters
    string getNombre()
    {
        return nombre;
    }
    string getRut()
    {
        return rut;
    }

    // setters
    void setNombre(string _nombre)
    {
        nombre = _nombre;
    }
    void setRut(string _rut)
    {
        rut = _rut;
    }

    // metodos
    void agregarNota(float nota)
    {
        for (int i = 0; i < 10; i++)
        {
            if (notas[i] == NULL)
            {
                notas[i] = nota;
                return;
            }
        }
        cout << "No se pueden agregar más notas" << endl;
    }

    float getPromedio()
    {
        float suma = 0;
        int contador = 0;
        for (int i = 0; i < 10; i++)
        {
            if (notas[i] != NULL)
            {
                suma += notas[i];
                contador++;
            }
        }
        if (contador == 0)
            return 0;
        return suma / contador;
    }
    void mostrarInformacion()
    {
        cout << "Nombre: " << nombre << endl;
        cout << "RUT: " << rut << endl;
        cout << "Notas: ";
        for (int i = 0; i < 10; i++)
        {
            if (notas[i] != NULL)
            {
                cout << notas[i] << " ";
            }
        }
        cout << endl;
        cout << "Promedio: " << getPromedio() << endl;
    }
};

// ------------------ EJERCICIO 3 --------------------
class Libro
{
private:
    string titulo, autor;

public:
    Libro(string _titulo, string _autor)
    {
        titulo = _titulo;
        autor = _autor;
    }

    // setters
    string getTitulo()
    {
        return titulo;
    }
    string getAutor()
    {
        return autor;
    }
    // getters
    void setTitulo(string _titulo)
    {
        titulo = _titulo;
    }
    void setAutor(string _autor)
    {
        autor = _autor;
    }

    // metodos
    void mostrarInfo()
    {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
    }
};

class Biblioteca
{
private:
    string nombre;
    int cantidad_libros;
    Libro *libros[5];

public:
    Biblioteca(string _nombre)
    {
        nombre = _nombre;
        cantidad_libros = 0;
        for (int i = 0; i < 5; i++)
        {
            libros[i] = NULL;
        }
    }

    // metodos
    void agregarLibro(Libro *libro)
    {
        for (int i = 0; i < 5; i++)
        {
            if (libros[i] == NULL)
            {
                libros[i] = libro;
                cantidad_libros++;
                return;
            }
        }
        cout << "No se pueden agregar más libros" << endl;
    }

    void mostrarLibros()
    {
        cout << "Libros en la biblioteca " << nombre << ":" << endl;
        for (int i = 0; i < cantidad_libros; i++)
        {
            libros[i]->mostrarInfo();
        }
    }
};

int main()
{
    /* CuentaBancaria *cuenta = new CuentaBancaria("Juan Perez");
    cuenta->Depositar(500);
    cuenta->Retirar(200);
    cuenta->setTitular("Maria Gomez");
    cout << "Titular: " << cuenta->getTitular() << endl;
    cout << "Saldo: " << cuenta->getSaldo() << endl; */

    /* Alumno *alumno = new Alumno("Pedro", "12345678-9");
    alumno->agregarNota(6.5);
    alumno->agregarNota(7.0);
    alumno->agregarNota(5.5);
    alumno->mostrarInformacion(); */

    Biblioteca *biblioteca = new Biblioteca("Biblioteca Central");
    Libro *libro1 = new Libro("El Quijote", "Miguel de Cervantes");
    Libro *libro2 = new Libro("Las locuras del mono", "George Orwell");
    biblioteca->agregarLibro(libro1);
    biblioteca->agregarLibro(libro2);
    biblioteca->mostrarLibros();

    return 0;
}