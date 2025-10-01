#include <iostream>
using namespace std;

#include <map>

#include <vector>

#include <queue>

#include <stack>

int main()
{
    stack<int> stack1;

    stack1.push(1);
    stack1.push(7);

    // ejemplo para recorrer
    while (!stack1.empty())
    {
        cout << stack1.top() << endl;
        stack1.pop();
    }

    /* queue<int> cola1;

    cola1.push(5);
    cola1.push(7);

    // ejemplo de recorrer
    while(!cola1.empty()){
        cout << cola1.front() << endl;
        cola1.pop();
    } */

    /* vector<int> vector1;

    vector1.push_back(1);
    vector1.push_back(7);

    // ejemplo para recorrer
    for (int i = 0; i < vector1.size(); i++){
        cout << vector1.at(i) << endl;
        cout << vector1[i] << endl;
    } */

    // map<tipo_llave, tipo_valor> nombre_mapa

    // ejemplo
    /* map<string, int> edades;

    edades.insert({"Jose", 19});

    edades["Juan"] = 20;
    edades["Marcos"] = 20;


    // esta sintaxis es SIEMPRE la misma para el find
    map<string, int>:: iterator it = edades.find("Marcos");
    // esto nos retorna un iterador que se guarda en la
    // variable de nombre it. Para usarlo, lo haremos:

    if (it != edades.end()){
        cout << "la llave es "<< it->first;
        cout << " y su valor es " << it->second << endl;
    }

    // ejemplo parar recorrer
    for (it = edades.begin(); it != edades.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    } */
}