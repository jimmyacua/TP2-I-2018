//
// Created by jimmy on 10/06/18.
//

#include "Relacion1a1.h"
//#include "GrafoDirigListAdy.h"
#include "Algoritmos.h"
#include "GrafoNODirigido.h"

int main(){

    GrafoNODirigido g;
    g.crear();
    g.agregarVertice("e");
    g.agregarVertice("d");
    g.agregarVertice("c");
    g.agregarVertice("b");
    g.agregarVertice("a");
    g.agregarArista(g.traduceVrt("a"),g.traduceVrt("b"), 3);
    g.agregarArista(g.traduceVrt("a"),g.traduceVrt("c"), 4);
    g.agregarArista(g.traduceVrt("a"),g.traduceVrt("d"), 2);
    g.agregarArista(g.traduceVrt("a"),g.traduceVrt("e"), 7);
    g.agregarArista(g.traduceVrt("b"),g.traduceVrt("c"), 4);
    g.agregarArista(g.traduceVrt("b"),g.traduceVrt("d"), 6); //grafo visto en clase
    g.agregarArista(g.traduceVrt("b"),g.traduceVrt("e"), 3);
    g.agregarArista(g.traduceVrt("c"),g.traduceVrt("d"), 5);
    g.agregarArista(g.traduceVrt("c"),g.traduceVrt("e"), 8);
    g.agregarArista(g.traduceVrt("d"),g.traduceVrt("e"), 6);


    Algoritmos algoritmos;
    //algoritmos.hamilton(g);
    algoritmos.prim(g);
    /*vertice v = g.primerVertice();
    while(v != NULL){
        cout << g.etiqueta(v) << ": ";
        vertice va = g.primerVrtAdy(v);
        while(va != NULL){
            cout << g.etiqueta(va) << " -> ";
            va = g.sgtVrtAdy(v,va);
        }
        v = g.sgtVertice(v);
        cout << endl;
    }
*/

    return 0;
}