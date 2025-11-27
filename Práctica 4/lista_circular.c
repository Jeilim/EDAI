#include <stdio.h>
#include <stdlib.h>

// Nodo de la lista circular
typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

// Crear nodo
Nodo* crearNodo(int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->sig = NULL;
    return nuevo;
}

// Insertar en la lista 
void insertarCircular(Nodo **head, int valor) {
    Nodo *nuevo = crearNodo(valor);

    if (*head == NULL) {  // lista vacía
        *head = nuevo;
        nuevo->sig = nuevo;  // apunta a sí mismo
        return;
    }

    Nodo *temp = *head;

    // avanzar hasta que temp -> sig = head
    while (temp->sig != *head) {
        temp = temp->sig;
    }

    temp->sig = nuevo;
    nuevo->sig = *head;
}

// Mostrar la lista circular
void imprimirCircular(Nodo *head) {
    if (head == NULL) {
        printf("\nLista circular vacía.\n");
        return;
    }

    Nodo *temp = head;
    printf("\nLista circular: ");
    do {
        printf("%d -> ", temp->dato);
        temp = temp->sig;
    } while (temp != head);

    printf("(regresa al inicio)\n");
}

// Liberar la memoria
void liberarCircular(Nodo *head) {
    if (head == NULL) return;

    Nodo *temp = head->sig;
    Nodo *sigNodo;

    while (temp != head) {
        sigNodo = temp->sig;
        free(temp);
        temp = sigNodo;
    }

    free(head);
}

int main() {
    Nodo *lista = NULL;
    int n, valor;

    printf("¿Cuántos valores agregaras a la lista circular? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarCircular(&lista, valor);
    }

    imprimirCircular(lista);

    liberarCircular(lista);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}

