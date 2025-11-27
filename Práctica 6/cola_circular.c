//Inicialización
#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size;
} ColaCircular;

void inicializarCola(ColaCircular *c) {
    c->frente = 0;
    c->final = 0;
    c->size = 0;
    printf("Cola circular inicializada\n");
}

//Operaciones
int isEmpty(ColaCircular *c) {
    return c->size == 0;
}

int isFull(ColaCircular *c) {
    return c->size == MAX;
}

void enqueue(ColaCircular *c, int valor) {
    if(isFull(c)) {
        printf("Error: cola llena, no se puede encolar %d\n", valor);
        return;
    }
    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;
    c->size++;
}

int dequeue(ColaCircular *c) {
    if(isEmpty(c)) {
        printf("Error: cola vacía, no se puede desencolar\n");
        return -1;
    }
    int valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;
    return valor;
}

int peek(ColaCircular *c) {
    if(isEmpty(c)) {
        printf("Cola vacía\n");
        return -1;
    }
    return c->datos[c->frente];
}

void printQueue(ColaCircular *c) {
    printf("Cola: ");
    for(int i = 0; i < c->size; i++) {
        int index = (c->frente + i) % MAX;
        printf("%d ", c->datos[index]);
    }
    printf("\n");
}
//Pruebas
int main() {
    ColaCircular cola;
    inicializarCola(&cola);

    // Encolar 5, 10, 15
    enqueue(&cola, 5);
    enqueue(&cola, 10);
    enqueue(&cola, 15);
    printQueue(&cola);

    // Desencolar uno
    dequeue(&cola);
    printQueue(&cola);

    // Encolar 20, 25, 30
    enqueue(&cola, 20);
    enqueue(&cola, 25);
    enqueue(&cola, 30);
    printQueue(&cola);

    return 0;
}
