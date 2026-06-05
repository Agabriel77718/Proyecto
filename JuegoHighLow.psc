Algoritmo JuegoHighLow
    // 1. Declaración y definición de variables
    Definir menu, carta1, carta2, resultado Como Entero
    
    // Valores fijos provisionales que pusiste para probar la lógica
    carta1 <- 6
    carta2 <- 8
    
    // 2. Mostrar opciones al usuario
    Escribir "OLA, BIENVENIDO A HIGH OR LOW"
    Escribir "1. JUGAR UNA RONDA"
    Leer menu
    
    // 3. Estructura de Selección Múltiple (Equivalente al switch-case)
    Segun menu Hacer
        1:
            Escribir "La carta actual es: ", carta1
            Escribir "LA SIGUIENTE CARTA SERA ALTA (1) O BAJA (2)"
            Leer resultado
            
            Escribir "Y la carta fueeeeeeeeeeeeeee unnnnnn: ", carta2
            
            // Evaluamos las condiciones de victoria o derrota
            Si (carta2 > carta1 Y resultado == 1) Entonces
                Escribir "GANASTE 1000000000000 PESOS, ERA MAS ALTA"
            Sino 
                Si (carta2 < carta1 Y resultado == 2) Entonces
                    Escribir "GANASTE 1000000000000 PESOS, ERA MAS BAJO"
                Sino
                    Escribir "PERDISTE, NO ACERTASTE"
                FinSi
            FinSi
            
        De Otro Modo:
            Escribir "ERROR. OPCION INGRESADA NO VALIDA"
    FinSegun
FinAlgoritmo