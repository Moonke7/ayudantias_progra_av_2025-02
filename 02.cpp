// 03 de la solemne
#include <iostream>
#include <vector>

using namespace std;

class Deportista
{
protected:
    string nombre;
    string pais;
    string especialidad;

public:
    Deportista(string _nombre, string _pais, string _especialidad){
        nombre = _nombre;
        pais = _pais;
        especialidad = _especialidad;
    }

    virtual void imprimir()
    {
        cout << " Nombre : " << nombre << ", Pais : " << pais << ", Especialidad : " << especialidad << endl;
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
            cout << " Nombre : " << nombre << ", Pais : " << pais << ", Especialidad : " << especialidad << endl;
            cout << "Discapacidad: " << discapacidad << endl;
        }
};

class Stgo2023{
    private: 
        vector<Deportista*> deportistas;

    public:
        Stgo2023(){};

        void agregarDeportista(Deportista* d){
            deportistas.push_back(d);
        }

        void listarParticipantes(){
            for (int i = 0; i < deportistas.size(); i++){
                deportistas[i]->imprimir();
            }
        }
};

int main()
{
    Stgo2023 *juegos = new Stgo2023();
    
    Deportista *d1 = new Deportista("Juan Perez", "Chile", "Natacion");
    Deportista *d2 = new Deportista("Ana Gomez", "Argentina", "Atletismo"); 
    ParaDeportista *pd1 = new ParaDeportista("Carlos Ruiz", "Peru", "Ciclismo", "Discapacidad Visual");
    ParaDeportista *pd2 = new ParaDeportista("Luisa Fernandez", "Colombia", "Tenis en Silla de Ruedas", "Discapacidad Motriz");

    juegos->agregarDeportista(d1);
    juegos->agregarDeportista(d2);
    juegos->agregarDeportista(pd1);
    juegos->agregarDeportista(pd2);

    juegos->listarParticipantes();

    return 0;
}
