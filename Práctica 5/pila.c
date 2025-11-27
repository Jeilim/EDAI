#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int tope;
} Pila;

void inicializarPila(Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacía.\n");
}

int estaLlena(Pila *p) {
    return p->tope == MAX - 1;
}

int estaVacia(Pila *p) {
    return p->tope == -1;
}

void push(Pila *p, int valor) {
    if (estaLlena(p)) {
        printf("Error: la pila está llena.\n");
        return;
    }
    p->datos[++(p->tope)] = valor;
    printf("Push: %d\n", valor);
}

int pop(Pila *p) {
    if (estaVacia(p)) {
        printf("Error: pila vacía, no se puede hacer pop.\n");
        return -1;
    }
    return p->datos[(p->tope)--];
}

void mostrarPila(Pila *p) {
    if (estaVacia(p)) {
        printf("[Pila vacía]\n");
        return;
    }
    printf("Estado de la pila: ");
    for (int i = 0; i <= p->tope; i++) {
        printf("%d ", p->datos[i]);
    }
    printf("\n");
}

int main() {
    Pila p;
    inicializarPila(&p);

    int n, valor;

    // PUSH
    printf("¿Cuántos elementos quieres apilar (max 5)? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        push(&p, valor);
        mostrarPila(&p);
    }

    // POP
    printf("\n¿Cuántos elementos quieres desapilar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int eliminado = pop(&p);
        if (eliminado != -1)
            printf("Pop: %d\n", eliminado);
        mostrarPila(&p);
    }

    return 0;
}

