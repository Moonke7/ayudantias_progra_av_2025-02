#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class Editor
{
private:
    stack<string> palabras;

public:
    Editor() {};

    void escribir(queue<string> palabrasCola)
    {
        while (!palabrasCola.empty())
        {
            palabras.push(palabrasCola.front());
            palabrasCola.pop();
        }
    }

    void deshacer()
    {
        if (palabras.size() > 0)
        {
            palabras.pop();
        }
    }

    void mostrarTexto()
    {
        stack<string> aux1 = palabras;
        stack<string> aux2;

        while (!aux1.empty())
        {
            aux2.push(aux1.top());
            aux1.pop();
        }

        while (!aux2.empty())
        {
            cout << aux2.top() << " ";
            aux2.pop();
        }
    }
};

int main()
{

    Editor *e = new Editor();

    queue<string> cola;
    cola.push("Hola");
    cola.push("Mundo");
    cola.push("!");

    e->escribir(cola);

    e->mostrarTexto();

    e->deshacer();

    e->mostrarTexto();
}
