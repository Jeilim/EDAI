#include <stdio.h>
#define TAM 10
#define NUM_DIR 2

struct pelicula {
    char nombre [30];
    char genero[30];
    int  anio;
    int  numDirectores;
    char directores[NUM_DIR][20];
};

int main(void) {
    int totalPeliculas = TAM;

    struct pelicula videoteca[TAM];

    for (int i = 0; i < totalPeliculas; i++) {
        printf("\n--- Captura de la pelicula %d ---\n", i + 1);

        printf("Ingrese el nombre: ");
        scanf("%s", videoteca[i].nombre);

        printf("Ingrese el genero: ");
        scanf("%s", videoteca[i].genero);

        printf("Ingrese el anio: ");
        scanf("%d", &videoteca[i].anio);

        // Validación para directores
        do {
            printf("Cuantos directores tiene (1 a %d): ", NUM_DIR);
            scanf("%d", &videoteca[i].numDirectores);

            if (videoteca[i].numDirectores <= 0) {
                printf("Error: debe tener al menos 1 director.\n");
            } else if (videoteca[i].numDirectores > NUM_DIR) {
                printf("Error: maximo permitido es %d directores.\n", NUM_DIR);
            }

        } while (videoteca[i].numDirectores <= 0 || videoteca[i].numDirectores > NUM_DIR);

        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("Nombre del director %d: ", j + 1);
            scanf("%s", videoteca[i].directores[j]);
        }
    }

    // Orden inverso
    printf("\n####### Contenido de la videoteca #######\n");
    for (int i = totalPeliculas - 1; i >= 0; i--) {
        printf("Pelicula: %s\n", videoteca[i].nombre);
        printf("Genero: %s\n", videoteca[i].genero);
        printf("Anio: %d\n", videoteca[i].anio);
        printf("Directores (%d):\n", videoteca[i].numDirectores);
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("  - %s\n", videoteca[i].directores[j]);
        }
        printf("\n");
    }

    return 0;
