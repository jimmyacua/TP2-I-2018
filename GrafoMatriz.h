//
// Created by felipe on 10/06/18.
//

#ifndef TP2_GRAFOMATRIZ_H
#define TP2_GRAFOMATRIZ_H

#endif //TP2_GRAFOMATRIZ_H

#include "ListaIndexadaLSE.h"
#include <string>
#include <iostream>

using namespace std;
typedef ListaIndexadaLSE listaInd;
typedef int vertice;
typedef int arista;
class GrafoMatriz{
public:
    //Efecto:
    //Requiere:
    //Modifica:
    void iniciar();
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
    vertice agregarVertice(string);
    //Efecto:
    //Requiere:
    //Modifica:
    void eliminarVertice(vertice);
    //Efecto:
    //Requiere:
    //Modifica:
    void modificarEtiqueta(vertice,string);
    //Efecto:
    //Requiere:
    //Modifica:
    string etiqueta(vertice);
    //Efecto:
    //Requiere:
    //Modifica:
    void agregarArista(vertice,vertice,int);
    //Efecto:
    //Requiere:
    //Modifica:
    void eliminarArista(vertice,vertice);
    //Efecto:
    //Requiere:
    //Modifica:
    void modificarPeso(vertice,vertice, int);
    //Efecto:
    //Requiere:
    //Modifica:
    int peso(vertice,vertice);
    //Efecto:
    //Requiere:
    //Modifica:
    vertice primerVertice();
    //Efecto:
    //Requiere:
    //Modifica:
    vertice siguieteVertice(vertice);
    //Efecto:
    //Requiere:
    //Modifica:
    bool hayArista(vertice,vertice);
    //Efecto:
    //Requiere:
    //Modifica:
    vertice primerVerticeAdyacente(vertice);
    //Efecto:
    //Requiere:
    //Modifica:
    vertice siguienteVerticeAdyacente(vertice,vertice);
    //Efecto:
    //Requiere:
    //Modifica:
    int numVertices();
    //Efecto:
    //Requiere:
    //Modifica:
    int numAristas();

    void mostrar();
private:
    int matrizAdyacencia[20][20];
    int cantVertices;
    int cantAristas;
    int ultimoLleno;
    listaInd lista;
};