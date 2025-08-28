//INVERTIDO

#include <stdio.h>

int main(void) {
    int n; 
    int i; 
    int a[10]; 
    int inv;

    printf("Ingresa la cantidad de números (máx 10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Número inválido.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n/2; i++) {
        inv = a[i];
        a[i] = a[n-1-i];
        a[n-1-i] = inv;
    }

    printf("Arreglo invertido: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}

