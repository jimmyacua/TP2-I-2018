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

    void listar();

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
            sgt = 0;
        }
    };
    Elem<T,S> *primero;
    int nElementos;
};

template <typename T, typename S>
void Relacion1a1<T,S>::crear() {
    primero = 0;
    nElementos = 0;
}

template <typename T, typename S>
void Relacion1a1<T,S>::destruir() {
    Elem<T,S> *anterior = 0;
    Elem<T,S> *temp = primero;
    while(temp != 0){
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
    while(temp != 0){
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
    primero = 0;
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
void Relacion1a1<T,S>::eliminarRelacion(T e1, S e2) {
    Elem<T,S> *temp = primero;
    Elem<T,S> *anterior = 0;
    while(temp != 0 && temp->elemento1 != e1){
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
void Relacion1a1<T,S>::modificarImagen(T e1, S nE) {
    Elem<T,S> *temp = primero;
    while(temp != 0 && temp->elemento1 != e1){
        temp = temp->sgt;
    }
    if(temp != 0){
        temp->elemento2 = nE;
    }
}

template <typename T, typename S>
bool Relacion1a1<T,S>::existeRelacion(T e1, S e2) {
    Elem<T,S> *temp = primero;
    while(temp != 0){
        if(temp->elemento1 == e1 && temp->elemento2 == e2){
            return true;
        }
        temp = temp->sgt;
    }
    return false;
}

template <typename T, typename S>
S Relacion1a1<T,S>::imagen(T e) {
    Elem<T,S> *temp = primero;
    while(temp != 0 && temp->elemento1 != e){
        temp = temp->sgt;
    }
    if(temp->elemento1 == e){
        return temp->elemento2;
    } else{
        return 0;
    }
}

template <typename T, typename S>
T Relacion1a1<T,S>::preImagen(S e) {
    Elem<T,S> *temp = primero;
    while(temp != 0 && temp->elemento2 != e){
        temp = temp->sgt;
    }
    if(temp->elemento2 == e){
        return temp->elemento1;
    } else{
        return 0;
    }
}

template <typename T, typename S>
bool Relacion1a1<T,S>::estaEnDominio(T e) {
    Elem<T,S> *temp = primero;
    bool existe = false;
    while(temp != 0 && !existe){
        if(temp->elemento1 == e){
            existe = true;
        } else {
            temp = temp->sgt;
        }
    }
    return existe;
}

template <typename T, typename S>
bool Relacion1a1<T,S>::estaEnCodominio(S e) {
    Elem<T,S> *temp = primero;
    bool existe = false;
    while(temp != 0 && !existe){
        if(temp->elemento2 == e){
            existe = true;
        } else {
            temp = temp->sgt;
        }
    }
    return existe;
}

template <typename T, typename S>
int Relacion1a1<T,S>::numRelaciones() {
    return  nElementos;
}

template <typename T, typename S>
void Relacion1a1<T,S>::listar() {
    Elem<T,S> *aux = primero;
    while(aux != 0) {
        cout << aux->elemento1 << "-" << aux->elemento2 << endl;
        aux = aux->sgt;
    }
}




#endif //TP2_I_2018_RELACION1A1_H
