//
// Created by jimmy on 12/06/18.
//

#include "AlgoritmosGrafoDirigido.h"


void AlgoritmosGrafoDirigido::profundidadPrimero(grafo g) {
    if(!g.vacio()){
        dvv.crear();
        vertice v = g.primerVertice();
        while(v != NULL){
            if(!dvv.pertenece(v)) {
                profPrimeroRec(g, v);
            }
            v = g.sgtVertice(v);
        }
        dvv.destruir();
        cout << "FIN" << endl;
    }
}

void AlgoritmosGrafoDirigido::profPrimeroRec(grafo g, vertice v) {
    dvv.agregar(v);
    cout << g.etiqueta(v) << " -> ";
    vertice va = g.primerVrtAdy(v);
    while(va != NULL){
        if(!dvv.pertenece(va)){
            profPrimeroRec(g,va);
        }
        va = g.sgtVrtAdy(v, va);
    }
}

void AlgoritmosGrafoDirigido::dijkstra(grafo& g, vertice o) {
    int size = g.numVertices();
    Relacion1a1<vertice, int> par;
    int INF = 99999;
    //int distancia[size];
    bool visitado[size];
    //vertice previo[size];
    vertice listVrt[size];
    vertice v = g.primerVertice();

    listVrt[0] = o;
    int cont = 1;
    vertice v1 = g.primerVertice();
    while(v1 != NULL){
        if(v1 != o){
            listVrt[cont] = v1;
            cont++;
        }
        v1 = g.sgtVertice(v1);
    }

    for (int i = 0; i < size; i++) { //para inicializar los arreglos
        distancia[i] = INF;
        visitado[i] = false;
        previo[i] = NULL;
    } //fin de inicializacion

    Q.push(Node(o, 0));
    distancia[0] = 0;
    vertice actual;
    int peso;
    while (!Q.empty()) {
        actual = Q.top().first;
        Q.pop();
        int pos = 0;
        while (listVrt[pos] != actual) {
            pos++;
        }
        if (!visitado[pos]){
            visitado[pos] = true;
            vertice v = g.primerVrtAdy(actual);
            while (v != NULL) {
                peso = g.peso(actual,v);
                int posV = 0;
                vertice aux = g.primerVertice();
                while (aux != v) {
                    posV++;
                    aux = g.sgtVertice(aux);
                }
                if (!visitado[posV]) {
                    menor(actual, pos, v, posV, peso);
                }
                v = g.sgtVrtAdy(actual,v);
            }
        }
    }

    cout << "Distancia desde origen (" << g.etiqueta(o) << ") a todos los vértices." << endl;
    for(int i = 1; i< size; i++) {
        string camino = "";
        int cont = i;
        while (previo[cont] != o) {
            camino = camino + g.etiqueta(previo[cont]) + "<-";
            int a = 1;
            vertice aux = previo[cont];
            while(a < size && aux != listVrt[a]){
                if(listVrt[a] != previo[cont]){
                    a++;
                } else{
                    a = size;
                }
            }
            cont = a;
        }
            cout << "Etiqueta: " << listVrt[i]->etiqueta << ". Distancia: " << distancia[i] << ". Camino: "
                 << g.etiqueta(listVrt[i]) << "<-" << camino << g.etiqueta(o) << endl;
    }
}

void AlgoritmosGrafoDirigido::menor(vertice actual, int pos, vertice ad, int posAd ,int peso) {
    if(peso < distancia[posAd]){
        distancia[posAd] = peso;
        previo[posAd] = actual;
        Q.push(Node(ad,distancia[posAd]));
    }
}

bool AlgoritmosGrafoDirigido::iguales(grafo &g1, grafo &g2) {
    bool sonIguales = true;
    if(g1.numVertices() != g2.numVertices()){
        sonIguales = false;
    } else{
        relacion1a1.crear();
        vertice v1 = g1.primerVertice();
        while(v1 != NULL && sonIguales){
            vertice v2 = g2.traduceVrt(g1.etiqueta(v1));
            if(v2 != NULL){
                if(g1.numVrtAdyacentes(v1) == g2.numVrtAdyacentes(v2)){
                    relacion1a1.agregarRelacion(v1,v2);
                    v1 = g1.sgtVertice(v1);
                }
                else{
                    sonIguales = false;
                }
            }
            else{
                sonIguales = false;
            }
        }
        if(sonIguales){
            v1 = g1.primerVertice();
            while(v1 != NULL && sonIguales){
                vertice va1 = g1.primerVrtAdy(v1);
                while(va1 != NULL && sonIguales){
                    if(g2.existeArista(relacion1a1.imagen(v1), relacion1a1.imagen(va1))) {
                        if (g1.peso(v1, va1) != g2.peso(relacion1a1.imagen(v1), relacion1a1.imagen(va1))) {
                            sonIguales = false;
                        } else {
                            va1 = g1.sgtVrtAdy(v1, va1);
                        }
                    } else{
                        sonIguales = false;
                    }
                }
                v1 = g1.sgtVertice(v1);
            }
        }
        relacion1a1.destruir();
    }
    return sonIguales;
}

grafo AlgoritmosGrafoDirigido::copiarGrafo(grafo g1) {
    grafo g2;
    g2.crear();
    relacion1a1.crear();
    vertice v1 = g1.primerVertice();
    while(v1 != NULL){
        adyacente ad = v1->ady;
        g2.agregarVertice(g1.etiqueta(v1));
        while(ad != NULL){
            relacion1a1.agregarRelacion(v1,ad->destino);
            ad = ad->sgt;
        }
        v1 = g1.sgtVertice(v1);
    }
    v1 = g1.primerVertice();
    while(v1 != NULL){
        vertice aux = g1.primerVertice();
        while(aux != NULL) {
            if (relacion1a1.existeRelacion(v1, aux)) {
                g2.agregarArista(g2.traduceVrt(g1.etiqueta(v1)), g1.traduceVrt(g1.etiqueta(aux)), g1.peso(v1, aux));
            }
            aux = g1.sgtVertice(aux);
        }
        v1 = g1.sgtVertice(v1);
    }
    return g2;
}

void AlgoritmosGrafoDirigido::eliminarVertNoAislado(grafo& g, vertice v) {
    vertice aux = g.primerVertice();
    while(aux != NULL){
        if(aux != v){
            if(g.existeArista(aux,v)){
                g.eliminarArista(aux,v);
            }
        }
        aux = g.sgtVertice(aux);
    }
    adyacente ad = v->ady;
    while(ad != NULL){
        g.eliminarArista(v,ad->destino);
        ad = ad->sgt;
    }
    g.eliminarVertice(v);
}
