def cambio_greedy(cantidad, monedas):
    print(f"\nCantidad: {cantidad}")
    print(f"Monedas disponibles: {monedas}")

    resultado = {}

    for moneda in monedas:
        if cantidad >= moneda:
            num = cantidad // moneda
            resultado[moneda] = num
            cantidad -= num * moneda

    print("\nCambio devuelto:")
    for m, c in resultado.items():
        print(f"{m} : {c}")

    if cantidad > 0:
        print("\n⚠ No se pudo dar el cambio exacto con estas monedas")

# Prueba
cambio_greedy(87, [50, 20, 10, 5, 2, 1])

