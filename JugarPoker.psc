Algoritmo JugarPoker
	// 1. Crear el mazo ordenado de 52 cartas
	// Usamos dos arreglos paralelos para simular la estructura
	Dimensionar mazoPalo(52)
	Dimensionar mazoValor(52)
	Definir mazoPalo, mazoValor Como Entero
	Definir contador Como Entero
	contador <- 0
	Definir p, v Como Entero
	Para p<-0 Hasta 3 Con Paso 1 Hacer
		Para v<-0 Hasta 12 Con Paso 1 Hacer // Recorre los 4 palos
			mazoPalo[contador] <- p // Recorre los 13 valores
			mazoValor[contador] <- v
			contador <- contador+1
		FinPara
	FinPara
	// 2. Barajar el mazo (Intercambiar cartas al azar)
	Definir i, indiceAleatorio Como Entero
	Definir tempPalo, tempValor Como Entero
	Para i<-0 Hasta 51 Con Paso 1 Hacer
		indiceAleatorio <- Aleatorio(0,51)
		// Intercambio clásico usando variables temporales
		tempPalo <- mazoPalo[i] // Equivalente a rand()  MOD  52
		tempValor <- mazoValor[i]
		mazoPalo[i] <- mazoPalo[indiceAleatorio]
		mazoValor[i] <- mazoValor[indiceAleatorio]
		mazoPalo[indiceAleatorio] <- tempPalo
		mazoValor[indiceAleatorio] <- tempValor
	FinPara
	// 3. Repartir las primeras 5 cartas al jugador
	Dimensionar manoJugadorPalo(5)
	Dimensionar manoJugadorValor(5)
	Definir manoJugadorPalo, manoJugadorValor Como Entero
	Escribir ''
	Escribir '========================================='
	Escribir '? ?       BIENVENIDO AL POKER          ? ?'
	Escribir '========================================='
	Escribir ''
	Escribir 'Tus 5 cartas aleatorias (Formato {Palo, Valor}):'
	Escribir ''
	Para i<-0 Hasta 4 Con Paso 1 Hacer
		// Tomamos las primeras 5 del mazo ya barajado
		manoJugadorPalo[i] <- mazoPalo[i]
		manoJugadorValor[i] <- mazoValor[i]
		// Imprimimos el resultado numérico puro
		Escribir 'Carta ', (i+1), ': {', manoJugadorPalo[i], ', ', manoJugadorValor[i], '}'
	FinPara
	Escribir ''
	Escribir '========================================='
	Escribir 'Guia de Palos: 0=Corazon, 1=Diamante, 2=Pica, 3=Trebol'
	Escribir 'Guia de Valores: 0=As, 1-9=Numeros, 10=J, 11=Q, 12=K'
	Escribir '========================================='
FinAlgoritmo
