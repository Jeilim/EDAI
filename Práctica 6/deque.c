//Inicialización
#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int front;
    int size;
} Deque;

void inicializarDeque(Deque *d) {
    d->front = 0;
    d->size = 0;
    printf("Deque inicializado\n");
}

//Operaciones 
int isEmptyDeque(Deque *d) {
    return d->size == 0;
}

int isFullDeque(Deque *d) {
    return d->size == MAX;
}

int rearIndex(Deque *d) {
    return (d->front + d->size - 1) % MAX;
}

void insert_front(Deque *d, int valor) {
    if(isFullDeque(d)) {
        printf("Deque lleno, no se puede insertar %d\n", valor);
        return;
    }
    d->front = (d->front - 1 + MAX) % MAX;
    d->datos[d->front] = valor;
    d->size++;
}

void insert_rear(Deque *d, int valor) {
    if(isFullDeque(d)) {
        printf("Deque lleno, no se puede insertar %d\n", valor);
        return;
    }
    int r = rearIndex(d);
    int nuevo = (r + 1) % MAX;
    d->datos[nuevo] = valor;
    d->size++;
}

int delete_front(Deque *d) {
    if(isEmptyDeque(d)) {
        printf("Deque vacío, no se puede eliminar\n");
        return -1;
    }
    int valor = d->datos[d->front];
    d->front = (d->front + 1) % MAX;
    d->size--;
    return valor;
}

int delete_rear(Deque *d) {
    if(isEmptyDeque(d)) {
        printf("Deque vacío, no se puede eliminar\n");
        return -1;
    }
    int r = rearIndex(d);
    int valor = d->datos[r];
    d->size--;
    return valor;
}

int peek_front(Deque *d) {
    if(isEmptyDeque(d)) return -1;
    return d->datos[d->front];
}

int peek_rear(Deque *d) {
    if(isEmptyDeque(d)) return -1;
    return d->datos[rearIndex(d)];
}

void printDeque(Deque *d) {
    printf("Deque: ");
    for(int i = 0; i < d->size; i++) {
        int index = (d->front + i) % MAX;
        printf("%d ", d->datos[index]);
    }
    printf("\nFront: %d, Rear: %d\n", d->front, rearIndex(d));
}

//Pruebas
int main() {
    Deque d;
    inicializarDeque(&d);

    insert_front(&d, 10);
    insert_rear(&d, 15);
    insert_rear(&d, 20);
    insert_front(&d, 30);
    insert_rear(&d, 40);
    printDeque(&d);

    delete_front(&d);
    delete_rear(&d);
    printDeque(&d);

    return 0;
}
