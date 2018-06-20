//
// Created by felipe on 10/06/18.
//

#include "GrafoMatriz.h"

void GrafoMatriz::iniciar() {
    cantVertices = 0;
    cantAristas = 0;
    ultimoLleno = 0;
    lista.iniciar();

}

void GrafoMatriz::destruir() {
    lista.destruir();
    ultimoLleno = -1;
    cantVertices = 0;
    cantAristas = 0;
}

void GrafoMatriz::vaciar() {
    lista.vaciar();
    ultimoLleno = 0;
    cantVertices = 0;
    cantAristas = 0;
}

bool GrafoMatriz::vacio() {
    if(ultimoLleno==0){
        return true;
    }else{
        return false;
    }
}

vertice GrafoMatriz::agregarVertice(string etiqueta) {
        lista.insertar(etiqueta,ultimoLleno+1);
        cantVertices++;
        ultimoLleno++;
        for(int i = 1; i = ultimoLleno; i++){
            matrizAdyacencia[ultimoLleno][1]=0;
        }
}

void GrafoMatriz::eliminarVertice(vertice indice) {
    lista.borrar(indice);
    for(int i = indice; i < ultimoLleno; i++){
        for(int j = 1; j = ultimoLleno; j++){
            matrizAdyacencia[i][j] = matrizAdyacencia[i+1][j];
        }
    }
    ultimoLleno--;
    cantVertices--;
}

void GrafoMatriz::modificarEtiqueta(vertice indice, string etiqueta) {
    lista.modificarElem(etiqueta,indice);
}

string GrafoMatriz::etiqueta(vertice indice) {
    return lista.recuperar(indice);
}

void GrafoMatriz::agregarArista(vertice indiceP, vertice indiceS, int peso) {
        matrizAdyacencia[indiceP][indiceS] = peso;
        cantAristas++;
}

void GrafoMatriz::eliminarArista(vertice indiceP, vertice indiceS) {
    matrizAdyacencia[indiceP][indiceS]=0;
    cantAristas--;
}

void GrafoMatriz::modificarPeso(vertice indiceP, vertice indiceS, int peso) {
    matrizAdyacencia[indiceP][indiceS] = peso;
}

int GrafoMatriz::peso(vertice indiceP, vertice indiceS) {
    return matrizAdyacencia[indiceP][indiceS];
}

vertice GrafoMatriz::primerVertice() {
    return 1;
}

vertice GrafoMatriz::siguieteVertice(vertice indice) {
    return indice+1;
}

bool GrafoMatriz::hayArista(vertice indiceP, vertice indiceS) {
    if(matrizAdyacencia[indiceP][indiceS]>0){
        return true;
    } else{
        return false;
    }
}

vertice GrafoMatriz::primerVerticeAdyacente(vertice indice) {
    bool terminado = false;
    int contador = 1;
    vertice primerAdy;
    while(!terminado){
        if(matrizAdyacencia[indice][contador]>0){
            terminado = true;
            primerAdy = matrizAdyacencia[indice][contador];
        }
        contador++;
    }
    return primerAdy;
}

vertice GrafoMatriz::siguienteVerticeAdyacente(vertice indiceP, vertice indiceS) {
    bool terminado = false;
    int contador = indiceS+1;
    vertice siguienteAdy;
    while(!terminado){
        if(matrizAdyacencia[indiceP][contador]>0){
            terminado = true;
            siguienteAdy = matrizAdyacencia[indiceP][contador];
        }
        contador++;
    }
    return siguienteAdy;
}

int GrafoMatriz::numVertices() {
    return cantVertices;
}

int GrafoMatriz::numAristas() {
    return cantAristas;
}

void GrafoMatriz::mostrar() {
    lista.listar();
}