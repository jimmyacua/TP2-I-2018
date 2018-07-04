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

void AlgoritmosGrafoDirigido::floyd(grafo& g) {
    int tamano = g.numVertices();
    int pesos[tamano][tamano];
    string caminos[tamano][tamano];
    vertice indice = g.primerVertice();
    for (int i = 0; i < tamano; i++) {
        vertice comp = g.primerVertice();
        for (int j = 0; j < tamano; j++) {
            caminos[j][i] = g.etiqueta(indice);
            if (g.existeArista(indice, comp)) {
                pesos[i][j] = g.peso(indice, comp);
            } else {
                pesos[i][j] = 1000;
            }
            comp = g.sgtVertice(comp);
        }
        indice = g.sgtVertice(indice);
    }

    for (int k = 0; k < tamano; k++) {
        for (int i = 0; i < tamano; i++){
            for (int j = 0; j < tamano; j++){
                if (pesos[i][k] + pesos[k][j] < pesos[i][j]) {
                    pesos[i][j] = pesos[i][k] + pesos[k][j];
                    caminos[i][j] = g.etiqueta(k);
                }
            }
        }
    }

    for (int i = 0; i < tamano; i++)
    {
        for (int j = 0; j < tamano; j++)
        {
            if (pesos[i][j] == 1000)
                printf("%7s", "INF");
            else
                printf ("%7d", pesos[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < tamano; i++)
    {
        for (int j = 0; j < tamano; j++)
        {
            cout<<caminos[i][j]<<" ";
            //printf ("%7d", caminos[i][j]);
        }
        printf("\n");
    }
}

int AlgoritmosGrafoDirigido::menorArista(int aristas[], bool visitados[], int tam) {
    int min = 1000;
    int minInd;
    for(int i=0; i<tam; i++){
        if(visitados[i]==false&&aristas[i]<min){
            min = aristas[i];
            minInd = i;
        }
    }
    return minInd;
}

void AlgoritmosGrafoDirigido::prim(grafo &g) {
    int tam = g.numVertices();
    int aristasPesos[tam];
    bool visitados[tam];
    vertice camino[tam];
    //Rellena los pesos y los visitados
    for(int i=0;i<tam;i++){
        aristasPesos[i]=1000;//Se pone 1000 en lugar del INF
        visitados[i] = false;
    }
    aristasPesos[0] = 0;
    camino[0] = NULL;
    for(int j=0; j < tam-1; j++){
        int minimo = menorArista(aristasPesos,visitados,tam);
        visitados[minimo] = true;
        for(int i=0;i<tam;i++){
            if((g.existeArista(minimo,i))&&(visitados[i]==false)&&(g.peso(minimo,i))){
                camino[i] = minimo;
                aristasPesos[i] = g.peso(minimo,i);
            }
        }
    }
    //imprimir
}