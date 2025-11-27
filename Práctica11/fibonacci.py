from functools import lru_cache

# Función recursiva con memoización
@lru_cache(maxsize=None)
def fibonacci(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fibonacci(n-1) + fibonacci(n-2)

# Posiciones requeridas
posiciones = [7, 21, 40, 71, 94]

print("Secuencia de Fibonacci para las posiciones requeridas:\n")
for pos in posiciones:
    print(f"Fibonacci({pos}) = {fibonacci(pos)}")
