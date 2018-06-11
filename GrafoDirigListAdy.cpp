//
// Created by jimmy on 10/06/18.
//

#include "GrafoDirigListAdy.h"

void ListaAdyacencia::crear() {
    cabeza = new Vertice();
    nVertices = 0;
}

void ListaAdyacencia::destruir() {}

void ListaAdyacencia::vaciar() {}

bool ListaAdyacencia::vacia() {
    if(nVertices == 0){
        return true;
    } else{
        return false;
    }
}

vertice ListaAdyacencia::agregarVertice(string e) {
    vertice nuevo = new Vertice(e);
    if(cabeza == NULL){
        cabeza = nuevo;
    } else{
        nuevo->sgt = cabeza;
        cabeza = nuevo;
    }
    nVertices++;
}

void ListaAdyacencia::eliminarVertice(vertice v) {
    vertice aux = cabeza;
    vertice anterior = NULL;
    while(aux != NULL && aux != v){
        anterior = aux;
        aux = aux->sgt;
    }
    if(anterior == NULL){
        cabeza = cabeza->sgt;
        delete aux;
        nVertices--;
    } else{
        anterior->sgt = aux->sgt;
        delete aux;
        nVertices--;
    }
}

void ListaAdyacencia::modificarEtiqueta(vertice v, string e) {
    v->etiqueta = e;
}

string ListaAdyacencia::etiqueta(vertice v) {
    return v->etiqueta;
}

void ListaAdyacencia::agregarArista(vertice v1, vertice v2) {
    v1->ady->destino = v2;
}

void ListaAdyacencia::eliminarArista(vertice v1, vertice v2) {
    if(v1->ady->destino == v2){
        v1->ady->destino = NULL;
    }
}

void ListaAdyacencia::modificarPeso(vertice v1, vertice v2, int p) {
    v1->ady->peso = p;
}

vertice ListaAdyacencia::primerVertice() {
    return cabeza;
}

vertice ListaAdyacencia::sgtVErtice(vertice v) {
    return v->sgt;
}

vertice ListaAdyacencia::primerVrtAdy(vertice v) {
    if(v->ady->destino != NULL){
        return v->ady->destino;
    } else{
        return NULL;
    }
}

vertice ListaAdyacencia::sgtVrtAdy(vertice v, vertice ad) {
    adyacente temp = v->ady;
    while(temp != NULL && temp->destino != ad){
        temp = temp->sgt;
    }
    return temp->destino;
}

int ListaAdyacencia::numVertices() {
    return nVertices;
}
