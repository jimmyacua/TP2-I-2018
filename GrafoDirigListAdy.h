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
    int numVrtAdy;

    Vertice(){
        etiqueta = "";
        sgt = NULL;
        ady = NULL;
        numVrtAdy = 0;
    };

    Vertice(string e){
        etiqueta = e;
        ady = NULL;
        numVrtAdy = 0;
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

    //EFE: inicializa el grafo
    //REQ: -
    //MOD: -
    void crear();

    //EFE: destruye el grafo dejandolo initulizable
    //REQ: grafo inicializado
    //MOD: el grafo
    void destruir();

    //EFE: elimina todos los elementos del grafo
    //REQ: grafo inicializado
    //MOD: el grafo
    void vaciar();

    //EFE: devuelve true si el grafo está vacío, false si no.
    //REQ: grafo inicializado
    //MOD: -
    bool vacio();

    //EFE: agrega un nuevo vertice con la etiqueta e al grafo.
    //REQ: grafo inicializado, etiqueta de tipo hilera
    //MOD: el grafo
    vertice agregarVertice(string e);

    //EFE: elimina el vertice v del grafo
    //REQ: grafo inicializado y que el vertice v exista en el grafo
    //MOD: el grafo
    void eliminarVertice(vertice v);

    //EFE: asigna una nueva etiqueta e al vertice v
    //REQ: grafo inicializado, que el vertice v exista en el grafo y etiqueta de tipo hilera
    //MOD:
    void modificarEtiqueta(vertice v, string e);

    //EFE: devuelve la etiqueta el vertice v
    //REQ: grafo inicializado y que el vertice v exista en el grafo
    //MOD: -
    string etiqueta(vertice v);

    //EFE: agrega una arista del vertice v1 al vertice v2 con peso p
    //REQ: grafo inicializado, vertices v1 y v2 validos y peso de tipo entero
    //MOD: el grafo
    void agregarArista(vertice v1, vertice v2, int p);

    //EFE: elimina la arista que sale de v1 a v2
    //REQ: grafo inicializado y que exista la arista de v1 a v2
    //MOD: el grafo
    void eliminarArista(vertice v1, vertice v2);

    //EFE: cambia el peso de la arista de v1 a v2
    //REQ: grafo inicializado y que exista la arista de v1 a v2
    //MOD: la arista de v1 a v2 y el grafo
    void modificarPeso(vertice v1, vertice v2, int p);

    //EFE: devuelve el peso de la arista de v1 a v2
    //REQ: grafo inicializado y que exista la arista de v1 a v2
    //MOD: -
    int peso(vertice v1, vertice v2);

    //EFE: devuelve un vertice el grafo
    //REQ: grafo inicializado y no vacio
    //MOD: -
    vertice primerVertice();

    //EFE: devuelve el vertice "siguiente" a v
    //REQ: grafo inicializado y no vacio, v valido
    //MOD: -
    vertice sgtVertice(vertice v);

    //EFE: devuelve el primer vertice adyacente a v
    //REQ: grafo inicializado y no vacio. V valido y con vertices adyacentes
    //MOD: -
    vertice primerVrtAdy(vertice v);

    //EFE: devuelve un vertice adyacente a v distinto de ad
    //REQ: grafo inicializado y no vacio, v y ad validos.
    //MOD: -
    vertice sgtVrtAdy(vertice v, vertice ad);

    //EFE: devuelve el numero de vertices que hay en el grafo
    //REQ: grafo inicializado
    //MOD: -
    int numVertices();

    //EFE: devuelve el numero de vertices adyacentes a v
    //REQ: grafo inicializado y v valido
    //MOD: -
    int numVrtAdyacentes(vertice v);

    //EFE: devuelve true si existe una arista de v1 a v2, false si no.
    //REQ: grafo inicializado y v1 y v2 validos
    //MOD: -
    bool existeArista(vertice v1, vertice v2);

    //EFE: devuelve el vertice con la etiqueta e
    //REQ: grafo inicializado y que no hayan etiquetas repetidas
    //MOD: -
    vertice traduceVrt(string e);

private:
    int nVertices;
    vertice cabeza;

};


#endif //TP2_I_2018_LISTAADYACENCIA_H
