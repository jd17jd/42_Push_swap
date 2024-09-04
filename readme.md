# EXPLICACION DEL DESAROLLO DEL PROYECTO

##  OBJETIVO
    - Implementación de un algoritmo que ordene los numeros de una pila con el menor numero de operaciones posible.


## ESPECIFICACIONES:

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


## ALGORITMO:
    1. DECLARACION ESTRUCTURAS DE DATOS (Listas enlazadas A y B)
        - Inicializamos ambas pilas a NULL para evitar comportamientos indefinidos

    2. PARSEO ENTRADA
        - VÁLIDO
            - Si es un único argumento en forma de string
                - ./push_swap "1 2 3 4 5"
                    --> [[1], [2], [3], [4], [5]]

            - Si tiene un numero variable de argumentos
                - ./push_swap 1
                    --> [[1]]

                - ./push_swap 1 2 3 4 5
                    --> [[1], [2], [3], [4], [5]]

        - INVÁLIDO
            - Error 1. Incorrect number of parameters --> Si me introducen menos de dos parametros
                - ./push_swap

            - Error 2. Unable to allocate memory --> Si la cantidad de argumentos que me pasan es muy grande
                - ./push_swap 1 2 .... 99999998 99999999
            
            - Error 3. Number out of range --> Si me pasan un numero mayor a MAXINT
                - ./push_swap 78 54 9999999999999999

            - Error 4. No number to convert --> Si me pasan algo que no sea un número
                - ./push_swap 2 5 k 9

            - Error 5. Duplicate values --> Si me pasan dos numeros iguales
                - ./push_swap 1 2 3 4 5 5

            - Error 6. Impossible to create the array --> Si no se ha podido dividir los argumentos correctamente para poderlos examinar
            or
            2nd value is NULL. --> Si lo que hay en "" como primer argumento es nulo.

            - Error 7. Impossible to create stacks --> Si las pilas no se han podido crear

            - Error 8. Impossible to allocate memory for the int aray

    3. INICIALIZAMOS STACK A
        - Inicializamos StackA apilando cada numero de entrada como un nodo.

    5. ORDENACION STACK A (ALGORITMO)


    6. LIMPIAR STACK


## REMINDER PARSEO:
    1. Con number_arguments() obtenemos el nº total de argumentos que buscamos introducir en la primera pila
        - Si hay 2 argumentos quiere decir que puede ser: ./push_swap "23 45 67" (totales: 2, buscamos: 3)
        - Si hay más de 2 argumentos, quiere decir que será: ./push_swap 23 45 67 (totales: 4, buscamos: 3)

    2. Le pasamos a aux_parse() dos parametros: El número buscado de argumentos y por debe emmpezar a hacer el parseo
        - aux_parse() llama a allocate_and_parse() para meter en un array de enteros todos los enteros de los argumentos
        - luego hacemos una comprobación para ver si los numeros están repetidos en el array o no.

    3. Finalmente liberamos la memoria del array de caracteres y devolvemos el array de enteros resultante tras haber comprobado que es una cadena de números válida para seguir con la siguiente fase.


## REMINDER INIT:
    1. Comprobamos que las pilas existan, inicializamos la pila b a null y metemos todos los números del array anterior como nodos de una lista en la pila a

    2. Cada nodo de las pilas está compuesto por 2 elementos y 2 conexiones:
        - Elementos: Posicion y contenido
        - Conexiones: Detrás y delante

    3. Para inicializar A:

    necesitamos la correlacion entre los números enteros originales (content) y su valor de menor a mayor empezando por el 0 (position).

    Para esto, crearemos nodos nuevos con la correspondiente información entre la posicion y su contenido.

    por ejemplo:

    tendríamos:
        Node: 0x7fc0a3f05cc0, position: 0, content: -100
        Node: 0x7fc0a3f05ce0, position: 2, content: 5
        Node: 0x7fc0a3f05d00, position: 3, content: 78
        Node: 0x7fc0a3f05d20, position: 4, content: 29383727
        Node: 0x7fc0a3f05d40, position: 1, content: -9

    querríamos:
        Node: 0x7fc0a3f05cc0, position: 0, content: -100
        Node: 0x7fc0a3f05d40, position: 1, content: -9
        Node: 0x7fc0a3f05ce0, position: 2, content: 5
        Node: 0x7fc0a3f05d00, position: 3, content: 78
        Node: 0x7fc0a3f05d20, position: 4, content: 29383727

    lo hacemos porque para nuestro futuro algoritmo de ordenamiento nos será necesario tener todos los nodos con valores positivos.

    4. Para ello, en init() inicializamos la pila B, y llamamos a init_a() para inicializar la A.

    5. En init_a() creamos la pila nodo a nodo (cada uno con la información de position(el valor positivo) y content(el valor original)).

    6. En to_position_array() transformamos el array original a su analogo en valores positivos empezando desde el cero.

    7. Para ello, necesita primero tener el array ordenado, esto lo hacemos con el metodo de la burbuja en bubble_sort().

    En el ejemplo de antes, nos devuelve -100 5 78 29383727 como: -100 -9 5 78 29383727.

    8. Luego, para dar el valor positivo, lo único que debemos hacer es comparar los valores iniciales con los valores del array ordenado y darles la posición en la que están en este nuevo array


## REMINDER ALGORITMO
    1. Comprobamos primero si la pila ya está ordenada
    En caso contrario, elegimos un método u otro para ordenar la pila en funcion de su longitud:

    2. Si la pila tiene 2 elementos, los evaluamos y aplicamos sa si no están ordenados

    3. Si la pila tiene 3 elementos, aplicamos sort_three_elements(): Si el más alto está en la cima (primer elto), llevarlo a la base (ultimo elto) y después aplicar igual que con 2 elementos, con los dos de la cima.

    4. Si la pila tiene 4 o 5 elementos, aplicamos sort_five_elements():
        - Encontramos el nodo más bajo y lo llevamos a la cima de A.
        - Lo llevamos a la cima de B.
        - Repetimos esto hasta que queden 3 elementos en A. (Se hace 2 veces si hay 5 o 1 si hay 4)
        - Se aplica sort_three_elements()
        - Cuando haya terminado, como el más bajo está en la cima de B, llevamos todos los que haya de uno en uno en A, quedando así ordenada.

    5. Si la pila tiene más de 5 elementos, aplicamos sort_big_stack():
        - Calculamos el numero maximo de bits necesario para representar la cantidad de elementos que tengamos (Mientras el número size desplazado a la derecha max_bits veces no sea 0, incrementa max_bits en 1)
        - Recorremos el bucle tantas veces como bits haya para aplicar el algoritmo de ordenación radix (sort_by_bit)
        - Recorremos este otro bucle tantas veces como grande sea la pila:
            - obtenemos el valor de la position del nodo actual (cima de la pila).
            - desplazamos el número num a la derecha bit posiciones y luego hacemos una operación AND con 1 para aislar el bit en la posición bit.
            - Si el bit aislado es 1, rotamos; de lo contrario lo llevamos a la pila B.
            - Así conseguimos separar los bits que sean 1s de los 0s y más tarde volvemos a traer los bits de la pila B a la A.
