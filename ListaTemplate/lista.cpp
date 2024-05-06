#include "lista.hpp"
#include <stack>

using namespace std;

template <class T>
Lista<T>::Lista(){
    header = nullptr;
}

template <class T>
Lista<T>::~Lista(){
    if(!estaVacia()){
        Nodo<T> *actual = header;
        Nodo<T> *temp;
        while(actual != nullptr){
            temp = actual;
            actual = actual->getSiguiente();
            delete temp;
        }
        header = nullptr;
    }
}

template <class T>
bool Lista<T>:: existe(T dato){
    Nodo<T>* actual = header;
        while (actual) {
            if (actual->getDato() == dato) {
                return true;
            }
            actual = actual->getSiguiente();
        }
        return false;
}

    

template <class T>
Nodo<T>* Lista<T>:: getHeader() const{
    return header;
}

template <class T>
bool Lista<T>::estaVacia() const{
    return header == nullptr;
}

template <class T>
Nodo<T>* Lista<T>:: getPrimero() const{
    return header;
}

template <class T>
Nodo<T>* Lista<T>:: getUlt() const{
    Nodo<T> *actual = header;

    if(estaVacia()){
        return nullptr;
    }
    while(actual->getSiguiente() != nullptr){
        actual = actual->getSiguiente();
    } 

    return actual;
}

template <class T>
Nodo<T>* Lista<T>::getPrev(Nodo<T>* nodo) const {
    if(nodo == nullptr){
        return nullptr;
    }
    return nodo->getPrev();
}

template <class T>
Nodo<T>* Lista<T>::getSiguiente(Nodo<T>* nodo) const{
    if(nodo == nullptr){
        return nullptr;
    }
    return nodo->getSiguiente();
}

template <class T>
void Lista<T>::insertarInicio(T dato){
    Nodo<T> *nodo = new Nodo<T>();
    nodo->setDato(dato);
    nodo->setPrev(nullptr);

    if(estaVacia()){
        header = nodo;
    }else{
        nodo->setSiguiente(header);
        nodo->setPrev(nodo);
        header = nodo;
    }
}

template <class T>
void Lista<T>::insertarFinal(T dato){
    Nodo<T>* nodo = new Nodo<T>();
    nodo->setDato(dato);

    if(estaVacia()){
        header = nodo;
    }else{
        Nodo<T>* ultimo = getUlt();
        nodo->setPrev(ultimo);
        ultimo->setSiguiente(nodo);
    }
}

template <class T>
void Lista<T>::imprimirLista(){
    Nodo<T> *actual = header;

    if(estaVacia()){
        return;
    }

    while(actual!= nullptr ){
        cout<< actual->getDato()<< "-> ";
        actual = actual->getSiguiente();
    }
}

template <class T>
void Lista<T>::eliminar(const T& dato){
    if(estaVacia()){
        return;
    }
    Nodo<T>* actual = header;
    Nodo<T>* anterior = nullptr;

    while (actual != nullptr && actual->getDato() != dato) {
        anterior = actual;
        actual = actual->getSiguiente();
    }
  
    if (actual != nullptr) {
        
        if (actual == header) {
            header = actual->getSiguiente();
        } else {
            anterior->setSiguiente(actual->getSiguiente());
            if (actual->getSiguiente() != nullptr) {
                actual->getSiguiente()->setPrev(anterior);
            }
        }
        delete actual; 
    } else {
        std::cout << "Nodo no encontrado: " << dato << std::endl;
    }
}

//ordenamiento mergesort
template <class T>
void Lista<T>::mergeSort() {
    header = mergeSortRecursivo(header);
}

template <class T>
Nodo<T>* Lista<T>::mergeSortRecursivo(Nodo<T>* inicio) {
    // Casos base: si la lista está vacía o tiene un solo elemento
    if (inicio == nullptr || inicio->getSiguiente() == nullptr) {
        return inicio;
    }

    // Divide la lista en dos sublistas
    Nodo<T>* mitad = dividirLista(inicio);

    // Ordena recursivamente ambas sublistas
    inicio = mergeSortRecursivo(inicio);
    mitad = mergeSortRecursivo(mitad);

    // Fusiona las sublistas ordenadas
    return fusionarListas(inicio, mitad);
}

template <class T>
Nodo<T>* Lista<T>::dividirLista(Nodo<T>* inicio) {
    Nodo<T>* lento = inicio;
    Nodo<T>* rapido = inicio->getSiguiente();

    // Avanza el puntero rápido dos veces más rápido que el puntero lento
    while (rapido != nullptr && rapido->getSiguiente() != nullptr) {
        lento = lento->getSiguiente();
        rapido = rapido->getSiguiente()->getSiguiente();
    }

    // 'lento' es ahora el nodo del medio
    Nodo<T>* mitad = lento->getSiguiente();
    lento->setSiguiente(nullptr); // Divide la lista en dos sublistas

    return mitad;
}

template <class T>
Nodo<T>* Lista<T>::fusionarListas(Nodo<T>* lista1, Nodo<T>* lista2) {
    Nodo<T>* dummy = new Nodo<T>(); // Nodo falso para facilitar la fusión
    Nodo<T>* actual = dummy;

    // Fusiona las sublistas comparando los valores de los nodos
    while (lista1 != nullptr && lista2 != nullptr) {
        if (lista1->getDato() > lista2->getDato()) {
            actual->setSiguiente(lista1);
            lista1 = lista1->getSiguiente();
        } else {
            actual->setSiguiente(lista2);
            lista2 = lista2->getSiguiente();
        }
        actual = actual->getSiguiente();
    }

    // Une la lista restante
    if (lista1 != nullptr) {
        actual->setSiguiente(lista1);
    } else {
        actual->setSiguiente(lista2);
    }

    Nodo<T>* resultado = dummy->getSiguiente();
    delete dummy; // Libera el nodo falso

    return resultado;
}

//ordenamiento quicksort
template <class T>
void Lista<T>::swap(Nodo<T> *a, Nodo<T> *b) {
    T temp = a->getDato();
    a->setDato(b->getDato());
    b->setDato(temp);
}

template <class T>
Nodo<T>* Lista<T>::partition(Nodo<T> *low, Nodo<T> *high) {
    T pivot = high->getDato();
    Nodo<T> *i = low->getPrev();

    for (Nodo<T> *j = low; j != high; j = j->getSiguiente()) {
        if (j->getDato() >= pivot) {
            i = (i == nullptr) ? low : i->getSiguiente();
            swap(i, j);
        }
    }

    i = (i == nullptr) ? low : i->getSiguiente();
    swap(i, high);

    return i;
}

template <class T>
void Lista<T>::quickSort(Nodo<T> *low, Nodo<T> *high) {
    if (high != nullptr && low != high && low != high->getSiguiente()) {
        Nodo<T> *pivot = partition(low, high);
        quickSort(low, pivot->getPrev());
        quickSort(pivot->getSiguiente(), high);
    }
}

template <class T>
void Lista<T>::quicksort(){
    quickSort(header, getUlt());
}