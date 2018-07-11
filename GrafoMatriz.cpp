//
// Created by felipe on 10/06/18.
//

#include "GrafoMatriz.h"

void GrafoMatriz::crear() {
    cantVertices = 0;
    cantAristas = 0;
    ultimoLleno = 0;
    lista.iniciar();
}

void GrafoMatriz::destruir() {
    lista.destruir();
    ultimoLleno = 0;
    cantVertices = 0;
    cantAristas = 0;
}

void GrafoMatriz::vaciar() {
    lista.destruir();
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

vertex GrafoMatriz::agregarVertice(string etiqueta) {
        cantVertices++;
        ultimoLleno++;
        lista.insertar(etiqueta,ultimoLleno);
        for(int i = 0; i <= tam; i++){
            matrizAdyacencia[ultimoLleno][i]=0;
        }
}

void GrafoMatriz::eliminarVertice(vertex indice) {
    lista.borrar(indice);
    for(int i = indice; i <= ultimoLleno; i++){
        for(int j = 1; j <= ultimoLleno; j++){
            matrizAdyacencia[i][j] = matrizAdyacencia[i+1][j];
        }
    }
    ultimoLleno--;
    cantVertices--;
}

void GrafoMatriz::modificarEtiqueta(vertex indice, string etiqueta) {
    lista.modificarElem(etiqueta,indice);
}

string GrafoMatriz::etiqueta(vertex indice) {
    return lista.recuperar(indice);
}

void GrafoMatriz::agregarArista(vertex indiceP, vertex indiceS, int peso) {
        matrizAdyacencia[indiceP][indiceS] = peso;
        cantAristas++;
}

void GrafoMatriz::eliminarArista(vertex indiceP, vertex indiceS) {
    matrizAdyacencia[indiceP][indiceS]=0;
    cantAristas--;
}

void GrafoMatriz::modificarPeso(vertex indiceP, vertex indiceS, int peso) {
    matrizAdyacencia[indiceP][indiceS] = peso;
}

int GrafoMatriz::peso(vertex indiceP, vertex indiceS) {
    //int p = matrizAdyacencia[indiceP][indiceS];
    return matrizAdyacencia[indiceP][indiceS];
}

vertex GrafoMatriz::primerVertice() {
    return 1;
}

vertex GrafoMatriz::sgtVertice(vertex indice) {
    return indice+1;
}

bool GrafoMatriz::existeArista(vertex indiceP, vertex indiceS) {
    if(matrizAdyacencia[indiceP][indiceS]>0){
        return true;
    } else{
        return false;
    }
}

vertex GrafoMatriz::primerVrtAdy(vertex indice) {
    bool terminado = false;
    int contador = 1;
    vertex primerAdy = -1;
    while(!terminado && contador <= numVertices()){
        if(matrizAdyacencia[indice][contador] > 0){
            terminado = true;
            primerAdy = contador;
        }
        contador++;
    }
    return primerAdy;
}

vertex GrafoMatriz::sgtVrtAdy(vertex indiceP, vertex indiceS) {
    bool terminado = false;
    int contador = indiceS+1;
    vertex siguienteAdy = -1;
    while(!terminado && contador <= numVertices()){
        if(matrizAdyacencia[indiceP][contador]>0){
            terminado = true;
            siguienteAdy = contador;
        }
        contador++;
    }
    return siguienteAdy;
}

int GrafoMatriz::numVertices() {
    return ultimoLleno;
}

int GrafoMatriz::numAristas() {
    return cantAristas;
}

int GrafoMatriz::numVrtAdyacentes(vertex v) {
    int numAdya = 0;
    int indice = 1;
    while(indice <= cantVertices){
        if(matrizAdyacencia[v][indice] > 0){
            numAdya++;
        }
        indice++;
    }
    return numAdya;
}
void GrafoMatriz::mostrar() {
    lista.listar();
}

vertex GrafoMatriz::traduceVrt(string e){
    vertex indice = primerVertice();
    vertex resultado = -1;
    bool encontrado = false;
    while(indice <= ultimoLleno && !encontrado){
        if(etiqueta(indice)==e){
            encontrado = true;
            resultado = indice;
        }
        indice++;
    }
    return resultado;
}