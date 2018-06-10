//
// Created by jimmy on 10/06/18.
//

#ifndef TP2_I_2018_RELACION1A1_H
#define TP2_I_2018_RELACION1A1_H
#include <iostream>
#include <memory>

using namespace std;

template < typename T >

class Relacion1a1 {
public:

    //EFE: Crea la Relacion1a1
    //REQ: 
    //MOD:
    void crear();

    //EFE: Destruye la Relacion1a1 haciendola inutilizable
    //REQ: Relacion inicializada
    //MOD: el modelo relacion
    void destruir();

    //EFE: eliminar todos los elementos que hay en la relacion
    //REQ: relacion inicializada y no vacía
    //MOD: la relacion
    void vaciar();

    //EFE: devuelve true si la relacion está vacía, false si no
    //REQ: relacion inicializada
    //MOD:
    bool vacia();



    

private:
    template <typename V, typename W>
    struct Elem{
        V elemento1;
        W elemento2;
        Elem *sgt;

        Elem(){};
        Elem(V e1, W e2){
            elemento1 = e1;
            elemento2 = e2;
            sgt = NULL;
        }
    };
    Elem<T> *primero;
    int nElementos;
};

template <typename T>
void Relacion1a1<T>::crear() {
    primero = NULL;
}

template <typename T>
void Relacion1a1<T>::destruir() {
    Elem<T> *anterior = NULL;
    Elem<T> *temp = primero;
    while(temp != NULL){
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
}

template <typename T>
void Relacion1a1<T>::vaciar() {
    Elem<T> *anterior;
    Elem<T> *temp = primero;
    while(temp != NULL){
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
    primero = NULL;
}

template <typename T>
bool Relacion1a1<T>::vacia() {
    if(nElementos == 0){
        return true;
    }else{
        return false;
    }
}



#endif //TP2_I_2018_RELACION1A1_H
