//
// Created by jimmy on 10/06/18.
//

#include "GrafoDirigListAdy.h"

void ListaAdyacencia::crear() {
    cabeza = new Vertice();
    nVertices = 0;
}

void ListaAdyacencia::destruir() {
    vertice temp = cabeza;
    vertice anterior;
    adyacente ad = temp->ady;
    adyacente antAdy;
    while(temp != NULL){
        while(ad != NULL){
            antAdy = ad;
            ad = ad->sgt;
            delete antAdy;
        }
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
}

void ListaAdyacencia::vaciar() {
    vertice temp = cabeza;
    vertice anterior;
    adyacente ad = temp->ady;
    adyacente antAdy;
    while(temp != NULL){
        while(ad != NULL){
            antAdy = ad;
            ad = ad->sgt;
            delete antAdy;
        }
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
    cabeza = new Vertice();
    nVertices = 0;
}

bool ListaAdyacencia::vacio() {
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

void ListaAdyacencia::agregarArista(vertice v1, vertice v2, int p) {
    adyacente aris = new Arista(p);
    if(v1->ady == NULL) { //si es el primer adyacente que se agrega
        v1->ady = aris;
        aris->destino = v2;
    } else{
        adyacente aux = v1->ady;
        while(aux->sgt != NULL){
            aux = aux->sgt;
        }
        aris->destino = v2;
        aux->sgt = aris;
    }

}

void ListaAdyacencia::eliminarArista(vertice v1, vertice v2) {
    adyacente aux = v1->ady;
    adyacente anterior = NULL;
    while(aux->destino != v2){
        anterior = aux;
        aux = aux->sgt;
    }
    if(anterior == NULL){
        v1->ady = v1->ady->sgt;
        delete aux;
    } else{
        anterior->sgt = aux->sgt;
        delete aux;
    }

}

void ListaAdyacencia::modificarPeso(vertice v1, vertice v2, int p) {
    adyacente aux = v1->ady;
    while(aux->destino != v2){
        aux = aux->sgt;
    }
    aux->peso = p;
}

int ListaAdyacencia::peso(vertice v1, vertice v2) {
    adyacente aux = v1->ady;
    while(aux->destino != v2){
        aux = aux->sgt;
    }
    return aux->peso;
}

vertice ListaAdyacencia::primerVertice() {
    return cabeza;
}

vertice ListaAdyacencia::sgtVertice(vertice v) {
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
    if(temp->sgt != NULL){
        return temp->sgt->destino;
    } else{
        return NULL;
    }
}

int ListaAdyacencia::numVertices() {
    return nVertices;
}

vertice ListaAdyacencia::traduceVrt(string e) {
    vertice temp = cabeza;
    while(temp != NULL && temp->etiqueta != e){
        temp = temp->sgt;
    }
    return temp;
}