//
// Created by jimmy on 12/06/18.
//

#include "AlgoritmosGrafoDirigido.h"

void AlgoritmosGrafoDirigido::profundidadPrimero(grafo& g) {
    if(!g.vacio()){
        dvv.crear();
        profPrimeroRec(g, g.primerVertice());
        dvv.destruir();
    }
}

void AlgoritmosGrafoDirigido::profPrimeroRec(grafo g, vertice v) {
    if(v != NULL && !dvv.pertenece(v)) {
        dvv.agregar(v);
        cout << g.etiqueta(v) << ",";
        vertice va = g.primerVrtAdy(v);
        while (va != NULL) {
            profPrimeroRec(g, va);
            va = g.sgtVrtAdy(v, va);
        }
    }
}

void AlgoritmosGrafoDirigido::floyd(grafo& g) {
    int tamano = g.numVertices();
    int caminos[tamano][tamano];
    vertice indice = g.primerVertice();
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            if (g.existeArista(indice, g.sgtVertice(indice))) {
                caminos[i][j] = g.peso(indice, g.sgtVertice(indice));
            } else {
                caminos[i][j] = 1000;
            }
        }
        indice = g.sgtVertice(indice);
    }

    for (int k = 0; k < tamano; k++) {
        for (int i = 0; i < tamano; i++){
            for (int j = 0; j < tamano; j++){
                if (caminos[i][k] + caminos[k][j] < caminos[i][j]) {
                    caminos[i][j] = caminos[i][k] + caminos[k][j];
                }
            }
        }
    }

    for (int i = 0; i < tamano; i++)
    {
        for (int j = 0; j < tamano; j++)
        {
            if (caminos[i][j] == 1000)
                printf("%7s", "INF");
            else
                printf ("%7d", caminos[i][j]);
        }
        printf("\n");
    }
}