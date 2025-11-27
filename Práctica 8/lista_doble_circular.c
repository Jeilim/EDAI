#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

struct Nodo *inicio = NULL;

// Insertar al final en lista doble circular
void insertarFinalCircular(int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if(inicio == NULL) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        inicio = nuevo;
        return;
    }

    struct Nodo *ultimo = inicio->anterior;

    nuevo->siguiente = inicio;
    nuevo->anterior = ultimo;
    ultimo->siguiente = nuevo;
    inicio->anterior = nuevo;
}

// Recorrer hacia adelante
void recorrerAdelanteCircular() {
    if(inicio == NULL) {
        printf("Lista circular vacía\n");
        return;
    }

    struct Nodo *actual = inicio;
    printf("Lista adelante: ");
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while(actual != inicio);
    printf("(vuelta a inicio)\n");
}

// Recorrer hacia atrás
void recorrerAtrasCircular() {
    if(inicio == NULL) return;
    struct Nodo *actual = inicio->anterior; // último nodo

    printf("Lista atrás: ");
    struct Nodo *fin = actual;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->anterior;
    } while(actual != fin);
    printf("(vuelta a inicio)\n");
}

// Eliminar nodo circular
void eliminarCircular(int valor) {
    if(inicio == NULL) return;

    struct Nodo *actual = inicio;
    int encontrado = 0;

    do {
        if(actual->dato == valor) {
            encontrado = 1;
            break;
        }
        actual = actual->siguiente;
    } while(actual != inicio);

    if(!encontrado) {
        printf("Valor %d no encontrado\n", valor);
        return;
    }

    if(actual->siguiente == actual) { // único nodo
        free(actual);
        inicio = NULL;
        return;
    }

    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;

    if(actual == inicio)
        inicio = actual->siguiente;

    free(actual);
}

// Liberar lista circular
void liberarCircular() {
    if(inicio == NULL) return;
    struct Nodo *actual = inicio->siguiente;
    while(actual != inicio) {
        struct Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    free(inicio);
    inicio = NULL;
    printf("Memoria liberada correctamente.\n");
}

int main() {
    int n, valor;

    printf("Cuántos valores insertar al final: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarFinalCircular(valor);
        recorrerAdelanteCircular();
    }

    printf("Lista hacia atrás:\n");
    recorrerAtrasCircular();

    printf("Ingrese valor a eliminar: ");
    scanf("%d", &valor);
    eliminarCircular(valor);
    recorrerAdelanteCircular();
    recorrerAtrasCircular();

    liberarCircular();
    return 0;
}

