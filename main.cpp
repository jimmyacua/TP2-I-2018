//
// Created by jimmy on 10/06/18.
//

#include "Relacion1a1.h"
//#include "GrafoDirigListAdy.h"
#include "Algoritmos.h"
#include "GrafoNODirigido.h"

typedef ListaAdyacencia gd;
//typedef GrafoMatriz gd;

int main(){

    GrafoNODirigido gnd;
    gnd.crear();
    gnd.agregarVertice("e");
    gnd.agregarVertice("d");
    gnd.agregarVertice("c");
    gnd.agregarVertice("b");
    gnd.agregarVertice("a");
    gnd.agregarArista(gnd.traduceVrt("a"),gnd.traduceVrt("b"), 3);
    gnd.agregarArista(gnd.traduceVrt("a"),gnd.traduceVrt("c"), 4);
    gnd.agregarArista(gnd.traduceVrt("a"),gnd.traduceVrt("d"), 2);
    gnd.agregarArista(gnd.traduceVrt("a"),gnd.traduceVrt("e"), 7);
    gnd.agregarArista(gnd.traduceVrt("b"),gnd.traduceVrt("c"), 4);
    gnd.agregarArista(gnd.traduceVrt("b"),gnd.traduceVrt("d"), 6); //grafo visto en clase
    gnd.agregarArista(gnd.traduceVrt("b"),gnd.traduceVrt("e"), 3);
    gnd.agregarArista(gnd.traduceVrt("c"),gnd.traduceVrt("d"), 5);
    gnd.agregarArista(gnd.traduceVrt("c"),gnd.traduceVrt("e"), 8);
    gnd.agregarArista(gnd.traduceVrt("d"),gnd.traduceVrt("e"), 6);


    gd GD;
    GD.crear();
    GD.agregarVertice("5");
    GD.agregarVertice("4");
    GD.agregarVertice("3");
    GD.agregarVertice("2");
    GD.agregarVertice("1");
    GD.agregarArista(GD.traduceVrt("1"), GD.traduceVrt("2"), 10);
    GD.agregarArista(GD.traduceVrt("1"), GD.traduceVrt("4"), 30);
    GD.agregarArista(GD.traduceVrt("1"), GD.traduceVrt("5"), 100);
    GD.agregarArista(GD.traduceVrt("2"), GD.traduceVrt("3"), 50); //grafo del libro
    GD.agregarArista(GD.traduceVrt("3"), GD.traduceVrt("5"), 10);
    GD.agregarArista(GD.traduceVrt("4"), GD.traduceVrt("3"), 20);
    GD.agregarArista(GD.traduceVrt("4"), GD.traduceVrt("5"), 60);

    gd copia;
    copia.crear();

    Algoritmos algoritmos;

    bool continuar = true;
    while (continuar) {
        int desicion;
        cout << "Se le dará un grafo dirigido y uno NO dirigido para facilidad y agilizar el proceso, puede modificarlos en cualquier momento." << endl;
        cout << "Qué estructura de datos desea utilizar?" << endl;
        cout << " 1. Grafo Dirigido." << endl;
        cout << " 2. Grafo NO Dirigido." << endl;
        cout << " 3. Algoritmos." << endl;
        cout << " 0. Salir." << endl;
        cout << " Ingrese un número válido: ";
        cin >> desicion;

        switch (desicion) {
            case 1:
            {
                bool seguir = true;
                int op;
                while (seguir) {
                    cout << "   Qué desea hacer?" << endl;
                    cout << "       1. Destruir." << endl;
                    cout << "       2. Vaciar." << endl;
                    cout << "       3. Averiguar si esta vacio." << endl;
                    cout << "       4. Agregar un vertice." << endl;
                    cout << "       5. Eliminar un vertice." << endl;
                    cout << "       6. Modificar la etiqueta de un vertice." << endl;
                    cout << "       7. Agregar un arista." << endl;
                    cout << "       8. Eliminar una arista." << endl;
                    cout << "       9. Modificar un peso." << endl;
                    cout << "       10. Averiguar el peso de un arista." << endl;
                    cout << "       11. Averiguar si dos vertices son adyacentes." << endl;
                    cout << "       12. Averiguar cual es el primer vertice." << endl;
                    cout << "       13. Averiguar el siguiente vertice." << endl;
                    cout << "       14. Averiguar el primer vertice adyacente." << endl;
                    cout << "       15. Averiguar el siguiente vertice adyacente." << endl;
                    cout << "       16. Averiguar el numero de vertices del grafo." << endl;
                    cout << "       0. Salir." << endl;
                    cout << "   Ingrese el número correspondiente: ";
                    cin >> op;
                    switch (op) {
                        case 1:
                        {
                            GD.destruir();
                        }
                        break;
                        case 2:
                        {
                            GD.vaciar();
                        }
                        break;
                        case 3:
                        {
                            GD.vacio() ? cout << "          Grafo Vacio.\n" : cout << "         Grafo no vacio.\n";
                        }
                        break;
                        case 4:
                        {
                            string s;
                            cout << "ingrese la etiqueta del nuevo vertice ";
                            cin >> s;
                            GD.agregarVertice(s);
                        }
                        break;
                        case 5:
                        {
                            string s;
                            cout << "           Ingrese la etiqueta del vertice a eliminar: ";
                            cin >> s;
                            GD.eliminarVertice(GD.traduceVrt(s));
                        }
                        break;
                        case 6:
                        {
                            string ver;
                            cout << "           Ingrese la etiqueta del vertice que desea modificar: ";
                            cin >> ver;
                            string etq;
                            cout << "           Ingrese la nueva etiqueta del vertice: ";
                            cin >> etq;
                            GD.modificarEtiqueta(GD.traduceVrt(ver), etq);
                        }
                        break;
                        case 7:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            int p;
                            cout << "           Ingrese el peso del arista: ";
                            cin >> p;
                            GD.agregarArista(GD.traduceVrt(ver),GD.traduceVrt(ver2),p);
                        }
                        break;
                        case 8:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            GD.eliminarArista(GD.traduceVrt(ver),GD.traduceVrt(ver2));
                        }
                        break;
                        case 9:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            int p;
                            cout << "           Ingrese el nuevo peso del arista: ";
                            cin >> p;
                            GD.modificarPeso(GD.traduceVrt(ver),GD.traduceVrt(ver2),p);
                        }
                        break;
                        case 10:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            cout << "           El peso del arista es: " << GD.peso(GD.traduceVrt(ver),GD.traduceVrt(ver2)) << endl;
                        }
                        break;
                        case 11:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            if(GD.existeArista(GD.traduceVrt(ver),GD.traduceVrt(ver2))){
                                cout << "           Vertices adyacentes." << endl;
                            } else{
                                cout << "           Vertices no adyacentes." << endl;
                            }
                        }
                        break;
                        case 12:
                        {
                            cout << "           El primer vertice es: " << GD.etiqueta(GD.primerVertice()) << endl;
                        }
                        break;
                        case 13:
                        {
                            //siguiente vertice
                            string ver;
                            cout << "           Ingrese el vertice: ";
                            cin >> ver;
                            cout << "           El siguiente vertice es " << GD.etiqueta(GD.sgtVertice(GD.traduceVrt(ver))) << endl;
                        }
                        break;
                        case 14:
                        {
                            //primer vertice adyacente
                            string ver;
                            cout << "           Ingrese el vertice: ";
                            cin >> ver;
                            cout << "           El primer vertice adyacente es " << GD.etiqueta(GD.primerVrtAdy(GD.traduceVrt(ver))) << endl;
                        }
                        break;
                        case 15:
                        {
                            //siguiente vertice adyacente
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            cout << "          El siguiente vertice adyacente de " << ver << " y distinto a " << ver2 << "es " << GD.etiqueta(GD.sgtVrtAdy(GD.traduceVrt(ver), GD.traduceVrt(ver2)))  << endl;
                        }
                        break;
                        case 16:
                        {
                            //num vertices
                            cout << "El grafo posee actualmente  " << GD.numVertices() << " vertices." << endl;
                        }
                        break;
                        case 0:
                        {
                            seguir = false;
                        }
                        break;
                        default:
                        {
                            cout << "   INGRESE UN NUMERO VALIDO\n" << endl;
                        }
                        break;
                    }
                }
            }
            break;
            case 2:
            {
                bool seguir = true;
                int op;
                while (seguir) {
                    cout << "   Qué desea hacer?" << endl;
                    cout << "       1. Destruir." << endl;
                    cout << "       2. Vaciar." << endl;
                    cout << "       3. Averiguar si esta vacio." << endl;
                    cout << "       4. Agregar un vertice." << endl;
                    cout << "       5. Eliminar un vertice." << endl;
                    cout << "       6. Modificar la etiqueta de un vertice." << endl;
                    cout << "       7. Agregar un arista." << endl;
                    cout << "       8. Eliminar una arista." << endl;
                    cout << "       9. Modificar un peso." << endl;
                    cout << "       10. Averiguar el peso de un arista." << endl;
                    cout << "       11. Averiguar si dos vertices son adyacentes." << endl;
                    cout << "       12. Averiguar cual es el primer vertice." << endl;
                    cout << "       13. Averiguar el siguiente vertice." << endl;
                    cout << "       14. Averiguar el primer vertice adyacente." << endl;
                    cout << "       15. Averiguar el siguiente vertice adyacente." << endl;
                    cout << "       16. Averiguar el numero de vertices del grafo." << endl;
                    cout << "       0. Salir." << endl;
                    cout << "   Ingrese el número correspondiente: ";
                    cin >> op;
                    switch (op) {
                        case 1:
                        {
                            gnd.destruir();
                        }
                        break;
                        case 2:
                        {
                            gnd.vaciar();
                        }
                       break;
                        case 3:
                        {
                            gnd.vacio() ? cout << "          Grafo Vacio.\n" : cout << "         Grafo no vacio.\n";
                       }
                        break;
                        case 4:
                        {
                            string s;
                            cout << "ingrese la etiqueta del nuevo vertice ";
                            cin >> s;
                            gnd.agregarVertice(s);
                        }
                        break;
                        case 5:
                        {
                            string s;
                            cout << "           Ingrese la etiqueta del vertice a eliminar: ";
                            cin >> s;
                            gnd.eliminarVertice(gnd.traduceVrt(s));
                        }
                        break;
                        case 6:
                        {
                            string ver;
                            cout << "           Ingrese la etiqueta del vertice que desea modificar: ";
                            cin >> ver;
                            string etq;
                            cout << "           Ingrese la nueva etiqueta del vertice: ";
                            cin >> etq;
                            gnd.modificarEtiqueta(gnd.traduceVrt(ver), etq);
                        }
                        break;
                        case 7:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            int p;
                            cout << "           Ingrese el peso del arista: ";
                            cin >> p;
                            gnd.agregarArista(gnd.traduceVrt(ver),gnd.traduceVrt(ver2),p);
                        }
                        break;
                        case 8:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            gnd.eliminarArista(gnd.traduceVrt(ver),gnd.traduceVrt(ver2));
                        }
                        break;
                        case 9:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            int p;
                            cout << "           Ingrese el nuevo peso del arista: ";
                            cin >> p;
                            gnd.modificarPeso(gnd.traduceVrt(ver),gnd.traduceVrt(ver2),p);
                        }
                        break;
                        case 10:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            cout << "           El peso del arista es: " << gnd.peso(gnd.traduceVrt(ver),gnd.traduceVrt(ver2)) << endl;
                        }
                        break;
                        case 11:
                        {
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            if(gnd.existeArista(gnd.traduceVrt(ver),gnd.traduceVrt(ver2))){
                                cout << "           Vertices adyacentes." << endl;
                            } else{
                                cout << "           Vertices no adyacentes." << endl;
                            }
                        }
                        break;
                        case 12:
                        {
                           cout << "           El primer vertice es: " << gnd.etiqueta(gnd.primerVertice()) << endl;
                        }
                        break;
                        case 13:
                        {
                            //siguiente vertice
                            string ver;
                           cout << "           Ingrese el vertice: ";
                            cin >> ver;
                            cout << "           El siguiente vertice es " << gnd.etiqueta(gnd.sgtVertice(gnd.traduceVrt(ver))) << endl;
                        }
                        break;
                        case 14:
                        {
                            //primer vertice adyacente
                            string ver;
                            cout << "           Ingrese el vertice: ";
                            cin >> ver;
                            cout << "           El primer vertice adyacente es " << gnd.etiqueta(gnd.primerVrtAdy(gnd.traduceVrt(ver))) << endl;
                        }
                        break;
                        case 15:
                        {
                            //siguiente vertice adyacente
                            string ver;
                            cout << "           Ingrese el primer vertice: ";
                            cin >> ver;
                            string ver2;
                            cout << "           Ingrese el segundo vertice: ";
                            cin >> ver2;
                            cout << "          El siguiente vertice adyacente de " << ver << " y distinto a " << ver2 << "es " << gnd.etiqueta(gnd.sgtVrtAdy(gnd.traduceVrt(ver), gnd.traduceVrt(ver2)))  << endl;
                        }
                        break;
                        case 16:
                        {
                            //num vertices
                            cout << "El grafo posee actualmente  " << gnd.numVertices() << " vertices." << endl;
                        }
                        break;
                        case 0:
                        {
                            seguir = false;
                        }
                        break;
                        default:
                        {
                            cout << "   INGRESE UN NUMERO VALIDO\n" << endl;
                        }
                        break;
                    }
                }
            }
            break;
            case 3:
            {
                bool seguir = true;
                int op;
                while (seguir) {
                    cout << "   Qué desea hacer?" << endl;
                    cout << "       1. Dijkstra.(GD)" << endl;
                    cout << "       2. Floyd.(GD)" << endl;
                    cout << "       3. Profundidad Primero.(GD)" << endl;
                    cout << "       4. Eliminar vertice no aislado.(GD)" << endl;
                    cout << "       5. Copiar grafo.(GD)" << endl;
                    cout << "       6. Averiguar si dos grafos son iguales.(GD)" << endl;
                    cout << "       7. Prim.(GND)" << endl;
                    cout << "       8. Problema del vendedor(GND)." << endl;
                    cout << "       0. Salir." << endl;
                    cout << "   Ingrese el número correspondiente: ";
                    cin >> op;
                    switch (op) {
                        case 1: {
                            string v;
                            cout << "Digite el vertice de origen" << endl;
                            cin >> v;
                            algoritmos.dijkstra(GD, GD.traduceVrt(v));
                        }
                            break;
                        case 2: {
                            algoritmos.floyd(GD);
                        }
                            break;
                        case 3: {
                            algoritmos.profundidadPrimero(GD);
                        }
                            break;
                        case 4: {
                            string v;
                            cout << "Digite el vertice a eliminar" << endl;
                            cin >> v;
                            algoritmos.eliminarVertNoAislado(GD, GD.traduceVrt(v));
                        }
                            break;
                        case 5:
                        {
                            copia = algoritmos.copiarGrafo(GD);
                        }
                            break;
                        case 6:{
                            cout << "¿Desea crear un grafo nuevo o usar el grafo 'copia' que se crea con el algoritmo Copiar?" << endl;
                            int dec;
                            cout << "1. Crear un grafo nuevo" << endl;
                            cout << "2. Usar el grafo copia (debe haber llamado al metodo Copiar antes) " << endl;
                            cin >> dec;
                            if(dec == 1){
                                bool listo = false;
                                gd nuevo;
                                nuevo.crear();
                                int op;
                                while(!listo){
                                    cout << "   Qué desea hacer?" << endl;
                                    cout << "       1. Agregar un vertice." << endl;
                                    cout << "       2. Eliminar un vertice." << endl;
                                    cout << "       3. Agregar un arista." << endl;
                                    cout << "       4. Eliminar una arista." << endl;
                                    cout << "       0. Terminar de construir grafo." << endl;
                                    cout << "   Ingrese el número correspondiente: ";
                                    cin >> op;
                                    switch(op){
                                        case 1:{
                                            string s;
                                            cout << "ingrese la etiqueta del nuevo vertice ";
                                            cin >> s;
                                            nuevo.agregarVertice(s);
                                        }
                                            break;
                                        case 2:{
                                            string s;
                                            cout << "ingrese la etiqueta del vertice a eliminar ";
                                            cin >> s;
                                           nuevo.eliminarVertice(nuevo.traduceVrt(s));
                                        }
                                            break;
                                        case 3:{
                                            string ver;
                                            cout << "           Ingrese el primer vertice: ";
                                            cin >> ver;
                                            string ver2;
                                            cout << "           Ingrese el segundo vertice: ";
                                            cin >> ver2;
                                            int p;
                                            cout << "           Ingrese el peso del arista: ";
                                            cin >> p;
                                            nuevo.agregarArista(nuevo.traduceVrt(ver),nuevo.traduceVrt(ver2),p);
                                        }
                                            break;
                                        case 4:{
                                            string ver;
                                            cout << "           Ingrese el primer vertice: ";
                                            cin >> ver;
                                            string ver2;
                                            cout << "           Ingrese el segundo vertice: ";
                                            cin >> ver2;
                                            nuevo.eliminarArista(nuevo.traduceVrt(ver),nuevo.traduceVrt(ver2));
                                        }
                                            break;
                                        case 0:{
                                            listo = true;
                                        }
                                            break;
                                    }
                                }
                                bool r = algoritmos.iguales(GD, nuevo);
                                if(r){
                                    cout << "Son iguales" << endl;
                                } else{
                                    cout << "NO son iguales" << endl;
                                }
                            }
                            else{
                                bool r = algoritmos.iguales(GD, copia);
                                if(r){
                                    cout << "Son iguales" << endl;
                                } else{
                                    cout << "NO son iguales" << endl;
                                }
                            }
                        }
                            break;
                        case 7:
                        {
                            algoritmos.prim(gnd);
                        }
                            break;
                        case 8:{
                            algoritmos.hamilton(gnd);
                        }
                            break;
                        case 0:{
                            seguir = false;
                        }
                            break;
                    }
                }
            }
                break;
            case 0:
            {
                continuar = false;
            }
            break;
            default:
            {
                cout << "   INGRESE UN NUMERO VALIDO\n" << endl;
            }
            break;
        }
  }


    return 0;
}