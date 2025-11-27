// codigo 1
# Variables y cadenas en Python

# Variables
nombre = "Juan"
edad = 20
altura = 1.75

print("Nombre:", nombre)
print("Edad:", edad)
print("Altura:", altura)

# Cadenas
cadena1 = "Hola"
cadena2 = "Mundo"
print("{} {}".format(cadena1, cadena2))

// codigo 2
# Operadores aritméticos
a = 10
b = 3

print("Suma:", a + b)
print("Resta:", a - b)
print("Multiplicación:", a * b)
print("División:", a / b)

# Operadores booleanos
x = True
y = False

print("AND:", x and y)
print("OR:", x or y)
print("NOT:", not x)

# Comparación
print("a > b:", a > b)
print("a == b:", a == b)

//codigo 3
# Listas
lista = [1, 2, 3, "hola", [5, 6]]
print("Lista completa:", lista)
print("Elemento en índice 3:", lista[3])

# Tuplas
tupla = (10, 20, 30)
print("Tupla:", tupla)

# Diccionarios
dic = {"nombre": "Ana", "edad": 22}
print("Diccionario:", dic)
print("Nombre:", dic["nombre"])

//codigo 4
# Ejemplo de funciones

def suma(a, b):
    return a + b

def saludo(nombre):
    print("Hola {}".format(nombre))

print("Resultado suma:", suma(5, 8))
saludo("Carlos")

//codigo 5
# IF - ELSE - ELIF
x = 15

if x < 10:
    print("Es menor que 10")
elif x < 20:
    print("Está entre 10 y 20")
else:
    print("Es mayor o igual a 20")

# WHILE
i = 0
while i < 5:
    print("i =", i)
    i += 1

# FOR
frutas = ["manzana", "pera", "uva"]
for fruta in frutas:
    print(fruta)

//codigo 6
print("Hola, ¿cómo te llamas?")
nombre = input()
print("Buen día {}".format(nombre))

print("---Calculadora---")
print("1- Sumar")
print("2- Restar")
print("3- Multiplicar")
print("4- Dividir")
print("5- Salir")

op = int(input("Opción: "))

if op == 1:
    a = int(input("Número 1: "))
    b = int(input("Número 2: "))
    print("Resultado:", a + b)

//codigo 7
import matplotlib.pyplot as plt

x = [1, 2, 3, 4]
y = [10, 20, 25, 30]

plt.plot(x, y)
plt.xlabel("Eje X")
plt.ylabel("Eje Y")
plt.title("Ejemplo de gráfica")
plt.show()

