//
//  main.c
//  Ej_Lista_Circular
//
//  Created by Francisco Árciga Nolasco on 30/10/18.
//  Copyright © 2018 Francisco Árciga Nolasco. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct LCIRCULAR LCIRCULAR;
struct LCIRCULAR{
    int dato;
    struct LCIRCULAR * siguiente;
};
LCIRCULAR * creadordenodos (int dato);
void insertarLista(LCIRCULAR ** inicio, int dato);
void insertarPorPosicion(LCIRCULAR ** inicio, int dato, int posicion);
void imprimirLista(LCIRCULAR ** inicio);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
LCIRCULAR * creadordenodos (int dato){
    LCIRCULAR * Nuevonodo = malloc(sizeof(LCIRCULAR));
    Nuevonodo->dato=dato;
    Nuevonodo->siguiente=NULL;
    return Nuevonodo;
}
void insertarLista(LCIRCULAR ** inicio, int dato){
    if (*inicio==NULL){
        LCIRCULAR * Nodo = creadordenodos(dato);
        *inicio=Nodo;
        (*inicio)->siguiente=(*inicio);
    }
    else{
        LCIRCULAR * aux = *inicio, *Nodo=creadordenodos(dato);
        while (aux->siguiente!=(*inicio)) {
            aux=aux->siguiente;
        }
        aux->siguiente=Nodo;
        aux=Nodo;
        aux->siguiente = *inicio;
    }
}
void insertarPorPosicion(LCIRCULAR ** inicio, int dato, int posicion){
    if (*inicio==NULL){
        printf("Lista vacia, no puede insertar el nodo por posición");
    }
    else{
        int i=1;
        LCIRCULAR * aux = *inicio, * Nodo = creadordenodos(dato);
        while (aux->siguiente!=(*inicio) && i<posicion-1) {
            aux=aux->siguiente;
            i++;
        }
        if (aux->siguiente==(*inicio)){
            printf("La posicion rebasa el tamanio de la lista");
        }
        else{
            Nodo->siguiente=aux->siguiente;
            aux->siguiente=Nodo;
        }
    }
}
void imprimirLista(LCIRCULAR ** inicio){
    printf("%d\t", (*inicio)->dato);
    LCIRCULAR * muesta = (*inicio)->siguiente;
    while (muesta!=(*inicio)){
        printf("%d \t", muesta->dato);
        muesta=muesta->siguiente;
    }
}
