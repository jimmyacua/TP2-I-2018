//
// Created by jimmy on 12/06/18.
//

#ifndef TP2_I_2018_ALGORITMOSGRAFODIRIGIDO_H
#define TP2_I_2018_ALGORITMOSGRAFODIRIGIDO_H

#include <iostream>
#include <vector>
#include <queue>

#include "GrafoDirigListAdy.h"
//#include "GrafoMatriz.h"
#include "Relacion1a1.h"
#include "Diccionario.h"
#include "GrafoNODirigido.h"

#define Node pair<vertice, int> //vrt adyacente y peso de arista
#define MAX = 20;
using namespace std;


typedef ListaAdyacencia grafo;
typedef vertice vert;

typedef GrafoNODirigido gnd;

class Algoritmos {
public:

    struct cmp {
        bool operator()(const Node &a, const Node &b) { //retorna el menor entre a y b (para Dijkstra)
            return a.second > b.second;
        }
    };

    //EFE:
    //REQ:
    //MOD:
    void dijkstra(grafo& g, vert o);

    //EFE:
    //REQ:
    //MOD:
    void floyd(grafo& g);

    //EFE:
    //REQ:
    //MOD:
    void profundidadPrimero(grafo g);

    //EFE:
    //REQ:
    //MOD:
    void eliminarVertNoAislado(grafo& g, vert v);

    //EFE:
    //REQ:
    //MOD:
    grafo copiarGrafo(grafo g1);

    //EFE:
    //REQ:
    //MOD:
    bool iguales(grafo& g1, grafo& g2);

    //EFE:
    //REQ:
    //MOD:
    void hamilton(gnd& g);

private:

    //EFE:
    //REQ:
    //MOD:
    void profPrimeroRec(grafo, vert);

    void menor(vert actual, int pos, vert ad,int posAd,  int peso);

    vertice* hamiltonRec(gnd& g, vert v, int peso, vert*);

    int solOPtima;
    int numSolFact;

    int distancia[20];
    vertice previo[20];

    priority_queue<Node, vector<Node>, cmp> Q; //lista de prioridad(para Dijkstra)
    Diccionario dvv;
    Relacion1a1<vertice,vertice>  relacion1a1;
};


#endif //TP2_I_2018_ALGORITMOSGRAFODIRIGIDO_H
