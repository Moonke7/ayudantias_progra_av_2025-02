#include <iostream>
#include <map>

using namespace std;

class Cuenta{
    private:
        string titular;
        int saldo;
    public:
        Cuenta(string _titular, int _saldo){
            titular = _titular;
            saldo = _saldo;
        }

        string getTitular(){
            return titular;
        }
        int getSaldo(){
            return saldo;
        }
};

int main(){
    map<int, Cuenta*> cuentas;
    map<int, Cuenta*>::iterator it;

    cuentas[1] = new Cuenta("Jose", 1000);
    cuentas[2] = new Cuenta("Juan", 2000);
    cuentas[3] = new Cuenta("Marcos", 3000);
    cuentas[4] = new Cuenta("Luis", 4000);
    cuentas[5] = new Cuenta("Ana", 5000);

    float sumaSaldos = 0;
    for(it = cuentas.begin(); it != cuentas.end(); it++){
        sumaSaldos += it->second->getSaldo();
    }

    float promedio = sumaSaldos / cuentas.size();
    cout << "Promedio de saldos: " << promedio << endl;

    // buscando el numero de cta = 2
    it = cuentas.find(2);
    if(it != cuentas.end()){
        cout << "Titular de la cuenta 2: " << it->second->getTitular() << endl;
        cout << "Saldo de la cuenta 2: " << it->second->getSaldo() << endl;
    } else {
        cout << "No se encontro la cuenta 2" << endl;
    }

    // lo de borrar me parece que no se usa mucho, asiq podian ignorarlo, pero asi se hace
    it = cuentas.find(3);
    if (it != cuentas.end()){
        cuentas.erase(it);
        cout << "Cuenta 3 borrada" << endl;
    }

    return 0;
}