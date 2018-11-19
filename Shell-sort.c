//
//  main.c
//  Ej_de_Lista_Doble
//
//  Created by Francisco Árciga Nolasco on 29/10/18.
//  Copyright © 2018 Francisco Árciga Nolasco. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Lista Lista;
struct Lista{
    int numero;
    struct Lista * siguiente;
    struct Lista * anterior;
};
Lista * inicio1 = NULL;
Lista * inicio2 = NULL;
Lista * Crear(int dato);
void InsertarLista(Lista ** inicio, int dato);
void ImprimirLista(Lista ** inicio);
int ComList(int total1, int total2);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
Lista * Crear (int dato){
    Lista * Nuevo = malloc(sizeof(Lista));
    Nuevo->numero=dato;
    Nuevo->siguiente=NULL;
    Nuevo->anterior=NULL;
    return Nuevo;
}
void InsertarLista(Lista ** inicio, int dato){
    Lista * aux, * Nuevonodo=Crear(dato);
    if (*inicio==NULL){
        *inicio=Nuevonodo;
    }
    else{
        aux = (*inicio);
        while (aux->siguiente!=NULL) {
            aux=aux->siguiente;
        }
        aux->siguiente=Nuevonodo;
        Nuevonodo->anterior=aux;
    }
}
int ComList(int total1, int total2){
    if (total1==total2){
        int i, suma=0;
        Lista * aux1 = inicio1;
        Lista * aux2 = inicio2;
        for (i=0; i<total2; i++){
            if (aux1->numero==aux2->numero){
                suma++;
            }
            aux1=aux1->siguiente;
            aux2=aux2->siguiente;
        }
        if (suma==total1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}
void ImprimirLista(Lista ** inicio){
    if (*inicio==NULL){
        printf("Lista Vacia");
    }
    else{
        Lista * corredor = *inicio;
        while (corredor!=NULL) {
            printf("%d ", corredor->numero);
            corredor=corredor->siguiente;
        }
    }
}
