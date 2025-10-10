#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Alumno{
    private:
        string nombre, rut;
        flota promedio;

    public:
        Alumno(string _nombre, string _rut, float _promedio){
            nombre = _nombre;
            rut = _rut;
            promedio = _promedio;
        }

        void mostrarInfo(){
            cout << "Nombre: " << nombre << endl;
            cout << "Rut: " << rut << endl;
            cout << "Promedio: " << promedio << endl;
        }

        string getNombre(){
            return nombre;
        }
        string getRut(){
            return rut;
        }
        float getPromedio(){
            return promedio;
        }
};

class Curso{
    private:
        string codigo_curso;
        map<int, vector<Alumno*> > secciones; 
    public:
        Curso(string _codigo_curso){
            codigo_curso = _codigo_curso;
        }

        void agregarAlumno(int seccion, Alumno* alumno){
            vector<Alumno*> vector_alumnos = secciones[seccion];

            // primero, verificar tamaño maximo de la secc
            if (vector_alumnos.size() >= 30){
                cout << "No se puede agregar alumno, seccion llena" << endl;
                return;
            } else {
                // agregamos el alumno al vector auxiliar
                vector_alumnos.push_back(alumno);
                // luego, actualizamos el vector del mapa diciendo que es igual al vector auxiliar creado (No descontaré por esto)
                secciones[seccion] = vector_alumnos;
                cout << "Alumno agregado exitosamente" << endl;
            }
        }

        float notaMasAlta(int seccion){
            vector<Alumno*> vector_alumnos = secciones[seccion];
            float nota_alta = 0;

            if (!vector_alumnos.size()){
                cout << "Esta seccion no existe o no tiene alumnos" << endl;
                return -1;
            }

            // en caso de que exista la seccion, recorremos el vector de alumnos y buscamos la nota mas alta
            for (int i = 0; i < vector_alumnos.size(); i++){
                if (vector_alumnos[i]->getPromedio() > nota_alta){
                    nota_alta = vector_alumnos[i]->getPromedio();
                }
            }
            return nota_alta;
        }

        float obtenerPromedio(int seccion){
            vector<Alumno*> vector_alumnos = secciones[seccion];
            float suma_notas = 0;

            if (!vector_alumnos.size()){
                cout << "Esta seccion no existe o no tiene alumnos" << endl;
                return -1;
            }

            for (int i = 0; i < vector_alumnos.size(); i++){
                suma_notas += vector_alumnos[i]->getPromedio();
            }
            return suma_notas / vector_alumnos.size();
        }

        void imprimirSeccion(int seccion){
            map<int, vector<Alumno*> >::iterator it = secciones.find(seccion);
            
            if (it != secciones.end()){
                vector<Alumno*> vector_alumnos = it->second;
            
                for (int i = 0; i < vector_alumnos.size(); i++){
                    vector_alumnos[i]->mostrarInfo();
                }
            } else {
                cout << "Esta seccion no existe" << endl;
            }

            // una forma alternativa de hacerlo era asi:
            // recorrer todo el mapa y buscar la seccion
            // for (it = secciones.begin(); it != secciones.end(); it++){
            //     if (it->first == seccion){
            //         vector<Alumno*> vector_alumnos = it->second;
            
            //         for (int i = 0; i < vector_alumnos.size(); i++){
            //             vector_alumnos[i]->mostrarInfo();
            //         }
            //     }
            // }
        }

        float obtenerPromedioSecciones(){
            int total_alumnos = 0;
            float suma_notas = 0;

            map<int, vector<Alumno*> >::iterator it;
            for (it = secciones.begin(); it != secciones.end(); it++){
                // para cada seccion, obtenemos su vector de alumnos que recorreremos
                vector<Alumno*> vector_alumnos = it->second;
                total_alumnos += vector_alumnos.size();

                for (int i = 0; i < vector_alumnos.size(); i++){
                    suma_notas += vector_alumnos[i]->getPromedio();
                }
            }

            return suma_notas / total_alumnos;
        }

        float obtenerNotaMasAltaSecciones(){
            float nota_alta = 0;

            map<int, vector<Alumno*> >::iterator it;
            for (it = secciones.begin(); it != secciones.end(); it++){
                // lo mismo que antes, para cada seccion, obtenemos su vector de alumnos que recorreremos
                vector<Alumno*> vector_alumnos = it->second;

                for (int i = 0; i < vector_alumnos.size(); i++){
                    if (vector_alumnos[i]->getPromedio() > nota_alta){
                        nota_alta = vector_alumnos[i]->getPromedio();
                    }
                }
            }

            return nota_alta;
        }
}

int main(){
    Alumno* alumno1 = new Alumno("Juan", "123-4", 5.5);
    Alumno* alumno2 = new Alumno("Maria", "1231-8", 6.0);
    Alumno* alumno3 = new Alumno("Pedro", "756-1", 4.5);    
    Alumno* alumno4 = new Alumno("Ana", "11223-2", 7.0);
    Alumno* alumno5 = new Alumno("Luis", "13165-4", 4.0);

    Curso* curso = new Curso("CIT1010");
    curso->agregarAlumno(1, alumno1);
    curso->agregarAlumno(1, alumno2);
    curso->agregarAlumno(2, alumno3);
    curso->agregarAlumno(2, alumno4);
    curso->agregarAlumno(2, alumno5);

    cout << "Nota mas alta seccion 1: " << curso->notaMasAlta(1) << endl;
    cout << "Promedio seccion 2: " << curso->obtenerPromedio(2) << endl;
    cout << "Promedio todas las secciones: " << curso->obtenerPromedioSecciones() << endl;
    cout << "Nota mas alta todas las secciones: " << curso->obtenerNotaMasAltaSecciones() << endl;
    cout << "Imprimiendo seccion 2:" << endl;
    curso->imprimirSeccion(2);
}