//
// Created by jimmy on 12/06/18.
//

#include "Algoritmos.h"


void Algoritmos::profundidadPrimero(grafo g) {
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

void Algoritmos::profPrimeroRec(grafo g, vertice v) {
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

void Algoritmos::dijkstra(grafo& g, vertice o) {
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

void Algoritmos::floyd(grafo& g) {
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

void Algoritmos::menor(vertice actual, int pos, vertice ad, int posAd ,int peso) {
    if(distancia[pos]+peso < distancia[posAd]){
        distancia[posAd] = peso;
        previo[posAd] = actual;
        Q.push(Node(ad,distancia[posAd]));
    }
}

bool Algoritmos::iguales(grafo &g1, grafo &g2) {
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

grafo Algoritmos::copiarGrafo(grafo g1) {
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

void Algoritmos::eliminarVertNoAislado(grafo& g, vertice v) {
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

void Algoritmos::hamilton(gnd &g) {
    int n = g.numVertices();
    vertice* ruta = new vertice[n];
    dvv.crear();
    numSolFact = 0;
    solOPtima = 999; //simula INF
    dvv.agregar(g.primerVertice());
    vertice* rutaAct = hamiltonRec(g,g.primerVertice(), 0, ruta);
    delete[] ruta;
    if(rutaAct != NULL){
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

vertice* Algoritmos::hamiltonRec(gnd &g, vertice v, int peso, vertice* ruta) {
    vertice* solucion = 0;
    if (dvv.numElem() == g.numVertices()) {
        if (!g.existeArista(v, g.primerVertice())) {
            return 0;
        } else {
            peso += g.peso(v, g.primerVertice());
            numSolFact++;
            if (peso < solOPtima) {
                const int n = g.numVertices();
                solucion = new vertice[n];
                solOPtima = peso;
                for (int i = 0; i < n - 1; i++) {
                    solucion[i] = ruta[i];
                }
                solucion[n - 1] = g.primerVertice();
            }
            return solucion;
        }
    }
    vertice ady = g.primerVrtAdy(v);
    while (ady != 0) {
        if (!dvv.pertenece(ady)) {
            dvv.agregar(ady);
            peso += g.peso(v, ady);
            ruta[dvv.numElem() - 2] = ady;
            vertice* solP = hamiltonRec(g, ady, peso, ruta);
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
    //return sol;
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

void Algoritmos::prim(grafo &g) {
    int tamano = g.numVertices();
    int pesos[tamano][tamano];
    vertice vertices[tamano];
    vertice comp;
    vertice indice = g.primerVertice();
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
    vertice camino[tamano];
    int caminoInd[tamano];

    //Rellena los pesos y los visitados
    for (int i = 0; i < tamano; i++) {
        aristasPesos[i] = 9999;//Se pone 1000 en lugar del INF
        visitados[i] = false;
    }

    aristasPesos[0] = 0;
    camino[0] = NULL;
    caminoInd[0] = -1;
    int minimo;

    for (int j = 0; j < tamano - 1; j++) {
        minimo = menorArista(aristasPesos, visitados, tamano);
        visitados[minimo] = true;
        for (int i = 0; i < tamano; i++) {
            if ((pesos[minimo][i]>0) && (visitados[i] == false) && (pesos[minimo][i]<aristasPesos[i])) {
                camino[i] = vertices[minimo];
                caminoInd[i] = minimo;
                aristasPesos[i] = pesos[minimo][i];

            }
        }

    }

    printf("Edge   Weight\n");
    for (int i = 1; i < tamano; i++) {
        printf("%d - %d    %d \n", camino[i]->etiqueta, i, pesos[i][caminoInd[i]]);
    }

}