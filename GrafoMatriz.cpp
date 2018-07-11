//
// Created by felipe on 10/06/18.
//

#include "GrafoMatriz.h"

void GrafoMatriz::crear() {
    cantVertices = 0;
    cantAristas = 0;
    ultimoLleno = 0;
    lista.iniciar();
    matrizAdyacencia[6][6];

}

void GrafoMatriz::destruir() {
    lista.destruir();
    ultimoLleno = 0;
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

vertex GrafoMatriz::agregarVertice(string etiqueta) {
        lista.insertar(etiqueta,ultimoLleno+1);
        cantVertices++;
        ultimoLleno++;
        for(int i = 0; i < tam; i++){
            matrizAdyacencia[ultimoLleno-1][i]=0;
        }
}

void GrafoMatriz::eliminarVertice(vertex indice) {
    lista.borrar(indice);
    for(int i = indice; i < ultimoLleno; i++){
        for(int j = 1; j = ultimoLleno; j++){
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
        matrizAdyacencia[indiceP-1][indiceS-1] = peso;
        cantAristas++;
}

void GrafoMatriz::eliminarArista(vertex indiceP, vertex indiceS) {
    matrizAdyacencia[indiceP-1][indiceS-1]=0;
    cantAristas--;
}

void GrafoMatriz::modificarPeso(vertex indiceP, vertex indiceS, int peso) {
    matrizAdyacencia[indiceP-1][indiceS-1] = peso;
}

int GrafoMatriz::peso(vertex indiceP, vertex indiceS) {
    int p = matrizAdyacencia[indiceP-1][indiceS-1];
    return matrizAdyacencia[indiceP-1][indiceS-1];
}

vertex GrafoMatriz::primerVertice() {
    return 1;
}

vertex GrafoMatriz::sgtVertice(vertex indice) {
    return indice+1;
}

bool GrafoMatriz::existeArista(vertex indiceP, vertex indiceS) {
    if(matrizAdyacencia[indiceP-1][indiceS-1]>0){
        return true;
    } else{
        return false;
    }
}

vertex GrafoMatriz::primerVrtAdy(vertex indice) {
    bool terminado = false;
    int contador = 0;
    vertex primerAdy;
    while(!terminado){
        if(matrizAdyacencia[indice][contador]>0){
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
    vertex siguienteAdy;
    while(!terminado){
        if(matrizAdyacencia[indiceP][contador]>0){
            terminado = true;
            siguienteAdy = contador;
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

int GrafoMatriz::numVrtAdyacentes(vertex v) {
    int numAdya = 0;
    int indice = 1;
    while(indice< cantVertices){
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
    vertex resultado;
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