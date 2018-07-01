//
// Created by jimmy on 10/06/18.
//

#include "Relacion1a1.h"
#include "GrafoDirigListAdy.h"
#include "AlgoritmosGrafoDirigido.h"
#include "GrafoNODirigido.h"

int main(){

    GrafoNODirigido g;
    g.crear();
    g.agregarVertice("a");
    g.agregarVertice("b");
    g.agregarArista(g.traduceVrt("a"),g.traduceVrt("b"), 9);
    bool r = g.existeArista(g.traduceVrt("a"),g.traduceVrt("b"));
    cout << r << endl;
    r = g.traduceVrt("b"),g.traduceVrt("a");
    cout << r;


    return 0;
}