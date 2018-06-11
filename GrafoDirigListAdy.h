//
// Created by jimmy on 10/06/18.
//

#ifndef TP2_I_2018_LISTAADYACENCIA_H
#define TP2_I_2018_LISTAADYACENCIA_H

#include <string>
#include <iostream>

using namespace std;

struct Vertice{
    string etiqueta;
    Vertice *sgt;
    struct Arista *ady;

    Vertice(){
        etiqueta = "";
        sgt = NULL;
        ady = NULL;
    };

    Vertice(string e){
        etiqueta = e;
        ady = NULL;
    };

};

struct Arista{
    Vertice *destino;
    Arista *sgt;
    int peso;

    Arista(){
        destino = NULL;
        sgt = NULL;
        peso = -1;
    };

    Arista(int p){
        destino = NULL;
        sgt = NULL;
        peso = p;
    }
};
typedef Vertice* vertice;
typedef Arista* adyacente;

class ListaAdyacencia {
public:

    //EFE:
    //REQ:
    //MOD:
    void crear();

    //EFE:
    //REQ:
    //MOD:
    void destruir();

    //EFE:
    //REQ:
    //MOD:
    void vaciar();

    //EFE:
    //REQ:
    //MOD:
    bool vacia();

    //EFE:
    //REQ:
    //MOD:
    vertice agregarVertice(string e);

    //EFE:
    //REQ:
    //MOD:
    void eliminarVertice(vertice v);

    //EFE:
    //REQ:
    //MOD:
    void modificarEtiqueta(vertice v, string e);

    //EFE:
    //REQ:
    //MOD:
    string etiqueta(vertice v);

    //EFE:
    //REQ:
    //MOD:
    void agregarArista(vertice v1, vertice v2);

    //EFE:
    //REQ:
    //MOD:
    void eliminarArista(vertice v1, vertice v2);

    //EFE:
    //REQ:
    //MOD:
    void modificarPeso(vertice v1, vertice v2, int p);

    //EFE:
    //REQ:
    //MOD:
    int peso(vertice v1, vertice v2);

    //EFE:
    //REQ:
    //MOD:
    vertice primerVertice();

    //EFE:
    //REQ:
    //MOD:
    vertice sgtVErtice(vertice v);

    //EFE:
    //REQ:
    //MOD:
    vertice primerVrtAdy(vertice v);

    //EFE:
    //REQ:
    //MOD:
    vertice sgtVrtAdy(vertice v, vertice ad);

    //EFE:
    //REQ:
    //MOD:
    int numVertices();

private:
    int nVertices;
    vertice cabeza;

};


#endif //TP2_I_2018_LISTAADYACENCIA_H
