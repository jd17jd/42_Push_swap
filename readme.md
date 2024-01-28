EXPLICACION DEL DESAROLLO DEL PROYECTO

- ESPECIFICACIONES:
    - PUSH: Empujar. SWAP = Intercambiar
    - Tenemos dos pilas: PilaA y PilaB. En la pilaA tenemos una lista desorganizada de numeros, tenemos que coger los numeros de pilaA y organizarlos de menor a mayor. Solo hay unos pocos movimientos permitidos para modificar la pila que les llamaremos "acciones".
    
    - Qué acciones tenemos permitido usar en las dos pilas?
        - sa: Swap top 2 nºs in StackA
        - sb: Swap top 2 nºs in StackB
        - ss: Run sa & sb at the same time

        - ra: Top nº goes to the bottom of StackA
        - rb: Top nº goes to the bottom of StackB
        - rr: Run ra & rb at the same time

        - rra: Bottom nº goes to the top of StackA
        - rrb: Bottom nº goes to the top of StackB
        - rrr: Run rra & rrb at the same time

        - pa: Send top StackB to top StackA
        - pb: Send top StackA to top SatckB


    usando el menor numero 


- OBJETIVO
    - Implementación de un algoritmo que ordene los numeros de una pila con el menor numero de operaciones posible.


- FUNCIONES QUE UTILIZAREMOS


- ALGORITMO:

