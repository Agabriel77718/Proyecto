Algoritmo JuegoLuckyShot
    // 1. Declaración y definición de variables
    Definir intentos, dado1, dado2 Como Entero
    
    // Valores fijos provisionales que pusieron para probar la lógica
    intentos <- 3
    dado1 <- 4
    dado2 <- 4
    
    // 2. Mostrar la bienvenida y los resultados
    Escribir "===Bienvenido al juego de los dados==="
    Escribir "Dado1: ", dado1
    Escribir "Dado2: ", dado2
    Escribir "Tu puntuacion final es ", (dado1 + dado2)
    
    // 3. Estructura Condicional (Si-Sino) para evaluar si ganó
    Si (dado1 + dado2 >= 8) Entonces
        Escribir "Superaste el objetivo! GANASTE"
    Sino
        Escribir ">> No superaste 8."
    FinSi
    
FinAlgoritmo