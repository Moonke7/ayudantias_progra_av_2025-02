#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main(){
    map<string, int> mapa;

    mapa["hola1"] = 1;
    mapa["hola2"] = 2;
    mapa["hola3"] = 3;

    string llaveBuscada = "hola1";

    if (mapa.find(llaveBuscada) == mapa.end()){
        cout << "llave no existe" << endl;
    } else{
        cout << mapa.find(llaveBuscada)->first;
        cout << mapa.find(llaveBuscada)->second + 5;
        cout << "la llave existe" << endl;
    }

}