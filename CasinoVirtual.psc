
//   SubProcesos (funciones sin retorno)
// ============================================================

SubProceso jugarPoker
	Escribir ""
	Escribir "===================================================="
	Escribir "        POKER - Five-Card Draw"
	Escribir "===================================================="
	Escribir "Aqui corrara el juego de Poker."
	Escribir "Presiona ENTER para regresar al menu..."
	Definir pausa Como Caracter
	Leer pausa
FinSubProceso

//----------------------------------------------------

SubProceso jugarHighLow
	Escribir ""
	Escribir "===================================================="
	Escribir "        HIGH OR LOW - Mayor o Menor"
	Escribir "===================================================="
	Escribir "Aqui corrara el juego de High or Low."
	Escribir "Presiona ENTER para regresar al menu..."
	Definir pausa Como Caracter
	Leer pausa
FinSubProceso

//----------------------------------------------------

SubProceso jugarLuckyShot
	Escribir ""
	Escribir "===================================================="
	Escribir "        LUCKY SHOT - Tiro de la suerte"
	Escribir "===================================================="
	Escribir "Aqui corrara el juego de Lucky Shot."
	Escribir "Presiona ENTER para regresar al menu..."
	Definir pausa Como Caracter
	Leer pausa
FinSubProceso

//----------------------------------------------------

SubProceso mostrarMenu
	Escribir "===================================================="
	Escribir "           CASINO VIRTUAL - CLASSIC CARDS"
	Escribir "===================================================="
	Escribir "  [1] Poker (Five-Card Draw)"
	Escribir "  [2] High or Low (Mayor o Menor)"
	Escribir "  [3] Lucky Shot (Tiro de la suerte)"
	Escribir "  [4] Salir del Casino"
	Escribir "===================================================="
	Escribir "  Hagan sus apuestas!"
	Escribir "===================================================="
FinSubProceso

// ============================================================
//   Funcion de logica del menu (testeable)
//   Recibe la opcion y devuelve una cadena con la accion
// ============================================================

Funcion resultado <- procesarMenu(menu)
	Definir resultado Como Cadena
	Segun menu Hacer
		1:
			resultado <- "POKER"
		2:
			resultado <- "HIGHLOW"
		3:
			resultado <- "LUCKYSHOT"
		4:
			resultado <- "SALIR"
		De Otro Modo:
			resultado <- "ERROR"
	Fin Segun
FinFuncion

//ALGORITMO PRINCIPAL
Algoritmo CasinoVirtual
	
	Definir menu Como Entero
	Definir accion Como Cadena
	
	Escribir "===================================================="
	Escribir "   Bienvenido a CLASSIC CARDS - Casino Virtual"
	Escribir "===================================================="
	
	Repetir
		
		mostrarMenu
		Escribir "Seleccione una opcion: "
		Leer menu
		Escribir ""
		
		accion <- procesarMenu(menu)
		
		Segun accion Hacer
			"POKER":
				Escribir "Has elegido: Poker (Five-Card Draw)"
				Escribir "La suerte puede estar de tu lado. Ve por el JACKPOT!"
				jugarPoker
				
			"HIGHLOW":
				Escribir "Has elegido: High or Low (Mayor o Menor)"
				Escribir "Los dados estan en el aire. Arriesga y duplica tus premios!"
				jugarHighLow
				
			"LUCKYSHOT":
				Escribir "Has elegido: Lucky Shot"
				Escribir "Un solo tiro, una sola oportunidad. TODO O NADA!"
				jugarLuckyShot
				
			"SALIR":
				Escribir "===================================================="
				Escribir "  Saliendo del Casino Virtual..."
				Escribir "  Gracias por jugar! Vuelve pronto."
				Escribir "===================================================="
				
			De Otro Modo:
				Escribir "ERROR: Por favor elige solo entre las opciones 1 a 4."
		Fin Segun
		
		Escribir ""
		
	Hasta Que menu = 4
	
FinAlgoritmo
