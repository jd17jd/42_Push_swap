INFORMACIÓN IMPORTANTE AQUI:
- https://youtu.be/wRvipSG4Mmk?si=Rey3vNnSwop5HVAW
- https://medium.com/@ayogun/push-swap-c1f5d2d41e97


EXPLICACION DEL DESAROLLO DEL PROYECTO

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


- OBJETIVO
    - Implementación de un algoritmo que ordene los numeros de una pila con el menor numero de operaciones posible.


- ALGORITMO:
    1. Declaracion a nuestras dos estructuras de datos / listas enlazadas. Una para A y otra para B.
        Inizializar ambas pilas a NULL para evitar comportamiento indefinido.

    2. Control de errores entrada. Debe haber dos o mas argumentos y el segundo no puede ser nulo

    3. Parseo de la entrada
        Si es un variable número de argumentos
        Si es un único argumento en forma de string

    4. Inicializar StackA apilando cada numero de entrada como un nodo de StackA
        Manejar los erroes de los posibles nodos a apilar (overflow, duplicados, elementos que no sean long int)
        Los nodos deben ser long int
        Apilar los nodos a StackA

    5. Comprobar si StackA está ordenado
        Si no está ordenado implementar nuestro algoritmo
        Comprobar 2 numeros. Si no estan ordedos. Rotarlos
        Comprobar 3 numeros. Si no están ordenados, implementar nuestro simple algoritmo "ordenar arbol"
        Si tiene más de 3 números, implementar nuestro "algoritmo turco"

    6. Limpiar stack



Proximo día:

- Hacer todos los movimientos
- Añadir en la carpeta lib el gnl y printf bien
- Actualizar el .h
- Mirar el parseo bien
- Terminar el main
