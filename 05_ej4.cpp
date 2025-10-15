#include <iostream>
#include <map>

using namespace std;

class Empleados{
    private:
        map<string, map<string, int> > empleados;

    public:
        void registrarGasto(string empleado, string categoria, int monto){
            empleados[empleado][categoria] += monto;
        }

        void informePorEmpleado(string empleadoBuscado){
            cout << "Informe de gastos para el empleado: " << empleadoBuscado << endl;
            // se recorre todo el mapa que esta dentro del mapa principal
            for(auto& categoria : empleados[empleadoBuscado]){
                cout << "- " << categoria.first << ": " << categoria.second << endl;
            }
        }

        void auditoriaGastos(string categoria, int limite){
            cout << "Empleados que excedieron el limite en la categoria " << categoria << ":" << endl;

            // se recorre el mapa principal para ver a todos los empleados
            for(auto& empleado : empleados){
                string nombreEmpleado = empleado.first;

                // ya que conocemos la categoria, no hace falta recorrer todo el mapa interno
                int gastoCategoria = empleado.second[categoria];
                if(gastoCategoria > limite){
                    cout << "- " << nombreEmpleado << " con un gasto de " << gastoCategoria << endl;
                }
            }
        }

        void categoriaConMayorGasto(){
            map<string, int> totalPorCategoria;

            // primero se hace un mapa que guarda el total gastado por cada categoria
            for(auto& empleado : empleados){
                for(auto& categoria : empleado.second){
                    totalPorCategoria[categoria.first] += categoria.second;
                }
            }

            // luego, se recorre el mapa creado anteriormente para ver cual tiene el mayor gasto y se guarda el nombre
            string categoriaMayor;
            int maxGasto = 0;
            for(auto& categoria : totalPorCategoria){
                if(categoria.second > maxGasto){
                    maxGasto = categoria.second;
                    categoriaMayor = categoria.first;
                }
            }

            cout << "Categoria con mayor gasto: " << categoriaMayor << " con un total de " << maxGasto << endl;
        }
};

int main(){
    Empleados *empleados = new Empleados();

    empleados->registrarGasto("Juan", "Transporte", 100);
    empleados->registrarGasto("Juan", "Comida", 200);
    empleados->registrarGasto("Ana", "Transporte", 150);
    empleados->registrarGasto("Ana", "Comida", 250);
    empleados->registrarGasto("Ana", "Hospedaje", 300);
    empleados->registrarGasto("Luis", "Comida", 100);
    empleados->registrarGasto("Luis", "Hospedaje", 200);

    empleados->informePorEmpleado("Ana");

    empleados->auditoriaGastos("Comida", 200);

    empleados->categoriaConMayorGasto();

    return 0;
}