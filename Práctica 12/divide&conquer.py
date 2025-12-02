# QuickSort (Divide & Conquer)

def quicksort(lista):
    if len(lista) <= 1:
        return lista  # Caso base
    
    pivote = lista[len(lista) // 2]
    menores = [x for x in lista if x < pivote]
    iguales  = [x for x in lista if x == pivote]
    mayores  = [x for x in lista if x > pivote]
    
    return quicksort(menores) + iguales + quicksort(mayores)


# Ejecución 
import random

lista = [random.randint(1, 100) for _ in range(10)]

print("Lista original:", lista)
lista_ordenada = quicksort(lista)
print("Lista ordenada:", lista_ordenada)

