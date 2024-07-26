INFORMACIÓN IMPORTANTE AQUI:
- https://youtu.be/wRvipSG4Mmk?si=Rey3vNnSwop5HVAW
- https://medium.com/@ayogun/push-swap-c1f5d2d41e97
- https://medium.com/nerd-for-tech push-swap-tutorial-fa746e6aba1e

EXPLICACION DEL DESAROLLO DEL PROYECTO


- OBJETIVO
    - Implementación de un algoritmo que ordene los numeros de una pila con el menor numero de operaciones posible.


- ESPECIFICACIONES:

    - Tenemos dos pilas: StackA y StackB.
    En StackA tenemos una lista desorganizada de numeros (positivos y negativos), tenemos que coger los numeros de StackA y organizarlos de menor a mayor.
    Solo hay unos pocos movimientos permitidos para modificar la pila que les llamaremos "acciones".
    
    - Acciones permitidas:
        - s(swap), r(rotate), rr(reverse rotate), p(push):

        - sa: Rotar los 2 nºs de la cima de StackA
        - sb: Rotar los 2 nºs de la cima de StackB
        - ss: Ejecutar sa y sb al mismo tiempo

        - ra: Llevar la cima a la base de StackA
        - rb: Llevar la cima a la base de StackB
        - rr: Ejecutar ra y rb al mismo tiempo

        - rra: Llevar la base a la cima de StackA
        - rrb: Llevar la base a la cima de StackB
        - rrr: Ejecutar rra y rrb al mismo tiempo

        - pa: Llevar la cima de StackB a la cima de StackA
        - pb: Llevar la cima de StackA a la cima de StackB


- ALGORITMO:
    1. Declaracion de nuestras dos estructuras de datos (A y B)
        - Inicializar ambas pilas a NULL

    2. Parseo de entrada:
        - Debe haber dos o más argumentos
            - Nº variable de argumentos
            - Un único argumento en forma de string
        - Error 1. Incorrect number of parameters --> Si me introducen menos de dos parametros
        - Error 2. Unable to allocate memory --> Si la cantidad de argumentos que me pasan es muy grande
        - Error 3. Number out of range --> Si me pasan un numero mayor a MAXINT
        - Error 4. No number to convert --> Si me pasan algo que no sea un número
        - Error 5. Duplicate values --> Si me pasan dos numeros iguales
        - Error 6. Impossible to create the array --> Si no se ha podido dividir los argumentos correctamente para poderlos examinar
        - Error 7. 2nd value is NULL. --> Si lo que hay en "" como primer argumento es nulo.

    3. Inicializar StackA aplicando cada num de entrada como un nodo de StackA

    4. Comprobar que se ha inicializado correctamente.
        - Error 8. Failed to create list

    5. Algoritmo


    5. Comprobar si StackA está ordenado
        Si no está ordenado implementar nuestro algoritmo
        Comprobar 2 numeros. Si no estan ordedos. Rotarlos
        Comprobar 3 numeros. Si no están ordenados, implementar nuestro simple algoritmo "ordenar arbol"
        Si tiene más de 3 números, implementar nuestro "algoritmo turco"

    6. Limpiar stack


- Reminder parseo:
    1. Con number_arguments() obtenemos el nº total de argumentos que buscamos introducir en la primera pila
        - Si hay 2 argumentos quiere decir que puede ser: ./nombre_programa "23 45 67" (totales: 2, buscamos: 3)
        - Si hay más de 2 argumentos, quiere decir que será: ./nombre_programa 23 45 67 (totales: 4, buscamos: 3)
    2. Le pasamos a aux_parse() dos parametros: El número buscado de argumentos y por debe emmpezar a hacer el parseo
        - aux_parse() llama a allocate_and_parse() para meter en un array de enteros todos los enteros de los argumentos
        - luego hacemos una comprobación para ver si los numeros están repetidos en el array o no.


- Reminder init:
    1. Iniciamos la pila b a null y metemos todos los numeros como nodos de una lista en la pila a