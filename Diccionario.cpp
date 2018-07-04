//
// Created by felipe on 10/06/18.
//

#include "Diccionario.h"
#include <iostream>
 using namespace std;

void Diccionario::crear() {
    cantElementos = 0;
    primero = NULL;
}

void Diccionario::destruir() {
    Caja *anterior;
    Caja *temp = primero;
    while(temp != NULL){
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
}

void Diccionario::vaciar() {
    Caja *anterior;
    Caja *temp = primero->sgt;
    while(temp != NULL){
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
    primero = NULL;
    cantElementos = 0;
}

bool Diccionario::vacio() {
    if((cantElementos==0)||(primero==NULL)){
        return true;
    }else{
        return false;
    }
}

void Diccionario::agregar(elemento elem) {
    Caja *nuevo = new Caja(elem);
    if(cantElementos==0){
        primero = nuevo;
    }else{
        Caja* aux = primero;
        bool existe = false;
        while(aux != NULL && !existe){
            if(aux->elem == elem){
                existe = true;
            } else{
                aux = aux->sgt;
            }
        }
        if(!existe){
         nuevo->sgt = primero;
         primero = nuevo;
        }
    }
    cantElementos++;
}

void Diccionario::borrar(elemento elem) {
    Caja *aux = primero;
    Caja *anterior = NULL;
    bool existe = false;
    while(aux != NULL && !existe){
        if(aux->elem == elem){
            existe = true;
        } else {
            anterior = aux;
            aux = aux->sgt;
        }
    }
    if(existe) {
        if (anterior == NULL) {
            primero = primero->sgt;
            delete aux;
            cantElementos--;
        } else {
            anterior->sgt = aux->sgt;
            delete aux;
            cantElementos--;
        }
    }

    /*bool continuar = true;
    if(primero->elem == elem){
        primero = primero->sgt;
        delete aux;
        cantElementos--;
    }
    while(aux!=NULL && continuar){
        anterior = aux;
        aux = aux->sgt;
        if(aux->elem==elem){
            anterior->sgt = aux->sgt;
            delete aux;
            cantElementos--;
            continuar = false;
        }
    }*/
}

bool Diccionario::pertenece(elemento elem) {
    Caja *aux = primero;
    while(aux != NULL){
        if(aux->elem==elem){
            return true;
        }
        aux = aux->sgt;
    }
    return false;
}

int Diccionario::numElem() {
 return cantElementos;
}

