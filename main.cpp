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

    AlgoritmosGrafoDirigido alg;
    alg.profundidadPrimero(grafo);




    return 0;
}