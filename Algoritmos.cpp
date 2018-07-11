//
// Created by jimmy on 12/06/18.
//

#include "Algoritmos.h"


void Algoritmos::profundidadPrimero(grafo g) {
    if(!g.vacio()){
        dvv.crear();
        vert v = g.primerVertice();
        int num = 1;
        while(v != 0 && num <= g.numVertices()){
            if(!dvv.pertenece(v)) {
                profPrimeroRec(g, v);
            }
            v = g.sgtVertice(v);
            num++;
        }
        dvv.destruir();
        cout << "FIN" << endl;
    }
}

void Algoritmos::profPrimeroRec(grafo g, vert v) {
    dvv.agregar(v);
    cout << g.etiqueta(v) << " -> ";
    int tam = g.numVertices();
    int num = 0;
    vert va = g.primerVrtAdy(v);
    while(va != 0 && num < tam){
        if(!dvv.pertenece(va)){
            profPrimeroRec(g,va);
        }
        va = g.sgtVrtAdy(v, va);
        num++;
    }
}

void Algoritmos::dijkstra(grafo& g, vert o) {
    distanciaR.crear();
    int n = g.numVertices();
    vert v = g.primerVertice();
    int num = 0;
    while(v != 0 && num < n){
        if(v != o){
            if(g.existeArista(o,v)){
                distanciaR.agregarRelacion(v,g.peso(o,v));
            } else{
                distanciaR.agregarRelacion(v,999);
            }
        }
        num++;
        v = g.sgtVertice(v);
    }
    for(int i = 0; i< n;i++){
        previo[i] = 0;
    }

    vert listVrt[n+1];
    listVrt[1] = o;
    int cont = 2;
    v = g.primerVertice();
    num = 0;
    while(v != 0 && num < n){
        if(v != o){
            listVrt[cont] = v;
            cont++;
        }
        v = g.sgtVertice(v);
        num++;
    }

    distanciaR.agregarRelacion(o,0);
    dvv.crear();
    dvv.agregar(o);
    previo[1] = o;
    int pos = 2;
    while(dvv.numElem() != n){
        vert menor = minimo(g, o, dvv.numElem()+1);
        dvv.agregar(menor);
        vert w = g.primerVrtAdy(menor);
        num = 0;
        int nAdy = g.numVrtAdyacentes(w);
        while(w != 0 && num <= nAdy){
            if(distanciaR.imagen(w) > distanciaR.imagen(menor) + g.peso(menor,w)){
                distanciaR.modificarImagen(w, (distanciaR.imagen(menor) + g.peso(menor,w)));
                previo[pos] = menor;
                pos++;
            }
            w = g.sgtVrtAdy(menor,w);
            num++;
        }
    }


    cout << "Distancia desde origen (" << g.etiqueta(o) << ") a todos los vértices." << endl;
    for(int i = 1; i< n+1; i++) {
        string camino = "";
        int cont = i;
        bool listo = false;
        while(!listo && cont < n+1){
            if(std::stoi(g.etiqueta(previo[cont])) == cont){
                listo = true;
            } else{
                camino = camino + g.etiqueta(previo[cont]) + "<-";
                cont = std::stoi(g.etiqueta(previo[cont]));
            }
        }
        cout << "Etiqueta: " << g.etiqueta(listVrt[i]) << ". Distancia: " << distanciaR.imagen(listVrt[i]) << ". Camino: "
             << g.etiqueta(listVrt[i]) << "<-" << camino << g.etiqueta(o) << endl;
    }
    dvv.destruir();
    distanciaR.destruir();
}

vert Algoritmos::minimo(grafo g , vert o, int i) {
    vert menor = 0;
    int min = 999;
    vert w = g.primerVertice();
    int num = 0;
    while(w != 0 && num < g.numVertices()){
        if(w != o){
            if(!dvv.pertenece(w) && distanciaR.imagen(w) < min){
                min = distanciaR.imagen(w);
                menor = w;
            }
        }
        w = g.sgtVertice(w);
        num++;
    }

    return menor;
}

void Algoritmos::floyd(grafo& g) {
    int tamano = g.numVertices();
    int pesos[tamano][tamano];
    string caminos[tamano][tamano];
    vert indice = g.primerVertice();
    for (int i = 0; i < tamano; i++) {
        vert comp = g.primerVertice();
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
    indice = g.primerVertice();
    for (int k = 0; k < tamano; k++) {
        for (int i = 0; i < tamano; i++){
            for (int j = 0; j < tamano; j++){
                if (pesos[i][k] + pesos[k][j] < pesos[i][j]) {
                    pesos[i][j] = pesos[i][k] + pesos[k][j];
                    caminos[i][j] = g.etiqueta(indice);
                }
            }
        }
        indice = g.sgtVertice(indice);
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

bool Algoritmos::iguales(grafo &g1, grafo &g2) {
    bool sonIguales = true;
    if(g1.numVertices() != g2.numVertices()){
        sonIguales = false;
    } else{
        relacion1a1.crear();
        vert v1 = g1.primerVertice();
        while(v1 != 0 && sonIguales){
            vert v2 = g2.traduceVrt(g1.etiqueta(v1));
            if(v2 != 0){
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
            while(v1 != 0 && sonIguales){
                vert va1 = g1.primerVrtAdy(v1);
                while(va1 != 0 && sonIguales){
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

grafo Algoritmos::copiarGrafo(grafo& g1) {
    grafo g2;
    g2.crear();
    relacion1a1.crear();
    vert v1 = g1.primerVertice();
    int num = 0;
    while(v1 != 0 && num < g1.numVertices()){
        vert ad = g1.primerVrtAdy(v1);
        int nady = g1.numVrtAdyacentes(v1);
        int na = 0;
        g2.agregarVertice(g1.etiqueta(v1));
        while(ad != 0 && na < nady){
            relacion1a1.agregarRelacion(v1,ad);
            ad = g1.sgtVrtAdy(v1,ad);
            na++;
        }
        num++;
        v1 = g1.sgtVertice(v1);
    }
    v1 = g1.primerVertice();
    num = 0;
    while(v1 != 0 && num < g1.numVertices()){
        vert aux = g1.primerVertice();
        int num2 = 0;
        while(aux != 0 && num2 <g1.numVertices()) {
            if (relacion1a1.existeRelacion(v1, aux)) {
                g2.agregarArista(g2.traduceVrt(g2.etiqueta(v1)), g2.traduceVrt(g1.etiqueta(aux)), g1.peso(v1, aux));
            }
            aux = g1.sgtVertice(aux);
            num2++;
        }
        v1 = g1.sgtVertice(v1);
        num++;
    }
    return g2;
}

void Algoritmos::eliminarVertNoAislado(grafo& g, vert v) {
    vert aux = g.primerVertice();
    int num = 0;
    while(aux != 0 && num < g.numVertices()){
        if(aux != v){
            if(g.existeArista(aux,v)){
                g.eliminarArista(aux,v);
            }
        }
        num++;
        aux = g.sgtVertice(aux);
    }
    vert ad = g.primerVrtAdy(v);
    int na = 0;
    while(ad != 0 && na < g.numVrtAdyacentes(ad)){
        g.eliminarArista(v,ad);
        ad = g.sgtVrtAdy(v,ad);
        na++;
    }
    g.eliminarVertice(v);
}

void Algoritmos::hamilton(gnd &g) {
    int n = g.numVertices();
    vert* ruta = new vert[n];
    dvv.crear();
    numSolFact = 0;
    solOPtima = 999; //simula INF
    dvv.agregar(g.primerVertice());
    vert* rutaAct = hamiltonRec(g,g.primerVertice(), 0, ruta);
    delete[] ruta;
    if(rutaAct != 0){
        cout << g.etiqueta(g.primerVertice()) << "->";
        for (int i = 0; i < n - 1; i++) {
            cout << g.etiqueta(rutaAct[i]) << "->";
        }
        cout << g.etiqueta(g.primerVertice()) << endl;
        cout << "Peso Total: " << solOPtima << endl;
        cout << "Numero de soluciones factibles: " << numSolFact << endl;
    } else {
        cout << "No hay soluciones" << endl;
    }
    dvv.destruir();
}

vert* Algoritmos::hamiltonRec(gnd &g, vert v, int peso, vert* ruta) {
    vert* solucion = 0;
    if (dvv.numElem() == g.numVertices()) {
        if (!g.existeArista(v, g.primerVertice())) {
            return 0;
        } else {
            peso += g.peso(v, g.primerVertice());
            numSolFact++;
            if (peso < solOPtima) {
                const int n = g.numVertices();
                solucion = new vert[n];
                solOPtima = peso;
                for (int i = 0; i < n - 1; i++) {
                    solucion[i] = ruta[i];
                }
                solucion[n - 1] = g.primerVertice();
            }
            return solucion;
        }
    }
    vert ady = g.primerVrtAdy(v);
    while (ady != 0) {
        if (!dvv.pertenece(ady)) {
            dvv.agregar(ady);
            peso += g.peso(v, ady);
            ruta[dvv.numElem() - 2] = ady;
            vert* solP = hamiltonRec(g, ady, peso, ruta);
            if (solP != 0) {
                if (solucion != 0) {
                    delete[] solucion;
                }
                solucion = solP;
            }
            dvv.borrar(ady);
            peso -= g.peso(v, ady);
        }
        ady = g.sgtVrtAdy(v, ady);
    }
    return solucion;
}

int Algoritmos::menorArista(int aristas[], bool visitados[], int tam) {
    int min = 9999;
    int minInd;
    for(int i=0; i<tam; i++){
        if(visitados[i]==false&&aristas[i]<min){
            min = aristas[i];
            minInd = i;
        }
    }
    return minInd;
}

void Algoritmos::prim(gnd &g) {
    int tamano = g.numVertices();
    int pesos[tamano][tamano];
    vert vertices[tamano];
    vert comp;
    vert indice = g.primerVertice();
    //Hace una matriz de adyacencia con los pesos
    for (int i = 0; i < tamano; i++) {
        comp = g.primerVertice();
        for (int j = 0; j < tamano; j++) {
            if (g.existeArista(indice, comp)) {
                pesos[i][j] = g.peso(indice, comp);
            } else {
                pesos[i][j] = 9999;
            }
            comp = g.sgtVertice(comp);
        }
        vertices[i]=indice;
        indice = g.sgtVertice(indice);
    }

    int aristasPesos[tamano];
    bool visitados[tamano];
    //vert camino[tamano];
    int caminoInd[tamano];

    //Rellena los pesos y los visitados
    for (int i = 0; i < tamano; i++) {
        aristasPesos[i] = 9999;//Se pone 1000 en lugar del INF
        visitados[i] = false;
    }

    aristasPesos[0] = 0;
    //relacionPrim[0] = {0,0};
    //camino[0] = 0;
    caminoInd[0] = -1;
    int minimo;
    int cont = 0;
    for (int j = 0; j < tamano - 1; j++) {
        minimo = menorArista(aristasPesos, visitados, tamano);
        visitados[minimo] = true;
        cont = 0;
        for (int i = 0; i < tamano; i++) {
            if ((pesos[minimo][i]>0) && (visitados[i] == false) && (pesos[minimo][i]<aristasPesos[i])) {
                relacionPrim.push_back(make_pair(vertices[minimo],vertices[i]));
                caminoInd[i] = minimo;
                aristasPesos[i] = pesos[minimo][i];
            }
        }

    }

    printf("Edge   Weight\n");
    for (int i = 1; i < tamano; i++) {
        cout<< g.etiqueta(relacionPrim[i].first)<<"   -" <<g.etiqueta(relacionPrim[i].second)<<"  "<<pesos[i][caminoInd[i]]<<endl;
    }
}

