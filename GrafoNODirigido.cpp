//
// Created by jimmy on 30/06/18.
//

#include "GrafoNODirigido.h"

void GrafoNODirigido::crear() {
    g.crear();
}

void GrafoNODirigido::destruir() {
    g.destruir();
}

void GrafoNODirigido::vaciar() {
    g.vaciar();
}

bool GrafoNODirigido::vacio() {
    bool r = g.vacio();
    return r;
}

vert GrafoNODirigido::agregarVertice(string e) {
    vert nuevo = g.agregarVertice(e);
    nVertices++;
    return nuevo;
}

void GrafoNODirigido::eliminarVertice(vert v) {
    g.eliminarVertice(v);
}

void GrafoNODirigido::agregarArista(vert v1, vert v2, int p) {
    g.agregarArista(v1,v2,p);
    g.agregarArista(v2,v1,p);//la arista en dirección contraria
}

void GrafoNODirigido::eliminarArista(vert v1, vert v2) {
    g.eliminarArista(v1,v2);
    g.eliminarArista(v2,v1);
}

string GrafoNODirigido::etiqueta(vert v) {
    return g.etiqueta(v);
}

int GrafoNODirigido::peso(vert v1, vert v2) {
    return g.peso(v1,v2);
}

void GrafoNODirigido::modificarEtiqueta(vert v, string e) {
    g.modificarEtiqueta(v,e);
}

void GrafoNODirigido::modificarPeso(vert v1, vert v2, int p) {
    g.modificarPeso(v1,v2,p);
}

bool GrafoNODirigido::existeArista(vert v1, vert v2) {
    return g.existeArista(v1,v2);
}

vert GrafoNODirigido::primerVertice() {
    return g.primerVertice();
}

vert GrafoNODirigido::sgtVertice(vert v) {
    return g.sgtVertice(v);
}

vert GrafoNODirigido::primerVrtAdy(vert v) {
    return g.primerVrtAdy(v);
}

vert GrafoNODirigido::sgtVrtAdy(vert v, vert ad) {
    return g.sgtVrtAdy(v, ad);
}

vert GrafoNODirigido::traduceVrt(string e) {
    return g.traduceVrt(e);
}

int GrafoNODirigido::numVertices() {
    return nVertices;
}

int GrafoNODirigido::numVrtAdyacentes(vert v) {
    return v->numVrtAdy;
}
