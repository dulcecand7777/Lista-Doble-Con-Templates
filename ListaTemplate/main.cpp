#include <iostream>
#include <cstdlib>
#include <ctime>
#include "lista.cpp"
#include "nodo.cpp"

using namespace std;

int main(){
    Lista<int> lista; 
    Lista<int> listaDos;

    for(int i = 1; i <= 1000 ; i++){
        lista.insertarFinal(i);
    }
    cout<<"Lista 1" <<endl;
    lista.imprimirLista();

    // for(int i = 50; i < 100; i++){
    //     listaDos.insertarFinal(i);
    // }
    // cout<<"\n";
    // cout<<"Lista 2" <<endl;
    // listaDos.imprimirLista();

    // cout<<"Lista 1" <<endl;
    // lista.imprimirLista();

    // cout<<"\n";
    // cout<<"Lista 2" <<endl;
    // listaDos.imprimirLista();

    cout << "\nLista ordenada" <<endl;

    lista.quicksort();
    lista.imprimirLista();

    // srand(time(nullptr));

    // cout << "\nInserta al inicio" << endl;
    // for(int i = 0; i < 2500; i++) {
    //     int dato = 0;
    //     do {
    //         dato = rand() % 5000;
    //     } while (lista.existe(dato)); 
    //     lista.insertarInicio(dato);
    // }
    // cout << "Lista:" << endl;
    // lista.imprimirLista();

    // cout << endl;
    // system("pause");

    // cout << "\nInserta al final" << endl;
    // for(int i = 0; i < 2500; i++) {
    //     int dato = 0;
    //     do {
    //         dato = rand() % 5000;
    //     } while (lista.existe(dato)); // Verificar si el dato ya existe en la lista
    //     lista.insertarFinal(dato);
    // }

    // cout << "Lista:" << endl;
    // lista.imprimirLista();

    // cout << endl;
    // system("pause");
    
    // for (int i = 0; i < 5000; ++i) {
    //     int datoAEliminar = rand() % 5000;
    //     lista.eliminar(datoAEliminar);
    // } 

    // cout << "\nInseta al inicio" << endl;
    // for(int i = 0; i < 25000; i++){
    //     int dato = 0;
    //     lista.insertarInicio(dato = rand() % 500000);
    // }
    // cout << "Lista:" << endl;
    // lista.imprimirLista();

    // cout << endl;
    // system("pause");

    // cout<< "\nInserta al final" << endl;
    // for(int i = 0; i < 25000; i++){
    //     int dato = 0;
    //     lista.insertarFinal(dato = rand() % 500000);
    // }
    // cout << "Lista:" << endl;
    // lista.imprimirLista();

    // cout << endl;
    // system("pause");
    
    // for (int i = 0; i < 5000; ++i) {
    //     int datoAEliminar = rand() % 500000; // Genera un número aleatorio del 0 al 99
    //     lista.eliminar(datoAEliminar); // Elimina el nodo que contiene el número aleatorio
    // }
    // cout << "Lista:" << endl;
    // lista.imprimirLista();

    // cout << endl;
    // system("pause");

    // cout << "\nOrdenar lista de manera descendente usando mergeSort" << endl;
    // lista.mergeSort();
    // lista.imprimirLista();

    // cout << endl;
    // system("pause");

    // lista.~Lista();
    // lista.imprimirLista();
    // cout << "Lista ordenada" << endl;
    // lista.quicksort();
    // lista.imprimirLista();

    
    // cout << "Previo" << endl;
    // cout << lista.getPrev(lista.getUlt())->getDato() << endl;;

    // cout << "Primero" << endl;
    // cout << lista.getPrimero()->getDato() << endl;
    // cout << lista.getPrimero()->getSiguiente()->getDato() << endl;
    // cout << lista.getPrimero()->getSiguiente()->getSiguiente()->getDato() << endl;
    // cout << lista.getUlt()->getPrev()->getDato() << endl;
    // cout << lista.getUlt()->getPrev()->getPrev()->getDato() << endl;

    return 0;
}