#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Insertar al inicio
void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

// Recorrer la lista
void recorrer(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while(actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

// Eliminar un nodo con valor específico
void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    while(actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if(actual == NULL) {
        printf("Valor %d no encontrado\n", valor);
        return;
    }

    if(anterior == NULL) { // Eliminar cabeza
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
}

// Liberar memoria
void liberar(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while(actual != NULL) {
        struct Nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    printf("Memoria liberada correctamente\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    int n, valor;

    printf("¿Cuántos valores desea insertar? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }

    printf("Ingrese el valor a eliminar: ");
    scanf("%d", &valor);
    eliminar(&cabeza, valor);
    recorrer(cabeza);

    liberar(cabeza);
    return 0;
}

