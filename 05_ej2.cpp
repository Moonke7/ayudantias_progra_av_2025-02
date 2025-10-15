#include <iostream>
#include <map>

using namespace std;

class Jugadores{
    private:
        map<string, map<string, int> > jugadores;

    public:
        void registrarPuntuacion(string jugador, string juego, int puntuacion){
            int puntuacion_actual = jugadores[jugador][juego];
            if(puntuacion > puntuacion_actual){
                cout << "Nueva puntuacion mas alta. Actualizando..." << endl;
                jugadores[jugador][juego] = puntuacion;
            }
        }

        int puntuacionTotalJugador(string jugadorBuscado){
            int total = 0;
            for(auto& juego : jugadores[jugadorBuscado]){
                total += juego.second;
            }

            return total;
        
            // otra forma de hacerlo
            // for(auto& jugador: jugadores){
            //     string nombre = jugador.first;
            //     if(nombre == jugadorBuscado){
            //         for(auto& juego: jugador.second){
            //             int puntuacion = juego.second;
            //             total += puntuacion;
            //         }
            //         return total;
            //     }
            // }
        }

        string juegoMasPopular(){
            map<string, int> conteoJuegos;

            // primero se hace un mapa que guarda cuantas veces aparece cada juego
            for(auto& jugador : jugadores){
                for(auto& juego : jugador.second){
                    conteoJuegos[juego.first]++;
                }
            }

            // luego, se recorre el mapa creado anteriormente para ver cual tiene el mayor conteo y se guarda el nombre
            string juegoPopular;
            int maxConteo = 0;
            for(auto& juego : conteoJuegos){
                if(juego.second > maxConteo){
                    maxConteo = juego.second;
                    juegoPopular = juego.first;
                }
            }

            // finalmente, se retorna el nombre del juego mas popular
            return juegoPopular;
        }
};

int main(){
    Jugadores *jugadores = new Jugadores();
    jugadores->registrarPuntuacion("Alice", "JuegoA", 150);
    jugadores->registrarPuntuacion("Bob", "JuegoB", 200);
    jugadores->registrarPuntuacion("Alice", "JuegoB", 250);
    jugadores->registrarPuntuacion("Charlie", "JuegoA", 300);
    jugadores->registrarPuntuacion("Bob", "JuegoA", 180);
    jugadores->registrarPuntuacion("Alice", "JuegoA", 100); // no actualiza porque es menor


    cout << "Puntuacion total de Alice: " << jugadores->puntuacionTotalJugador("Alice") << endl;
    cout << "Juego mas popular: " << jugadores->juegoMasPopular() << endl;
}