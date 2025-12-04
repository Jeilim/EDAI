def insertion_sort(lista):
    print("Lista original:", lista)

    for i in range(1, len(lista)):
        actual = lista[i]
        j = i - 1

        while j >= 0 and lista[j] > actual:
            lista[j + 1] = lista[j]
            j -= 1

        lista[j + 1] = actual

    print("Lista ordenada :", lista)

# Prueba
numeros = [12, 5, 3, 19, 1, 8]
insertion_sort(numeros)

