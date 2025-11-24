// 01 de la solemne 
#include <iostream>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Encuestas {
    private:
        queue<string> encuesta_1;
        stack<string> encuesta_2;

    public:
        Encuestas() {};

        void insertarRespuesta (int numeroEncuesta , string respuesta ){
            if (numeroEncuesta == 1){
                encuesta_1.push(respuesta);
            } else if (numeroEncuesta == 2){
                encuesta_2.push(respuesta);
            } else {
                cout << "numero de encuesta invalido" << endl;
            }
        }

        int cantidadCambioRespuesta () {
            if (encuesta_1.size() != encuesta_2.size()){
                return -1;
            }

            queue<string> colaAux = encuesta_1;
            stack<string> pilaAux = encuesta_2;

            int cambios = 0;

            while(!colaAux.empty()){
                if(colaAux.front() != pilaAux.top()){
                    cambios++;
                }

                colaAux.pop();
                pilaAux.pop();
            }

            return cambios;
        }
        
        void imprimeResultadoEncuesta2(){
            stack<string> pilaAux = encuesta_2;
            map<string, int> resultados;

            // int af = 0, ec = 0, i = 0, nc = 0;

            while (!pilaAux.empty()){
                string respuesta =  pilaAux.top();

                // if (respuesta == "A favor"){
                //     af++;
                // } else if (respuesta == "En contra"){
                //     ec++;
                // } else if(respuesta == "Indeciso"){
                //     i++;
                // } else {
                //     nc++;
                // }

                resultados[respuesta]++;

                pilaAux.pop();
            }

            for (auto &par : resultados){
                cout << "cantidad " << par.first << ": " << par.second << endl;
            }

            // cout << "cantidad de a favor: "<< af << endl;
        }
    
};

int main() {

    Encuestas *e = new Encuestas();

    e->insertarRespuesta(1, "A favor"); // persona 1
    e->insertarRespuesta(1, "En contra"); // persona 2
    e->insertarRespuesta(1, "Indeciso"); // persona 3

    // prueba con 1 cambio 
    e->insertarRespuesta(2, "Indeciso"); // persona 3
    e->insertarRespuesta(2, "En contra"); // persona 2
    e->insertarRespuesta(2, "En contra"); // persona 1
    cout << "cantidad de cambios: " << e->cantidadCambioRespuesta() << endl;

    e->imprimeResultadoEncuesta2();

    return 0;
}