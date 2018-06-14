//
// Created by jimmy on 10/06/18.
//

#include "Relacion1a1.h"
#include "GrafoDirigListAdy.h"
#include "AlgoritmosGrafoDirigido.h"
#include <iostream>
using namespace std;

int main(){
    //cout << "hola putitos" << endl;
    ListaAdyacencia grafo;
    grafo.crear();
    //grafo.agregarVertice("f");
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
    //grafo.agregarArista(grafo.traduceVrt("f"),grafo.traduceVrt("b"), 4);
    //grafo.agregarArista(grafo.traduceVrt("f"),grafo.traduceVrt("e"), 5);

    ListaAdyacencia g2;
    g2.crear();
    /*g2.agregarVertice("f");
    g2.agregarVertice("e");
    g2.agregarVertice("d");
    g2.agregarVertice("c");
    g2.agregarVertice("b");
    g2.agregarVertice("a");
    g2.agregarArista(g2.traduceVrt("a"),g2.traduceVrt("b"), 3);
    g2.agregarArista(g2.traduceVrt("a"),g2.traduceVrt("e"), 5);
    g2.agregarArista(g2.traduceVrt("a"),g2.traduceVrt("f"), 6);
    g2.agregarArista(g2.traduceVrt("b"),g2.traduceVrt("e"), 2);
    g2.agregarArista(g2.traduceVrt("c"),g2.traduceVrt("d"), 1);
    g2.agregarArista(g2.traduceVrt("d"),g2.traduceVrt("b"), 1);
    g2.agregarArista(g2.traduceVrt("e"),g2.traduceVrt("d"), 1);
    g2.agregarArista(g2.traduceVrt("f"),g2.traduceVrt("b"), 1);
    g2.agregarArista(g2.traduceVrt("f"),g2.traduceVrt("e"), 1);
    */
    AlgoritmosGrafoDirigido alg;
    alg.dijkstra(grafo, grafo.traduceVrt("5"));
    /*
    vertice v = c.primerVertice();
    while(v != NULL){
        cout << c.etiqueta(v) << ":";
        vertice va = c.primerVrtAdy(v);
        while(va != NULL){
            cout << c.etiqueta(va) << "->";
            va = c.sgtVrtAdy(v,va);
        }
        cout << endl;
        v = c.sgtVertice(v);
    }
    */

    return 0;
}