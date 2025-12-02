# Fibonacci Top-Down (Memoización)

memoria = {}

def fibonacci_top_down(n):
    if n in memoria:
        return memoria[n]
    
    if n == 0:
        memoria[0] = 0
    elif n == 1:
        memoria[1] = 1
    else:
        memoria[n] = fibonacci_top_down(n-1) + fibonacci_top_down(n-2)
    
    return memoria[n]


# Prueba
n = int(input("Ingresa un número para calcular Fibonacci con Top-Down: "))
print("Resultado:", fibonacci_top_down(n))
print("Memoria utilizada:", memoria)
