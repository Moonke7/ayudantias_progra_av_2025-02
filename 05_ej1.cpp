#include <iostream>
#include <map>

using namespace std;

class Tienda{
    private:
        map<string, map<string, int>> inventario;
    public:
        void agregarProducto(string categoria, string producto, int cantidad){
            inventario[categoria][producto] += cantidad;
        }

        void imprimirInventario(){
            for(auto& categoria : inventario){
                cout << "Categoria: " << categoria.first << endl;
                for(auto& producto : categoria.second){
                    cout << "- " << producto.first << ": " << producto.second << endl;
                }
            }
        }
};

int main(){
    Tienda *tienda = new Tienda();

    tienda->agregarProducto("Frutas", "Manzana", 50);
    tienda->agregarProducto("Frutas", "Platano", 40);
    tienda->agregarProducto("Lacteos", "Leche", 30);
    tienda->agregarProducto("Lacteos", "Queso", 20);
    tienda->agregarProducto("Verduras", "Zanahoria", 25);
    
    tienda->imprimirInventario();

    return 0;
}