#include <stdio.h> //librerias 
#include <stdlib.h>

// Nodo de la lista simple enlazada
typedef struct Nodo {
    int dato;
    struct Nodo *sig;
} Nodo;

// Crear un nodo
Nodo* crearNodo(int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->sig = NULL;
    return nuevo;
}

// Insertar al final
void insertarFinal(Nodo **head, int valor) {
    Nodo *nuevo = crearNodo(valor);

    if (*head == NULL) {  // lista vacía
        *head = nuevo;
        return;
    }

    Nodo *temp = *head;
    while (temp->sig != NULL) {
        temp = temp->sig;
    }
    temp->sig = nuevo;
}

// Para mostrar la lista
void imprimirLista(Nodo *head) {
    Nodo *temp = head;
    printf("\nLista simple: ");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->sig;
    }
    printf("NULL\n");
}

// Liberar la memoria
void liberarLista(Nodo *head) {
    Nodo *temp;
    while (head != NULL) {
        temp = head;
        head = head->sig;
        free(temp);
    }
}

int main() {
    Nodo *lista = NULL;
    int n, valor;

    printf("¿Cuántos valores agregas a la lista simple? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&lista, valor);
    }

    imprimirLista(lista);

    liberarLista(lista);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}

