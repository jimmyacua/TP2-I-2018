//
// Created by jimmy on 10/06/18.
//

#include "Relacion1a1.h"
#include "GrafoDirigListAdy.h"
#include "AlgoritmosGrafoDirigido.h"

int main(){
    ListaAdyacencia grafo;
    grafo.crear();
    grafo.agregarVertice("5");
    grafo.agregarVertice("4");
    grafo.agregarVertice("3");
    grafo.agregarVertice("2");
    grafo.agregarVertice("1");
    grafo.agregarArista(grafo.traduceVrt("1"),grafo.traduceVrt("2"), 10);
    grafo.agregarArista(grafo.traduceVrt("1"),grafo.traduceVrt("4"), 30);
    grafo.agregarArista(grafo.traduceVrt("1"),grafo.traduceVrt("5"), 100);
    grafo.agregarArista(grafo.traduceVrt("2"),grafo.traduceVrt("3"), 50);
    grafo.agregarArista(grafo.traduceVrt("3"),grafo.traduceVrt("5"), 10);
    grafo.agregarArista(grafo.traduceVrt("4"),grafo.traduceVrt("3"), 20);
    grafo.agregarArista(grafo.traduceVrt("4"),grafo.traduceVrt("5"), 60);



    AlgoritmosGrafoDirigido alg;
    alg.dijkstra(grafo, grafo.primerVertice());

    return 0;
}