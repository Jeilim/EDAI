//SUMA

int main (void)
{
    int n;
    int a [10];
    int i;
    int sum=0;
    
    printf("Ingresa una cantidad (máx 10):\n");
    scanf("%d", &n);
    
    if (n<1||n>10){
        printf("No es valido");
        }
        else if (n>0||n<11)
        {
            printf("Ingrese %d numeros:\n", n);
            for(int i=0; i<n; i++)
            {
                printf("Elemento %d:", i);
                scanf("%d", &a[i]);
                sum += a[i];
            }
            printf("La suma de los elementos del array son: %d \n",sum);  
        }
    
    return 0;
}

//RESTA 
#include <stdio.h>

int main(void)
{
    int n;
    int a[10];
    int i;
    int rest;  

    printf("Ingresa una cantidad (máx 10):\n");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("No es válido\n");
        return 1;
    }

    printf("Ingrese %d numeros:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &a[i]);  
    }

    rest = a[0];
    for (i = 1; i < n; i++) {
        rest -= a[i];  
    }

    printf("Los elementos del array son:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nEl resultado de la resta es: %d\n", rest);

    return 0;
}


//PROMEDIO

#include <stdio.h>

int main (void)
{
    int n;
    int a [10];
    int i;
    int sum=0;
    float prom;
    
    printf("Ingresa una cantidad (máx 10):\n");
    scanf("%d", &n);
    
    if (n<1||n>10){
        printf("No es valido");
        }
        else if (n>0||n<11)
        {
            printf("Ingrese %d numeros:\n", n);
            for(int i=0; i<n; i++)
            {
                printf("Elemento %d:", i);
                scanf("%d", &a[i]);
                sum += a[i];
                prom=(float)sum/n;
            }
            printf("El promedio de los elementos del array son: %f \n",prom);
            
        }
    
    return 0;
}

//MÍNIMOS Y MÁXIMOS

#include <stdio.h>

int main(void)
{
    int n, i;
    int a[10];
    int min, max;
    int posMin, posMax;

    printf("Ingresa una cantidad (máx 10):\n");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("No es válido\n");
        return 1;
    }

    printf("Ingrese %d numeros:\n", n);
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &a[i]);
    }

    min = max = a[0];
    posMin = posMax = 0;

    for (i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
            posMin = i;
        }
        if (a[i] > max) {
            max = a[i];
            posMax = i;
        }
    }

    printf("Los elementos del array son:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nEl mínimo es %d y está en la posición %d\n", min, posMin);
    printf("El máximo es %d y está en la posición %d\n", max, posMax);

    return 0;
}
