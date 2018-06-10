//
// Created by jimmy on 10/06/18.
//

#ifndef TP2_I_2018_RELACION1A1_H
#define TP2_I_2018_RELACION1A1_H
#include <iostream>
#include <memory>

using namespace std;

template < typename T, typename S >

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

    //EFE:
    //REQ:
    //MOD:
    void agregarRelacion(T e1, S e2);

    //EFE:
    //REQ:
    //MOD:
    void eliminarRelacion(T e1, S e2);

    //EFE:
    //REQ:
    //MOD:
    void modificarImagen(T e1, S nE);

    //EFE:
    //REQ:
    //MOD:
    bool existeRelacion(T e1, S e2);

    //EFE:
    //REQ:
    //MOD:
    S imagen(T e);

    //EFE:
    //REQ:
    //MOD:
    T preImagen(S e);

    //EFE:
    //REQ:
    //MOD:
    bool estaEnDominio(T e);

    //EFE:
    //REQ:
    //MOD:
    bool estaEnCodominio(S e);

    //EFE:
    //REQ:
    //MOD:
    int numRelaciones();

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
    Elem<T,S> *primero;
    int nElementos;
};

template <typename T, typename S>
void Relacion1a1<T,S>::crear() {
    primero = NULL;
    nElementos = 0;
}

template <typename T, typename S>
void Relacion1a1<T,S>::destruir() {
    Elem<T,S> *anterior = NULL;
    Elem<T,S> *temp = primero;
    while(temp != NULL){
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
    nElementos = -99;
}

template <typename T, typename S>
void Relacion1a1<T,S>::vaciar() {
    Elem<T,S> *anterior;
    Elem<T,S> *temp = primero;
    while(temp != NULL){
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
    primero = NULL;
    nElementos = 0;
}

template <typename T, typename S>
bool Relacion1a1<T,S>::vacia() {
    if(nElementos == 0){
        return true;
    }else{
        return false;
    }
}

template <typename T, typename S>
void Relacion1a1<T,S>::agregarRelacion(T e1, S e2){
    Elem<T,S> *nuevo = new Elem<T,S>(e1,e2);
    if(nElementos == 0){
        primero = nuevo;
    } else{
        nuevo->sgt = primero;
        primero = nuevo;
    }
    nElementos++;
}

template <typename T, typename S>
void Relacion1a1::eliminarRelacion(T e1, S e2) {
    Elem<T,S> *temp = primero;
    Elem<T,S> *anterior = NULL;
    while(temp != NULL && temp->elemento1 != e1){
        anterior = temp;
        temp = temp->sgt;
    }
    if(anterior == 0){ // es el primer elemento de la lista
        primero = primero->sgt;
        delete temp;
        nElementos--;
    } else{
        anterior->sgt = temp->sgt;
        delete temp;
        nElementos--;
    }
}

template <typename T, typename S>
void Relacion1a1::modificarImagen(T e1, S nE) {
    Elem<T,S> *temp = primero;
    while(temp != NULL && temp->elemento1 != e1){
        temp = temp->sgt;
    }
    if(temp != NULL){
        temp->elemento2 = nE;
    }
}

template <typename T, typename S>
bool Relacion1a1::existeRelacion(T e1, S e2) {}

template <typename T, typename S>
S Relacion1a1::imagen(T e) {}

template <typename T, typename S>
T Relacion1a1::preImagen(S e) {}

template <typename T, typename S>
bool Relacion1a1::estaEnDominio(T e) {}

template <typename T, typename S>
bool Relacion1a1::estaEnCodominio(S e) {}

template <typename T, typename S>
int Relacion1a1::numRelaciones() {
    nElementos++;
}





#endif //TP2_I_2018_RELACION1A1_H
