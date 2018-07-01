//
// Created by jimmy on 30/06/18.
//

#ifndef TP2_I_2018_GRAFONODIRIGIDO_H
#define TP2_I_2018_GRAFONODIRIGIDO_H

#include "GrafoDirigListAdy.h"
#include "AlgoritmosGrafoDirigido.h"

typedef ListaAdyacencia grafo;
typedef vertice vert;

//typedef Matriz grafo;
// vertice int


class GrafoNODirigido {
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
    vert agregarVertice(string e);

    //EFE: elimina el vertice v del grafo
    //REQ: grafo inicializado y que el vertice v exista en el grafo
    //MOD: el grafo
    void eliminarVertice(vert v);

    //EFE: asigna una nueva etiqueta e al vertice v
    //REQ: grafo inicializado, que el vertice v exista en el grafo y etiqueta de tipo hilera
    //MOD:
    void modificarEtiqueta(vert v, string e);

    //EFE: devuelve la etiqueta el vertice v
    //REQ: grafo inicializado y que el vertice v exista en el grafo
    //MOD: -
    string etiqueta(vert v);

    //EFE: agrega una arista del vertice v1 al vertice v2 con peso p
    //REQ: grafo inicializado, vertices v1 y v2 validos y peso de tipo entero
    //MOD: el grafo
    void agregarArista(vert v1, vert v2, int p);

    //EFE: elimina la arista que sale de v1 a v2
    //REQ: grafo inicializado y que exista la arista de v1 a v2
    //MOD: el grafo
    void eliminarArista(vert v1, vert v2);

    //EFE: cambia el peso de la arista de v1 a v2
    //REQ: grafo inicializado y que exista la arista de v1 a v2
    //MOD: la arista de v1 a v2 y el grafo
    void modificarPeso(vert v1, vert v2, int p);

    //EFE: devuelve el peso de la arista de v1 a v2
    //REQ: grafo inicializado y que exista la arista de v1 a v2
    //MOD: -
    int peso(vert v1, vert v2);

    //EFE: devuelve un vertice el grafo
    //REQ: grafo inicializado y no vacio
    //MOD: -
    vert primerVertice();

    //EFE: devuelve el vertice "siguiente" a v
    //REQ: grafo inicializado y no vacio, v valido
    //MOD: -
    vert sgtVertice(vert v);

    //EFE: devuelve el primer vertice adyacente a v
    //REQ: grafo inicializado y no vacio. V valido y con vertices adyacentes
    //MOD: -
    vert primerVrtAdy(vert v);

    //EFE: devuelve un vertice adyacente a v distinto de ad
    //REQ: grafo inicializado y no vacio, v y ad validos.
    //MOD: -
    vert sgtVrtAdy(vert v, vert ad);

    //EFE: devuelve el numero de vertices que hay en el grafo
    //REQ: grafo inicializado
    //MOD: -
    int numVertices();

    //EFE: devuelve el numero de vertices adyacentes a v
    //REQ: grafo inicializado y v valido
    //MOD: -
    int numVrtAdyacentes(vert v);

    //EFE: devuelve true si existe una arista de v1 a v2, false si no.
    //REQ: grafo inicializado y v1 y v2 validos
    //MOD: -
    bool existeArista(vert v1, vert v2);

    //EFE: devuelve el vertice con la etiqueta e
    //REQ: grafo inicializado y que no hayan etiquetas repetidas
    //MOD: -
    vert traduceVrt(string e);

private:
    int nVertices;
    grafo g;
};


#endif //TP2_I_2018_GRAFONODIRIGIDO_H
