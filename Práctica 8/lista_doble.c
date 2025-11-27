#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

// Insertar al inicio
void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = *inicio;

    if(*inicio != NULL)
        (*inicio)->anterior = nuevo;
    *inicio = nuevo;
}

// Insertar al final
void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if(*inicio == NULL) {
        nuevo->anterior = NULL;
        *inicio = nuevo;
        return;
    }

    struct Nodo *actual = *inicio;
    while(actual->siguiente != NULL)
        actual = actual->siguiente;

    actual->siguiente = nuevo;
    nuevo->anterior = actual;
}

// Recorrer hacia adelante
void recorrerAdelante(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    printf("Lista adelante: ");
    while(actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Recorrer hacia atrás
void recorrerAtras(struct Nodo *inicio) {
    if(inicio == NULL) return;
    struct Nodo *actual = inicio;
    while(actual->siguiente != NULL)
        actual = actual->siguiente;

    printf("Lista atrás: ");
    while(actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->anterior;
    }
    printf("NULL\n");
}

// Eliminar un nodo
void eliminar(struct Nodo **inicio, int valor) {
    struct Nodo *actual = *inicio;

    while(actual != NULL && actual->dato != valor)
        actual = actual->siguiente;

    if(actual == NULL) {
        printf("Valor %d no encontrado\n", valor);
        return;
    }

    if(actual->anterior != NULL)
        actual->anterior->siguiente = actual->siguiente;
    else
        *inicio = actual->siguiente;

    if(actual->siguiente != NULL)
        actual->siguiente->anterior = actual->anterior;

    free(actual);
}

// Liberar memoria
void liberar(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    while(actual != NULL) {
        struct Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    printf("Memoria liberada correctamente.\n");
}

// Programa principal
int main() {
    struct Nodo *inicio = NULL;
    int n, valor;

    printf("Cuántos valores insertar al inicio: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
        recorrerAdelante(inicio);
    }

    printf("Cuántos valores insertar al final: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
        recorrerAdelante(inicio);
    }

    printf("Lista hacia atrás:\n");
    recorrerAtras(inicio);

    printf("Ingrese valor a eliminar: ");
    scanf("%d", &valor);
    eliminar(&inicio, valor);
    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    liberar(inicio);
    return 0;
}

