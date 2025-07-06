#include <iostream>
using namespace std;

class nodo
{
public:

    int dato;
    nodo* siguiente;
    nodo(int valor)
    {
        dato = valor;
        siguiente = nullptr;
    }
};

class Lista
{
public:
    nodo* primero;

    Lista()
    {
        primero = nullptr;
    }

    ~Lista()
    {
        nodo* actual = primero;
        while (actual != nullptr)
        {
            nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }

    void Print();
};

void push_front(Lista& lista, int valor);
void pop_front(Lista& lista);

int main()
{
    Lista lista1;

    push_front(lista1, 1);
    push_front(lista1, 2);
    push_front(lista1, 3);

    lista1.Print();
    pop_front(lista1);
    lista1.Print();

    return 0;
}

void Lista::Print()
{
    nodo* actual = primero;
    while (actual != nullptr)
    {
        cout << actual->dato << " , ";
        actual = actual->siguiente;
    }
}

void push_front(Lista& lista, int valor)
{
    nodo* nuevo = new nodo(valor);
    nuevo->siguiente = lista.primero;
    lista.primero = nuevo;
}

void pop_front(Lista& lista)
{
    if (lista.primero == nullptr)
    {
        return;
    }

    nodo* temp = lista.primero;
    lista.primero = lista.primero->siguiente;
    delete temp;
}

