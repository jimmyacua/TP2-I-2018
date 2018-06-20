//
// Created by felipe on 11/05/18.
//

#include "ListaIndexadaLSE.h"
#include <iostream>
#include <string>

using namespace std;

void ListaIndexadaLSE::iniciar(){
    cantElem = 0;
    primero = new Caja();
    ultimo = primero;
}

void ListaIndexadaLSE::destruir(){
    Caja *anterior;
    Caja *temp = primero;
    while(temp != NULL){
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
    cantElem = 0;
}

void ListaIndexadaLSE::vaciar(){
    Caja *anterior;
    Caja *temp = primero->sgt;
    while(temp != NULL){
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
    primero = NULL;
    cantElem = 0;
}

bool ListaIndexadaLSE::vacia(){
    if((cantElem==0)||(primero==NULL)){
        return true;
    }else{
        return false;
    }
}

void ListaIndexadaLSE::insertar(string elemento,int indice){
    Caja *nuevo = new Caja(elemento);
    if(cantElem==0){
        primero = nuevo;
        ultimo = primero;
    }else{
        Caja *aux = primero;
        int contador = 2;
        while(contador < indice) {
            aux = aux->sgt;
            contador++;
        }
        if(indice==1){
            nuevo->sgt = aux;
            primero = nuevo;
        }else {
            nuevo->sgt = aux->sgt;
            aux->sgt = nuevo;
        }
    }
    if(ultimo->sgt!= nullptr){
        Caja *ult = ultimo;
        while(ult->sgt!= nullptr){
            ult = ult->sgt;
        }
        ultimo = ult;
    }
    cantElem++;
}

void ListaIndexadaLSE::borrar(int indice){
    Caja *aux = primero;
    Caja *anterior = NULL;
    int contador = 1;
    while((aux!=NULL)&&(contador<indice)){
        anterior = aux;
        aux = aux->sgt;
        contador++;
    }
    if(anterior==NULL){
        primero = primero->sgt;
        delete aux;
        cantElem--;
    }else{
        anterior->sgt=aux->sgt;
        delete aux;
        cantElem--;
    }
    int a = cantElem;

}

void ListaIndexadaLSE::modificarElem(string elemento,int indice){
    Caja *aux = primero;
    if(indice==1){
        primero->elemento=elemento;
    }else {
        int contador = 1;
        while (contador < indice) {
            aux = aux->sgt;
            contador++;
        }
        aux->elemento = elemento;
    }
}

void ListaIndexadaLSE::intercambiar(int indiceU,int indiceD){
    Caja *aux = primero;
    Caja *pri = new Caja();
    Caja *seg = new Caja();
    int contador = 1;
    while(contador <= cantElem) {
        if(contador==indiceU){
            pri = aux;
        }
        if(contador == indiceD){
            seg = aux;
        }
        aux = aux->sgt;
        contador++;
    }
    string respaldo = pri->elemento;
    pri->elemento = seg->elemento;
    seg->elemento = respaldo;
}

string ListaIndexadaLSE::recuperar(int indice){
    Caja *aux = primero;
    if(indice==1){
        return aux->elemento;
    }
    int contador = 1;
    while(contador < indice) {
        aux = aux->sgt;
        contador++;
    }
    return aux->elemento;
}

int ListaIndexadaLSE::numElem(){
    return cantElem;
}

void ListaIndexadaLSE::listar(){
    Caja *aux = primero;
    while(aux != NULL){
        cout<<aux->elemento<<endl;
        aux = aux->sgt;
    }
}