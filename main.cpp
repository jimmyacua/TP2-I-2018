//
// Created by jimmy on 10/06/18.
//

#include "Relacion1a1.h"
#include "GrafoDirigListAdy.h"
#include <iostream>
using namespace std;

int main(){
    //cout << "hola putitos" << endl;
    ListaAdyacencia grafo;
    grafo.crear();
    grafo.agregarVertice("a");
    grafo.agregarVertice("b");
    grafo.agregarVertice("c");
    grafo.agregarVertice("d");
    grafo.agregarVertice("e");
    grafo.agregarArista(grafo.traduceVrt("a"),grafo.traduceVrt("b"), 3);
    grafo.agregarArista(grafo.traduceVrt("a"),grafo.traduceVrt("d"), 5);
    grafo.agregarArista(grafo.traduceVrt("c"),grafo.traduceVrt("a"), 6);
    grafo.agregarArista(grafo.traduceVrt("d"),grafo.traduceVrt("e"), 2);
    grafo.agregarArista(grafo.traduceVrt("e"),grafo.traduceVrt("c"), 1);

    vertice v = grafo.primerVrtAdy(grafo.traduceVrt("a"));
    cout << grafo.etiqueta(v) << endl;
    vertice w = grafo.sgtVrtAdy(grafo.traduceVrt("a"), v);
    cout << grafo.etiqueta(w) << endl;



    return 0;
}