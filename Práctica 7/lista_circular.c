#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

struct Nodo *cabeza = NULL;
struct Nodo *ultimo = NULL;

// Insertar al inicio en lista circular
void insertarInicioCircular(int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if(cabeza == NULL) { // Lista vacía
        cabeza = nuevo;
        ultimo = nuevo;
        nuevo->siguiente = cabeza;
    } else {
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
        ultimo->siguiente = cabeza;
    }
}

// Recorrer lista circular
void recorrerCircular() {
    if(cabeza == NULL) {
        printf("Lista circular vacía\n");
        return;
    }

    struct Nodo *actual = cabeza;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while(actual != cabeza);
    printf("(vuelta a cabeza)\n");
}

// Eliminar un nodo en lista circular
void eliminarCircular(int valor) {
    if(cabeza == NULL) {
        printf("Lista vacía\n");
        return;
    }

    struct Nodo *actual = cabeza;
    struct Nodo *anterior = ultimo;
    int encontrado = 0;

    do {
        if(actual->dato == valor) {
            encontrado = 1;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while(actual != cabeza);

    if(!encontrado) {
        printf("Valor %d no encontrado\n", valor);
        return;
    }

    if(actual == cabeza) { // Eliminar cabeza
        cabeza = cabeza->siguiente;
        ultimo->siguiente = cabeza;
    } else if(actual == ultimo) { // Eliminar último
        anterior->siguiente = cabeza;
        ultimo = anterior;
    } else { // Nodo intermedio
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
}

int main() {
    int n, valor;

    printf("¿Cuántos valores desea insertar en la lista circular? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%d", &valor);
        insertarInicioCircular(valor);
        recorrerCircular();
    }

    printf("Ingrese el valor a eliminar: ");
    scanf("%d", &valor);
    eliminarCircular(valor);
    recorrerCircular();

    return 0;
}

