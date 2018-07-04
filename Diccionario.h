//
// Created by felipe on 10/06/18.
//

#ifndef TP2_I_2018_DICCIONARIO_H
#define TP2_I_2018_DICCIONARIO_H

#include "GrafoDirigListAdy.h"

typedef vertice elemento;

struct Caja{
public:
    elemento elem;
    Caja* sgt;
    Caja(){
        sgt = nullptr;
    }
    Caja(elemento elmt){
        elem = elmt;
        sgt = nullptr;
    }

};

class Diccionario{
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
    void agregar(elemento);
    //Efecto:
    //Requiere:
    //Modifica:
    void borrar(elemento);
    //Efecto:
    //Requiere:
    //Modifica:
    bool pertenece(elemento);
    //Efecto:
    //Requiere:
    //Modifica:
    int numElem();
private:
    Caja *primero;
    int cantElementos;
};
#endif //TP2_I_2018_DICCIONARIO_H
