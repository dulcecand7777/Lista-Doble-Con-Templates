#pragma once
#include "nodo.hpp"
#include <string>
#include <iostream>

template <class T>
class Lista{
private:
    Nodo<T> *header;
    bool estaVacia() const;
public:
    Lista();
    ~Lista();
    bool existe(T dato);
    Nodo<T>* getHeader() const;
    Nodo<T>* getPrimero() const;
    Nodo<T>* getUlt() const;
    Nodo<T>* getPrev(Nodo<T>* nodo) const;
    Nodo<T>* getSiguiente(Nodo<T>* nodo) const;
    void insertarInicio(T dato);
    void insertarFinal(T dato);
    void imprimirLista();
    void eliminar(const T& dato);
    //ordenamiento mergesort
    void mergeSort();
    Nodo<T>* mergeSortRecursivo(Nodo<T>* inicio);
    Nodo<T>* dividirLista(Nodo<T>* inicio);
    Nodo<T>* fusionarListas(Nodo<T>* lista1, Nodo<T>* lista2);
    //ordenamiento quicksort
    void swap(Nodo<T> *a, Nodo<T> *b);
    Nodo<T>* partition(Nodo<T> *low, Nodo<T> *high);
    void quickSort(Nodo<T> *low, Nodo<T> *high);
    void quicksort();
};