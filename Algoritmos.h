//
// Created by jimmy on 12/06/18.
//

#ifndef TP2_I_2018_ALGORITMOSGRAFODIRIGIDO_H
#define TP2_I_2018_ALGORITMOSGRAFODIRIGIDO_H

#include <iostream>

//#include "GrafoDirigListAdy.h"
//#include "ListaIndexadaLSE.h"
//#include "GrafoMatriz.h"
#include "Relacion1a1.h"
#include "Diccionario.h"
#include "GrafoNODirigido.h"

using namespace std;


typedef ListaAdyacencia grafo;
typedef vertice vert;

//typedef GrafoMatriz grafo;
//typedef int vert;

typedef GrafoNODirigido gnd;

class Algoritmos {
public:

    //EFE: Devuelve el camino más corto desde el vertice de origen a cualquier otro vertice
    //REQ: Grafo Dirigido inicializado y no vacio, vertice de origen valido
    //MOD: -
    void dijkstra(grafo& g, vert o);

    //EFE: encuentra el camino minimo entre todos los vertices
    //REQ: grafo dirigido inicializado y no vacio
    //MOD: -
    void floyd(grafo& g);

    //EFE: Recorre el grafo en profundidad primero
    //REQ: grafo Dirigido inicializado y no vacio
    //MOD: -
    void profundidadPrimero(grafo g);

    //EFE: borra el vertice v del grafo g
    //REQ: grafo Dirigido inicializado y no vacio, v valido
    //MOD: grafo g
    void eliminarVertNoAislado(grafo& g, vert v);

    //EFE: devuelve una copia del grafo g1
    //REQ: grafo dirigido g1 inicializado
    //MOD: -
    grafo copiarGrafo(grafo& g1);

    //EFE: devuelve true si los grafos g1 y g2 son iguales, false si no
    //REQ: grafos Dirigidos inicializados
    //MOD: -
    bool iguales(grafo& g1, grafo& g2);

    //EFE: encuentra el ciclo hamiltoniano en el grafo g
    //REQ: Grafo NO Dirigido inicializado y no vacio
    //MOD: -
    void hamilton(gnd& g);

    //EFE: encuentra el arbol de minimo costo del grafo g
    //REQ: Grafo NO Dirigido inicializado y no vacio
    //MOD: -
    void prim(gnd& g);

private:

    void profPrimeroRec(grafo, vert);

    int menorArista(int aristas[],bool visitados[],int tam);


    vert* hamiltonRec(gnd& g, vert v, int peso, vert*);
    vert minimo(grafo, vert, int);

    int solOPtima;
    int numSolFact;

    vert previo[20];
    Diccionario dvv;
    Relacion1a1<vert,vert>  relacion1a1;
    Relacion1a1<vert, int> distanciaR;


};


#endif //TP2_I_2018_ALGORITMOSGRAFODIRIGIDO_H