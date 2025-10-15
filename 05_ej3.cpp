#include <iostream>
#include <map>

using namespace std;

class PreferenciaMusical{
    private:
        map<string, map<string, int> > encuesta;
    
    public:
        void agregarVoto(string ciudad, string genero){
            encuesta[ciudad][genero]++;
        }

        string generoPredominante(string ciudadBuscada){
            string generoPredominante;
            int maxVotos = 0;

            for (auto& genero: encuesta[ciudadBuscada]){
                if(genero.second > maxVotos){
                    maxVotos = genero.second;
                    generoPredominante = genero.first;
                }
            }

            if (maxVotos == 0){
                return "No hay votos en esa ciudad";
            }
            return generoPredominante;
        }

        string ciudadMasVariada(){
            string ciudadVariada;
            int maxGeneros = 0;

            for(auto& ciudad: encuesta){
                int cantidadGeneros = ciudad.second.size();
                if(cantidadGeneros > maxGeneros){
                    maxGeneros = cantidadGeneros;
                    ciudadVariada = ciudad.first;
                }
            }

            return ciudadVariada;
        }
};

int main(){
    PreferenciaMusical *preferencia = new PreferenciaMusical();

    preferencia->agregarVoto("Rancagua", "Rock");
    preferencia->agregarVoto("Rancagua", "Pop");
    preferencia->agregarVoto("Rancagua", "Rock");
    preferencia->agregarVoto("Rancagua", "Jazz");
    preferencia->agregarVoto("Santiago", "Rock");
    preferencia->agregarVoto("Santiago", "Pop");
    preferencia->agregarVoto("Talca", "kpop");
    preferencia->agregarVoto("Talca", "metal");

    cout << "Genero predominante en Rancagua: " << preferencia->generoPredominante("Rancagua") << endl;

    cout << "Ciudad con mayor variedad de generos: " << preferencia->ciudadMasVariada() << endl;

    return 0;
}