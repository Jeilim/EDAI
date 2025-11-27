#include <stdio.h>
#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacía.\n");
}

int estaLlena(Cola *c) {
    return c->final == MAX - 1;
}

int estaVacia(Cola *c) {
    return c->frente > c->final;
}

void enqueue(Cola *c, int valor) {
    if (estaLlena(c)) {
        printf("Error: la cola está llena.\n");
        return;
    }
    c->datos[++(c->final)] = valor;
    printf("Enqueue: %d\n", valor);
}

int dequeue(Cola *c) {
    if (estaVacia(c)) {
        printf("Error: cola vacía, no se puede hacer dequeue.\n");
        return -1;
    }
    return c->datos[(c->frente)++];
}

void mostrarCola(Cola *c) {
    if (estaVacia(c)) {
        printf("[Cola vacía]\n");
        return;
    }

    printf("Estado de la cola: ");
    for (int i = c->frente; i <= c->final; i++) {
        printf("%d ", c->datos[i]);
    }
    printf("\n");
}

int main() {
    Cola c;
    inicializarCola(&c);

    int n, valor;

    // ENQUEUE
    printf("¿Cuántos elementos quieres encolar (max 5)? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        enqueue(&c, valor);
        mostrarCola(&c);
    }

    // DEQUEUE
    printf("\n¿Cuántos elementos quieres desencolar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int eliminado = dequeue(&c);
        if (eliminado != -1)
            printf("Dequeue: %d\n", eliminado);
        mostrarCola(&c);
    }

    return 0;
}

