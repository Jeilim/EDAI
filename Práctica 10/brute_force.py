import itertools
import string
import time

caracteres = string.digits   # "0123456789"

def fuerza_bruta(longitud):
    inicio = time.time()
    print(f"\nGenerando contraseñas de longitud {longitud}...\n")

    contador = 0

    for combinacion in itertools.product(caracteres, repeat=longitud):
        pwd = ''.join(combinacion)
        contador += 1
        
        if contador % 1000000 == 0:
            print(f"{contador} combinaciones generadas...")

    fin = time.time()
    print(f"\nTotal de combinaciones: {contador}")
    print(f"Tiempo total: {fin - inicio:.2f} segundos\n")

# Prueba
fuerza_bruta(4)
fuerza_bruta(8)
fuerza_bruta(10)

