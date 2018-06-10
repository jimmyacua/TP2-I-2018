//
// Created by felipe on 10/06/18.
//

#include "Diccionario.h"
#include <iostream>
 using namespace std;

void Diccionario::crear() {
    cantElementos = 0;
    primero = new Caja();
    ultimo = primero;
}

void Diccionario::destruir() {
    Caja *anterior;
    Caja *temp = primero;
    while(temp != NULL){
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
    cantElementos = 0;
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
        ultimo = primero;
    }else{
        ultimo->sgt = nuevo;
        ultimo = ultimo->sgt;
    }
    cantElementos++;
}

void Diccionario::borrar(elemento elem) {
    Caja *aux = primero;
    Caja *anterior = NULL;
    bool continuar = true;
    if(primero->elem == elem){
        primero = primero->sgt;
        delete aux;
        cantElementos--;
    }
    while((aux!=NULL)&&(continuar)){
        anterior = aux;
        aux = aux->sgt;
        if(aux->elem==elem){
            anterior->sgt = aux->sgt;
            delete aux;
            cantElementos--;
            continuar = false;
        }
    }
}

bool Diccionario::pertenece(elemento elem) {
    Caja *aux = primero;
    while((aux!=NULL)){
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

