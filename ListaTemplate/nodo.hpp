#pragma once

template <class T>
class Nodo{
private:
    T dato;
    Nodo<T> *prev;
    Nodo<T> *sig;

public:
    Nodo();
    // Getters
    T getDato() const;
    Nodo<T>* getPrev() const;
    Nodo<T>* getSiguiente() const;

    // Setters
    void setDato(const T& dato);
    void setPrev(Nodo<T>* prev);
    void setSiguiente(Nodo<T>* sig);
};