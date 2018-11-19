//
//  main.c
//  POLINOMIOS
//
//  Created by Usuario on 28/08/18.
//  Copyright © 2018 Usuario. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodou Nodou;
struct Nodou{
    int coeficiente;
    int potencia;
    struct Nodou * siguiente;
};
Nodou * inicio1 = NULL;
Nodou * ultimo1 = NULL;
Nodou * inicio2 = NULL;
Nodou * ultimo2 = NULL;
Nodou * inicio = NULL;
Nodou * ultimo = NULL;
Nodou * inicior = NULL;
Nodou * ultimor = NULL;

void creareinsertar1(int coeficiente, int potencia);
void creareinsertar2(int coeficiente, int potencia);
Nodou * crear(int coeficiente, int potencia);
void ordenarpolinomio1();
void ordenarpolinomio2();
void suma();
void resta();
void imprimirresultado1();
void imprimirresultado2();
void imprimirresultado3();
void imprimirresultado4();
void simplificarpolinomio(Nodou ** inicio);
void simplificacion(Nodou ** aux1);
void suma();
void resta();
int main(int argc, const char * argv[]) {
    int coeficiente1, coeficiente2, potencia1, potencia2;
    int polinomios1, polinomios2;
    printf("Inserte el numero de terminos a ingresar: ");
    scanf("%d", &polinomios1);
    for(int i=0; i<polinomios1; i++){
        printf("Inserte coefinciente y potencia: ");
        scanf("%d %d", &coeficiente1, &potencia1);
        creareinsertar1(coeficiente1, potencia1);
    }
    printf("Inserte el numero de terminos a ingresar: ");
    scanf("%d", &polinomios2);
    for(int i=0; i<polinomios2; i++){
        printf("Inserte coefinciente y potencia: ");
        scanf("%d %d", &coeficiente2, &potencia2);
        creareinsertar2(coeficiente2, potencia2);
    }
    printf(" \n");
    imprimirresultado1();
    printf("\n\n");
    imprimirresultado2();
    printf("\n\n");
    ordenarpolinomio1();
    imprimirresultado3();
    printf("\n\n");
    ordenarpolinomio2();
    imprimirresultado4();
    printf("\n\n");
    simplificarpolinomio(&inicio1);
    imprimirresultado3();
    /*printf("\n\n");
    simplificarpolinomio(&inicio2);
    imprimirresultado4();
    printf("\n\n");*/
    return 0;
}
void creareinsertar1(int coeficiente, int potencia){
    Nodou *Nuevonodo=malloc(sizeof(Nodou));
    Nuevonodo->coeficiente=coeficiente;
    Nuevonodo->potencia=potencia;
    Nuevonodo->siguiente=NULL;
    Nodou *aux;
    if (inicio1==NULL){
        inicio1=Nuevonodo;
        ultimo1=Nuevonodo;
        aux=inicio1;
    }
    else{
        aux=inicio1;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
            ultimo1=aux;
        }
        aux->siguiente=Nuevonodo;
        ultimo1->siguiente=aux->siguiente;
        aux=Nuevonodo;
        ultimo1=aux;
    }
}
void creareinsertar2(int coeficiente, int potencia){
    Nodou *Nuevonodo=malloc(sizeof(Nodou));
    Nuevonodo->coeficiente=coeficiente;
    Nuevonodo->potencia=potencia;
    Nuevonodo->siguiente=NULL;
    Nodou *aux;
    if (inicio2==NULL){
        inicio2=Nuevonodo;
        ultimo2=Nuevonodo;
        aux=inicio2;
    }
    else{
        aux=inicio2;
        while(aux->siguiente!=NULL){
            aux=aux->siguiente;
            ultimo2=aux;
        }
        aux->siguiente=Nuevonodo;
        ultimo2->siguiente=aux->siguiente;
        aux=Nuevonodo;
        ultimo2=aux;
    }
}
void imprimirresultado1(){
    
    Nodou *aux=inicio1;
    while (aux!=NULL) {
        printf("%dx^%d ", aux->coeficiente, aux->potencia);
        aux=aux->siguiente;
    }
    
}
void imprimirresultado2(){
    
    Nodou *aux=inicio2;
    while (aux!=NULL) {
        printf("%dx^%d ", aux->coeficiente, aux->potencia);
        aux=aux->siguiente;
    }
    
}
void ordenarpolinomio1(){
    if(inicio1!=NULL){
        Nodou *PIVOTE=inicio1;
        Nodou *aux=PIVOTE;
        if (PIVOTE->siguiente==NULL){
            printf("La lista solo contiene un monomio\n");
        }
        else{
            int auxpotencia, auxcoeficiente;
            while(PIVOTE->siguiente!=NULL){
                while(aux->siguiente!=NULL){
                    aux=aux->siguiente;
                    if((PIVOTE->potencia) < (aux->potencia)){
                        auxpotencia=PIVOTE->potencia;
                        auxcoeficiente=PIVOTE->coeficiente;
                        PIVOTE->potencia=aux->potencia;
                        PIVOTE->coeficiente=aux->coeficiente;
                        aux->potencia=auxpotencia;
                        aux->coeficiente=auxcoeficiente;
                    }
                }
                PIVOTE=PIVOTE->siguiente;
                aux=PIVOTE;
            }
        }
    }
    else{
        printf("Lista vacia\n");
    }
}
void ordenarpolinomio2(){
    if(inicio2!=NULL){
        Nodou *PIVOTE=inicio2;
        Nodou *aux=PIVOTE;
        if (PIVOTE->siguiente==NULL){
            printf("La lista solo contiene un monomio\n");
        }
        else{
            int auxpotencia, auxcoeficiente;
            while(PIVOTE->siguiente!=NULL){
                while(aux->siguiente!=NULL){
                    aux=aux->siguiente;
                    if((PIVOTE->potencia) < (aux->potencia)){
                        auxpotencia=PIVOTE->potencia;
                        auxcoeficiente=PIVOTE->coeficiente;
                        PIVOTE->potencia=aux->potencia;
                        PIVOTE->coeficiente=aux->coeficiente;
                        aux->potencia=auxpotencia;
                        aux->coeficiente=auxcoeficiente;
                    }
                }
                PIVOTE=PIVOTE->siguiente;
                aux=PIVOTE;
            }
        }
    }
    else{
        printf("Lista vacia\n");
    }
}
void imprimirresultado3(){
    Nodou *aux=inicio1;
    while (aux!=NULL) {
        printf("%dx^%d ", aux->coeficiente, aux->potencia);
        aux=aux->siguiente;
    }
    
}
void imprimirresultado4(){
    Nodou *aux=inicio2;
    while (aux!=NULL) {
        printf("%dx^%d ", aux->coeficiente, aux->potencia);
        aux=aux->siguiente;
    }
    
}
void simplificarpolinomio(Nodou ** inicio){
    if(*inicio!=NULL){
        Nodou * aux1 = *inicio;
        while (aux1->siguiente!=NULL){
            simplificacion(&aux1);
            aux1=aux1->siguiente;
        }
    }
    else{
        printf("Lista vacia\n");
    }
}
void simplificacion(Nodou ** aux1){
    Nodou * aux2 = (*aux1)->siguiente;
    if (aux2->potencia == (*aux1)->potencia){
        (*aux1)->coeficiente=(*aux1)->coeficiente+aux2->coeficiente;
        (*aux1)->siguiente=aux2->siguiente;
        aux2->siguiente=NULL;
        free(aux2);
        simplificacion(&(*aux1));
    }
}
Nodou * crear(int coeficiente, int potencia){
    Nodou * nodo = malloc(sizeof(Nodou));
    nodo->coeficiente=coeficiente;
    nodo->potencia=potencia;
    nodo->siguiente=NULL;
    return nodo;
}
void suma(){
    Nodou * aux1=inicio1;
    Nodou * aux2=inicio2;
    int suma;
    while(aux1->siguiente!=NULL && aux2->siguiente!=NULL){
        if(aux1->potencia==aux2->potencia){
            suma=aux1->coeficiente+aux2->coeficiente;
            Nodou * Nuevonodo=crear(suma, aux2->potencia);
            if (inicio==NULL){
                inicio=Nuevonodo;
                ultimo=Nuevonodo;
            }
            else{
                Nodou * aux = inicio;
                while(aux->siguiente!=NULL){
                    aux=aux->siguiente;
                    ultimo=aux;
                }
                aux->siguiente=Nuevonodo;
                ultimo->siguiente=aux->siguiente;
                aux=Nuevonodo;
                ultimo=aux;
            }
        }
    }
}
void resta(){
    Nodou * aux1=inicio1;
    Nodou * aux2=inicio2;
    int resta;
    while(aux1->siguiente!=NULL && aux2->siguiente!=NULL){
        if(aux1->potencia==aux2->potencia){
            resta=aux1->coeficiente-aux2->coeficiente;
            Nodou * Nuevonodo=crear(resta, aux2->potencia);
            if (inicio==NULL){
                inicio=Nuevonodo;
                ultimo=Nuevonodo;
            }
            else{
                Nodou * aux = inicio;
                while(aux->siguiente!=NULL){
                    aux=aux->siguiente;
                    ultimo=aux;
                }
                aux->siguiente=Nuevonodo;
                ultimo->siguiente=aux->siguiente;
                aux=Nuevonodo;
                ultimo=aux;
            }
        }
    }
}
