#include <stdio.h>

int main (void){
    int n;
    int a [10];
    
    printf("Ingresa una cantidad (máx 10):\n");
    scanf("%d", &n);
    
    if (n<1||n>10){
        printf("No es valido");}
        else if (n>0||n<11){
            printf("Ingrese %d numeros:\n", n);
            for(int i=0; i<n; i++){
                printf("Elemento %d:", i);
                scanf("%d", &a[i]);
            }
            printf("Los elementos del array son:\n");
            for (int i=0;i<n;i++){
                printf("%d",a[i]);
            
            }
        }
    
    printf("\n");
    return 0;
}
