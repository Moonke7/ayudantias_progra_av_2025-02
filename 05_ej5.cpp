#include <iostream>
#include <map>

using namespace std;

class Elecciones{
    private:
        map<string, map<string, int> > resultados;

    public:
        void agregarVotos(string region, string partido, int votos){
            resultados[region][partido] += votos;
        }

        map<string, int> calcularResultadosNacionales(){
            // primero, se crea el mapa auxiliar que despues se retornara
            map<string, int> totalPorPartido;

            // luego, se deben recorrer todas las regiones
            for(auto& region : resultados){
                // luego, se recorre el mapa interno que tiene cada region
                for(auto& partido : region.second){
                    // se guarda el nombre del partido como llave y se le suma la cantidad de votos de dicho partido
                    totalPorPartido[partido.first] += partido.second;
                }
            }

            return totalPorPartido;
        }

        void partidoGanadorPorRegion(){
            cout << "Partido ganador por region:" << endl;

            // se recorre el mapa principal para ver todas las regiones
            for(auto& region : resultados){
                string nombreRegion = region.first;

                // se inicializan las variables que guardaran el partido ganador y la cantidad de votos
                string partidoGanador;
                int maxVotos = 0;

                // se recorre el mapa interno para ver todos los partidos de la region actual
                for(auto& partido : region.second){
                    if(partido.second > maxVotos){
                        maxVotos = partido.second;
                        partidoGanador = partido.first;
                    }
                }

                cout << "- " << nombreRegion << ": " << partidoGanador << " con " << maxVotos << " votos" << endl;
            }
        }

        void informeConsolidado(){
            map<string, int> resultadosNacionales = calcularResultadosNacionales();

            cout << "Informe consolidado de elecciones:" << endl;
            for(auto& partido : resultadosNacionales){
                cout << "- " << partido.first << ": " << partido.second << " votos" << endl;
            }

            // ahora, se busca el ganador a nivel nacional
            string partidoGanador;
            int maxVotos = 0;
            for(auto& partido : resultadosNacionales){
                if(partido.second > maxVotos){
                    maxVotos = partido.second;
                    partidoGanador = partido.first;
                }
            }
            cout << "Partido ganador a nivel nacional: " << partidoGanador << " con " << maxVotos << " votos" << endl;
        }
};