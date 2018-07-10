//
// Created by jimmy on 10/06/18.
//

#include "GrafoDirigListAdy.h"

void ListaAdyacencia::crear() {
    cabeza = 0;
    nVertices = 0;
}

void ListaAdyacencia::destruir() {
    vertice temp = cabeza;
    vertice anterior;
    adyacente ad = temp->ady;
    adyacente antAdy;
    while(temp != 0){
        while(ad != 0){
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
    while(temp != 0){
        while(ad != 0){
            antAdy = ad;
            ad = ad->sgt;
            delete antAdy;
        }
        anterior = temp;
        temp = temp->sgt;
        delete anterior;
    }
    cabeza = 0;
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
    if(cabeza == 0){
        cabeza = nuevo;
    } else{
        nuevo->sgt = cabeza;
        cabeza = nuevo;
    }
    nVertices++;
    return nuevo;
}

void ListaAdyacencia::eliminarVertice(vertice v) {
    vertice aux = cabeza;
    vertice anterior = 0;
    while(aux != 0 && aux != v){
        anterior = aux;
        aux = aux->sgt;
    }
    if(anterior == 0){
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
    if(v1->ady == 0) { //si es el primer adyacente que se agrega
        v1->ady = aris;
        aris->destino = v2;
    } else{
        adyacente aux = v1->ady;
        while(aux->sgt != 0){
            aux = aux->sgt;
        }
        aris->destino = v2;
        aux->sgt = aris;
    }
    v1->numVrtAdy++;

}

void ListaAdyacencia::eliminarArista(vertice v1, vertice v2) {
    adyacente aux = v1->ady;
    adyacente anterior = 0;
    while(aux->destino != v2){
        anterior = aux;
        aux = aux->sgt;
    }
    if(anterior == 0){
        v1->ady = v1->ady->sgt;
        delete aux;
    } else{
        anterior->sgt = aux->sgt;
        delete aux;
    }
    v1->numVrtAdy--;
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
    if(v->sgt != 0){
        return v->sgt;
    } else{
        return 0;
    }
}

vertice ListaAdyacencia::primerVrtAdy(vertice v) {
    if(v->ady != 0){
        return v->ady->destino;
    } else{
        return 0;
    }
}

vertice ListaAdyacencia::sgtVrtAdy(vertice v, vertice ad) {
    adyacente temp = v->ady;
    while(temp != 0 && temp->destino != ad){
        temp = temp->sgt;
    }
    if(temp->sgt != 0){
        return temp->sgt->destino;
    } else {
        return 0;
    }

}

int ListaAdyacencia::numVertices() {
    return nVertices;
}

vertice ListaAdyacencia::traduceVrt(string e) {
    vertice temp = cabeza;
    while(temp != 0 && temp->etiqueta != e){
        temp = temp->sgt;
    }
    return temp;
}

int ListaAdyacencia::numVrtAdyacentes(vertice v) {
    return v->numVrtAdy;
}

bool ListaAdyacencia::existeArista(vertice v1, vertice v2) {
    adyacente ad = v1->ady;
    bool existe = false;
    while(ad != 0 && !existe){
        if(ad->destino == v2){
            existe = true;
        } else{
            ad = ad->sgt;
        }
    }
    return existe;
}