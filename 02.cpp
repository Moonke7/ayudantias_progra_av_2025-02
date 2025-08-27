#include <iostream>
using namespace std;

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
            notas[i] = NULL;
        }
    }
    string getNombre()
    {
        return nombre;
    }
    string getRut()
    {
        return rut;
    }

    void agregarNota(float nota){
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
    float getPromedio(){
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
        if (contador == 0) return 0;
        return suma / contador;
    }
    void mostrarInformacion(){
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

int
main()
{
    /* CuentaBancaria *cuenta = new CuentaBancaria("Juan Perez");
    cuenta->Depositar(500);
    cuenta->Retirar(200);
    cuenta->setTitular("Maria Gomez");
    cout << "Titular: " << cuenta->getTitular() << endl;
    cout << "Saldo: " << cuenta->getSaldo() << endl; */

    
    return 0;
}