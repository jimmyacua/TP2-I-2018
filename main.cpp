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
    grafo.agregarVertice("f");
    grafo.agregarVertice("e");
    grafo.agregarVertice("d");
    grafo.agregarVertice("c");
    grafo.agregarVertice("b");
    grafo.agregarVertice("a");
    grafo.agregarArista(grafo.traduceVrt("a"),grafo.traduceVrt("b"), 3);
    grafo.agregarArista(grafo.traduceVrt("a"),grafo.traduceVrt("e"), 5);
    grafo.agregarArista(grafo.traduceVrt("a"),grafo.traduceVrt("f"), 6);
    grafo.agregarArista(grafo.traduceVrt("b"),grafo.traduceVrt("e"), 2);
    grafo.agregarArista(grafo.traduceVrt("c"),grafo.traduceVrt("d"), 1);
    grafo.agregarArista(grafo.traduceVrt("d"),grafo.traduceVrt("b"), 1);
    grafo.agregarArista(grafo.traduceVrt("e"),grafo.traduceVrt("d"), 1);
    grafo.agregarArista(grafo.traduceVrt("f"),grafo.traduceVrt("b"), 1);
    grafo.agregarArista(grafo.traduceVrt("f"),grafo.traduceVrt("e"), 1);

    ListaAdyacencia g2;
    g2.crear();
    g2.agregarVertice("g");
    g2.agregarVertice("e");
    g2.agregarVertice("d");
    g2.agregarVertice("c");
    g2.agregarVertice("b");
    g2.agregarVertice("a");
    g2.agregarArista(g2.traduceVrt("a"),g2.traduceVrt("b"), 3);
    g2.agregarArista(g2.traduceVrt("a"),g2.traduceVrt("e"), 5);
    g2.agregarArista(g2.traduceVrt("a"),g2.traduceVrt("g"), 6);
    g2.agregarArista(g2.traduceVrt("b"),g2.traduceVrt("e"), 2);
    g2.agregarArista(g2.traduceVrt("c"),g2.traduceVrt("d"), 1);
    g2.agregarArista(g2.traduceVrt("d"),g2.traduceVrt("b"), 1);
    g2.agregarArista(g2.traduceVrt("e"),g2.traduceVrt("d"), 1);
    g2.agregarArista(g2.traduceVrt("g"),g2.traduceVrt("b"), 1);
    g2.agregarArista(g2.traduceVrt("g"),g2.traduceVrt("e"), 1);

    AlgoritmosGrafoDirigido alg;
    bool r = alg.iguales(grafo, g2);
    cout << r;




    return 0;
}