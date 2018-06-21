//
// Created by jimmy on 10/06/18.
//

#include "Relacion1a1.h"
//#include "GrafoDirigListAdy.h"
//#include "GrafoMatriz.h"
#include "AlgoritmosGrafoDirigido.h"
#include <iostream>
using namespace std;

int main(){
    //cout << "hola putitos" << endl;
    //ListaAdyacencia grafo;
    GrafoMatriz grafo;
    grafo.crear();
    grafo.agregarVertice("f");
    grafo.agregarVertice("e");
    grafo.agregarVertice("d");
    grafo.agregarVertice("c");
    grafo.agregarVertice("b");
    grafo.agregarVertice("a");
    grafo.agregarArista(grafo.traduceVrt("a"),grafo.traduceVrt("b"), 3);
    grafo.agregarArista(grafo.traduceVrt("a"),grafo.traduceVrt("e"), 5);
    grafo.agregarArista(grafo.traduceVrt("a"),grafo.traduceVrt("f"), 3);
    grafo.agregarArista(grafo.traduceVrt("b"),grafo.traduceVrt("d"), 100);
    grafo.agregarArista(grafo.traduceVrt("b"),grafo.traduceVrt("e"), 2);
    grafo.agregarArista(grafo.traduceVrt("b"),grafo.traduceVrt("f"), 8);
    grafo.agregarArista(grafo.traduceVrt("c"),grafo.traduceVrt("a"), 74);
    grafo.agregarArista(grafo.traduceVrt("c"),grafo.traduceVrt("d"), 1);
    grafo.agregarArista(grafo.traduceVrt("d"),grafo.traduceVrt("a"), 14);
    grafo.agregarArista(grafo.traduceVrt("d"),grafo.traduceVrt("b"), 1);
    grafo.agregarArista(grafo.traduceVrt("e"),grafo.traduceVrt("d"), 1);
    grafo.agregarArista(grafo.traduceVrt("e"),grafo.traduceVrt("c"), 15);
    grafo.agregarArista(grafo.traduceVrt("f"),grafo.traduceVrt("b"), 1);
    grafo.agregarArista(grafo.traduceVrt("f"),grafo.traduceVrt("c"), 7);
    grafo.agregarArista(grafo.traduceVrt("f"),grafo.traduceVrt("e"), 1);
    grafo.agregarArista(grafo.traduceVrt("f"),grafo.traduceVrt("d"), 4);

    grafo.mostrar();
    AlgoritmosGrafoDirigido alg;
    alg.floyd(grafo);




    return 0;
}