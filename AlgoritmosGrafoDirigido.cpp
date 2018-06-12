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