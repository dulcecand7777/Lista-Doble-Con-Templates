#include "nodo.hpp"

template <class T>
Nodo<T>::Nodo() {
    prev = nullptr;
    sig = nullptr;
}

template <class T>
T Nodo<T>:: getDato() const{
    return dato;
}

template <class T>
Nodo<T>* Nodo<T>:: getPrev() const{
    return prev;
}

template <class T>
Nodo<T>* Nodo<T>:: getSiguiente() const{
    return sig;
}

template <class T>
void Nodo<T>:: setDato(const T& dato){
    this->dato = dato;
}

template <class T>
void Nodo<T>:: setPrev(Nodo<T>* prev){
    this->prev = prev;
}

template <class T>
void Nodo<T>:: setSiguiente(Nodo<T>* sig){
    this->sig = sig;
}