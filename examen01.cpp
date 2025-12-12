#include <iostream>
#include <map>
#include <vector>

using namespace std;

class PreciosDiarios{
    private: 
        map<string, vector<int> > precios;

    public:
        PreciosDiarios(){};

        void registrarPrecio(string producto, int precio){
            precios[producto].push_back(precio); 
        }

        float promedioSemanal(string producto){
            vector<int> Aux = precios[producto];
            
            int contadorDias = 0;
            int suma = 0;

            for (int i = Aux.size() - 1; i >= 0; i--){
                if (contadorDias == 7){
                    return suma / 7;
                }
                suma += Aux[i];
                contadorDias++;
            }

            return suma / contadorDias;
        }

        int precioMenorRegistrado(string producto){
            vector<int> Aux = precios[producto];

            if (Aux.size() == 0){
                return -1;
            }

            int menor = Aux[0];

            for (int i = 0; i < Aux.size(); i++){
                if (Aux[i] < menor){
                    menor = Aux[i];
                }
            }

            return menor;
        }

        void imprimirInventario(){
            for(auto &producto : precios){
                cout << producto.first << endl;

                vector<int> aux = producto.second;

                cout << aux[aux.size() - 1] << endl;
            }
        }

};

int main(){
    map<string, int> mapa1;

    mapa1["hola"] = 1;
    mapa1["hola2"] = 2;
    mapa1["hola3"] = 3;


    for (auto &par : mapa1){
        cout << par.first << endl;
        cout << par.second << endl;
    }
}