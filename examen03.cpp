#include <iostream>
#include <stack>
#include <map>
#include <queue>

using namespace std;

class Frasco{
    private:
        stack<string> caramelos;
    
    public:
        Frasco(){};
        
        map<string, int> queTieneElFrasco(){
            stack<string> aux = caramelos;
            map<string, int> mapa;

            while (!aux.empty()){
                mapa[aux.top()]++;
                aux.pop();
            }

            return mapa;
        }

        map<string, int> anadirCaramelos(queue<string> caramelosCola){
            map<string, int> mapa;

            while(!caramelosCola.empty()){
                mapa[caramelosCola.front()]++;
                caramelos.push(caramelosCola.front());

                caramelosCola.pop();
            }

            return mapa;
        }

        string sacarCaramelo(){
            string caramelo = caramelos.top();
            caramelos.pop();

            return caramelo;
        }

};

int main(){
    map<string, int> mapa;

    mapa["hola"]++;
    cout << mapa["hola"] << endl;
}


