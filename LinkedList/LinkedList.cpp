#include <iostream>
using namespace std;

//Aqui creo la plantilla para que nodo pueda funcionar con cualquier tipo de dato
template <typename T>
class nodo
{
public:
    T dato; //Guardamos el dato del nodo
    nodo* siguiente; //Aqui con un puntero apuntamos al siguiente nodo de la lista

    nodo(T valor)
    {
        dato = valor;
        siguiente = nullptr;
    }
};

template <typename T>
class Lista
{
public:
    nodo<T>* primero; // este puntero apunta al primer nodo de la  lista

    Lista()
    {
        primero = nullptr;
    }

    //Esta funcion se ejecuta al final y libera todos los nodos para evitar fugas de memoria
    ~Lista()
    {
        nodo<T>* actual = primero; //Aqui empezamos desde le primer nodo
        while (actual != nullptr) //y aqui empezamos a recorrer todos los nodos
        {
            nodo<T>* temp = actual; //aqui guardamos el nodo actual
            actual = actual->siguiente; // aqui avanzamos al siguiente nodo 
            delete temp; // y aqui liberamos el nodo
        }
    }
    //esta es la funcion para insertar un nuevo nodo al inicio de la lista
    void push_front(T valor)
    {
        nodo<T>* nuevo = new nodo<T>(valor); //se crea un nodo con el valor recibido
        nuevo->siguiente = primero; // el nodo que creamos apunta al primer nodo actual
        primero = nuevo;
    }

    //funcion para eliminar el primer nodo de la lista
    void pop_front()
    {
        if (primero == nullptr) 
            return;

        nodo<T>* temp = primero; // aqui guardamos el priemer nodo 
        primero = primero->siguiente; // avanzamos al siguiente nodo
        delete temp; // y aqui eliminamos el nodo anterior
    }

    void Print()
    {
        nodo<T>* actual = primero;
        while (actual != nullptr)
        {
            cout << actual->dato << " , ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
};

int main()
{
    Lista<int> lista1; 

    lista1.push_front(1);
    lista1.push_front(2);
    lista1.push_front(3);

    lista1.Print();
    lista1.pop_front();
    lista1.Print();

    return 0;
}
