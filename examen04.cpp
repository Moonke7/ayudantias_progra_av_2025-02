#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

class Deportista{
    protected:
        string nombre, pais, especialidad;

    public:
        Deportista(string n, string p, string e){
            nombre = n;
            pais = p;
            especialidad = e;
        }

        virtual void imprimir(){
            cout << nombre << endl;
            cout << pais << endl;
            cout << especialidad << endl;
        }
};

class ParaDeportista : public Deportista{
    private:
        string discapacidad;

    public:
        ParaDeportista(string _nombre, string _pais, string _especialidad, string _discapacidad) : Deportista(_nombre, _pais, _especialidad){
            discapacidad = _discapacidad;
        }

        void imprimir() override {
            cout << nombre << endl;
            cout << pais << endl;
            cout << especialidad << endl;
            cout << discapacidad << endl;
        }
};

class Stgo2023{
    private:
        vector<Deportista*> participantes;

    public:
        Stgo2023(){};

        void listarParticipantes(){
            for(int i = 0; i < participantes.size(); i++){
                participantes[i]->imprimir();
            }
        }

    
};

int main(){

    

}