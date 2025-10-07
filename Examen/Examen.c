#include <stdio.h>
#include <stdlib.h> //para usar malloc, calloc, realloc, free

int main() {
    int n, nuevos, total;
    float *calificaciones;
    float suma = 0.0, promedio;

    //ingresar estudiantes
    printf("¿Cuántos estudiantes deseas registrar? ");
    scanf("%d", &n);

    // Reservar la memoria dinámicamente
    calificaciones = (float *) malloc(n * sizeof(float));
    if (calificaciones == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Guardar calificaciones y calcular promedio inicial
    for (int i = 0; i < n; i++) {
        printf("Calificación del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]);
        suma += calificaciones[i];
    }

    promedio = suma / n;
    printf("Promedio inicial: %.2f\n", promedio);

    // Preguntar si se desean agregar más estudiantes
    printf("\n¿Deseas agregar más estudiantes? (cantidad, 0 para no): ");
    scanf("%d", &nuevos);

    if (nuevos > 0) {
        total = n + nuevos;
        float *temp = (float *) realloc(calificaciones, total * sizeof(float));
        if (temp == NULL) {
            printf("Error al ampliar la memoria.\n");
            free(calificaciones);
            return 1;
        }
        calificaciones = temp;

        // Guardar nuevas calificaciones y recalcular promedio
        for (int i = n; i < total; i++) {
            printf("Calificación del estudiante %d: ", i + 1);
            scanf("%f", &calificaciones[i]);
            suma += calificaciones[i];
        }

        promedio = suma / total;

        // Mostrar todas las calificaciones y el resultado del nuevo promedio
        printf("\n=== Calificaciones registradas ===\n");
        for (int i = 0; i < total; i++) {
            printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
        }
        printf("Promedio general: %.2f\n", promedio);
    } else {
        printf("\n=== Calificaciones registradas ===\n");
        for (int i = 0; i < n; i++) {
            printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
        }
        printf("Promedio general: %.2f\n", promedio);
    }

    // Liberar la memoria
    free(calificaciones);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
