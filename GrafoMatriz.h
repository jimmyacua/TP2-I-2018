//
// Created by felipe on 10/06/18.
//

#ifndef  TP2_I_2018_GRAFOMATRIZ_H
#define  TP2_I_2018_GRAFOMATRIZ_H



#include "ListaIndexadaLSE.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

typedef ListaIndexadaLSE listaInd;
typedef int vertex;
typedef int arista;

class GrafoMatriz {
public:
    //Efecto:
    //Requiere:
    //Modifica:
    void crear();
    //Efecto:
    //Requiere:
    //Modifica:
    void destruir();
    //Efecto:
    //Requiere:
    //Modifica:
    void vaciar();
    //Efecto:
    //Requiere:
    //Modifica:
    bool vacio();
    //Efecto:
    //Requiere:
    //Modifica:
    vertex agregarVertice(string);
    //Efecto:
    //Requiere:
    //Modifica:
    void eliminarVertice(vertex);
    //Efecto:
    //Requiere:
    //Modifica:
    void modificarEtiqueta(vertex,string);
    //Efecto:
    //Requiere:
    //Modifica:
    string etiqueta(vertex);
    //Efecto:
    //Requiere:
    //Modifica:
    void agregarArista(vertex,vertex,int);
    //Efecto:
    //Requiere:
    //Modifica:
    void eliminarArista(vertex,vertex);
    //Efecto:
    //Requiere:
    //Modifica:
    void modificarPeso(vertex,vertex, int);
    //Efecto:
    //Requiere:
    //Modifica:
    int peso(vertex,vertex);
    //Efecto:
    //Requiere:
    //Modifica:
    vertex primerVertice();
    //Efecto:
    //Requiere:
    //Modifica:
    vertex sgtVertice(vertex);
    //Efecto:
    //Requiere:
    //Modifica:
    bool existeArista(vertex,vertex);
    //Efecto:
    //Requiere:
    //Modifica:
    vertex primerVrtAdy(vertex);
    //Efecto:
    //Requiere:
    //Modifica:
    vertex sgtVrtAdy(vertex,vertex);
    //Efecto:
    //Requiere:
    //Modifica:
    int numVertices();
    //Efecto:
    //Requiere:
    //Modifica:
    int numAristas();

    void mostrar();

    vertex traduceVrt(string);

    int numVrtAdyacentes(vertex);

private:
    int tam = 6;
    int matrizAdyacencia[6][6];
    int cantVertices;
    int cantAristas;
    int ultimoLleno;
    listaInd lista;
};

#endif //TP2_GRAFOMATRIZ_H