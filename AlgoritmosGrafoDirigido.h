//
// Created by jimmy on 12/06/18.
//

#ifndef TP2_I_2018_ALGORITMOSGRAFODIRIGIDO_H
#define TP2_I_2018_ALGORITMOSGRAFODIRIGIDO_H

#include <iostream>

#include "GrafoDirigListAdy.h"
#include "Relacion1a1.h"
#include "Diccionario.h"

using namespace std;

typedef ListaAdyacencia grafo;
typedef Relacion1a1<vertice, vertice> relacion;


class AlgoritmosGrafoDirigido {
public:
    //EFE:
    //REQ:
    //MOD:
    void dijkstra(grafo& g);

    //EFE:
    //REQ:
    //MOD:
    void floyd(grafo& g);

    //EFE:
    //REQ:
    //MOD:
    void profundidadPrimero(grafo& g);

    //EFE:
    //REQ:
    //MOD:
    void eliminarVertNoAislado(grafo& g, vertice v);

    //EFE:
    //REQ:
    //MOD:
    void copiarGrafo(grafo& g1, grafo g2);

    //EFE:
    //REQ:
    //MOD:
    bool iguales(grafo& g1, grafo& g2);

private:

    //EFE:
    //REQ:
    //MOD:
    void profPrimeroRec(grafo, vertice);
    Diccionario dvv;

};


#endif //TP2_I_2018_ALGORITMOSGRAFODIRIGIDO_H
