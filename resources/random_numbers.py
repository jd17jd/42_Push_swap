import random

MININT = -2147483648
MAXINT = 2147483647
cantidad_numeros = 500

if MAXINT - MININT + 1 < cantidad_numeros:
    print("El rango de enteros no es suficientemente grande para generar esa cantidad de números únicos.")
else:
    numeros_unicos = random.sample(range(MININT, MAXINT + 1), cantidad_numeros)
    print(numeros_unicos)
