#include <iostream>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// Estructura de datos para el usuario del juego High or Low
struct Jugador {
    string nombre;
    double saldo;
};

// Declaración de la función que inicia el juego High or Low (reemplaza a jugarRonda)
void iniciarHighOrLow();
void mostrarMenuCasinoHL(const Jugador& usuario);
void jugarHighOrLow(Jugador& usuario);
void registrarApuesta(string nombre, double apuesta, string resultado, double saldoFinal);
void mostrarHistorial();

// Declaración de las funciones para Lucky Shot
void iniciarLuckyShot();
void LanzarDados(char &opcion);

// Declaración de la función para el Poker (Five-Card Draw / 2 jugadores)
void jugarPoker();

int main()
{
   SetConsoleOutputCP(65001);
   srand(time(0)); // Inicia la semilla para que se generen los números aleatorios
   int cartas = 14, manos = 3, menu;
   // no sera aleatorio,tendra un sistema de cartas ya definido
   cout << "🟥🟥⬛⬛⬜⬜🟥🟥⬛⬛⬜⬜🟥🟥⬛⬛⬜⬜🟥🟥⬛⬛⬜⬜🟥🟥⬛⬛⬜⬜" << endl;
cout << "╭────────────────────────────────────────────────────────────╮" << endl;
cout << "│              🎰🎲  C L A S S I C   C A R D S  🃏♣️          │" << endl;
cout << "╰────────────────────────────────────────────────────────────╯" << endl;
cout << "⬛⬛🟥🟥⬜⬜⬛⬛🟥🟥⬜⬜⬛⬛🟥🟥⬜⬜⬛⬛🟥🟥⬜⬜🟥🟥⬛⬛⬜⬜" << endl;
cout << endl;
cout << endl;
   do
   {

cout << "╭────────────────────────────────────────────────────────────╮" << endl;
cout << "│                     CASINO VIRTUAL C++ 🗣️                   │" << endl;
cout << "├────────────────────────────────────────────────────────────┤" << endl;
cout << "│                                                            │" << endl;
cout << "│   [1] Poker (Five-Card Draw)                               │" << endl;
cout << "│   [2] High or Low (Mayor o Menor)                          │" << endl;
cout << "│   [3] Lucky Shot (Tiro de la suerte)                       │" << endl;
cout << "│                                                            │" << endl;
cout << "│   [4] Salir del Casino                                     │" << endl;
cout << "│                                                            │" << endl;
cout << "├────────────────────────────────────────────────────────────┤" << endl;
cout << "│                  ¡Hagan sus apuestas!                      │" << endl;
cout << "╰────────────────────────────────────────────────────────────╯" << endl;
 cout << " Seleccione una opcion: ";
      cin >> menu;
      cout << endl;
      cout << endl;

      switch (menu)
      {
     case 1:
    cout << "╭────────────────────────────────────────────────────────────╮" << endl;
    cout << "│ 🃏 Haz elegido     Video Poker (Five-Card Draw)            │" << endl;
    cout << "├────────────────────────────────────────────────────────────┤" << endl;
    cout << "│ ✨ La suerte puede estar de tu lado. Piensa rapido,        │" << endl;
    cout << "│    arma tu mejor jugada. ¡¡¡VE POR EL JACKPOT!!! ✨        │" << endl;
    cout << "╰────────────────────────────────────────────────────────────╯" << endl;
    jugarPoker();
    break;

case 2:
    cout << "╭────────────────────────────────────────────────────────────╮" << endl;
    cout << "│ 🃏 Haz elegido         High or Low (Mayor o Menor)         │" << endl;
    cout << "├────────────────────────────────────────────────────────────┤" << endl;
   cout << "│🔥Las cartas están en la mesa.  ¿El total será mayor o menor?│" << endl;
    cout << "│    ¡Arriesga, siente la adrenalina y duplica tus premios!🔥│" << endl;
    cout << "╰────────────────────────────────────────────────────────────╯" << endl;
    iniciarHighOrLow();
    break;

      case 3:
    cout << "╭────────────────────────────────────────────────────────────╮" << endl;
    cout << "│ 🎲 Haz elegido                  Lucky Shot                 │" << endl;
    cout << "├────────────────────────────────────────────────────────────┤" << endl;
    cout << "│    ¡Un solo tiro, una sola oportunidad! TODO O NADA        │" << endl;
    cout << "│    ¡Lanza con fuerza y deja que brille tu suerte!          │" << endl;
    cout << "╰────────────────────────────────────────────────────────────╯" << endl;
    iniciarLuckyShot();
    break;

      default:
         cout << "--------------Gracias por hacer tus apuestas en C L A S S I C   C A R D S te esperamos para mas apuestas!!!----------" << endl;
         break;
      }

   } while (menu !=4);

   return 0;
}

// ===========================================================
// HIGH OR LOW con sistema de saldo, apuestas e historial
// COPIRYGT POR: MERIVAS (visiten su repositorio del juego RPG)
void iniciarHighOrLow() {
    Jugador usuario;
    usuario.saldo = 100.0; // Saldo inicial base de la persona que vaya a jugar
    int menu;

    cout << "=== BIENVENIDO AL JUEGO HIGHT OR LOW ===" << endl;
    cout << "Ingrese su nombre : ";
    cin >> usuario.nombre;

    // pa recuperar lo del dinero si es que ya existia lo el dato 
    // EN ESTE ESPACIO FUE UTILIZADO GEMINI (IA) para saber como almacenar los datos 
    ifstream cargarSaldo("ultimo_saldo.txt");
    if (cargarSaldo.is_open()) {
        string nombreGuardado;
        double saldoGuardado;
        if (cargarSaldo >> nombreGuardado >> saldoGuardado) {
            if (nombreGuardado == usuario.nombre) {
                usuario.saldo = saldoGuardado;
                cout << "¡Hola de nuevo, " << usuario.nombre << "! Tu saldo es: $" << usuario.saldo << endl;
            }
        }
        cargarSaldo.close();
    }

    // Bucle principal usando DO-WHILE (Tal como el Ing. nos enseño para menús)
    do {
        mostrarMenuCasinoHL(usuario);
        cout << "Seleccione una opcion: ";
        cin >> menu;

        switch (menu) {
            case 1:
                jugarHighOrLow(usuario);
                break;
            case 2:
                mostrarHistorial();
                break;
            case 3:
                cout << "Guardando tu monto y saliendo del juego..." << endl;
                // Guardar dinero actual antes de cerrar el jogo
                {
                    ofstream guardarSaldo("ultimo_saldo.txt");
                    if (guardarSaldo.is_open()) {
                        guardarSaldo << usuario.nombre << " " << usuario.saldo << endl;
                        guardarSaldo.close();
                    }
                }
                break;
            default:
                cout << "ERROR. Opcion no VALIDADA. Intente de nuevo porfavor.\n" << endl;
        }
    } while (menu != 3); // Cierra el ciclo si elige la opción de salir

    cout << "¡Gracias, esperamos disfrutaras! tu saldo final es: $" << usuario.saldo << endl;
}

// uso de las funciones 
// apoyo (IA GEMINI) usada para corregir linea 90 
void mostrarMenuCasinoHL(const Jugador& usuario) {
    cout << "\n========================================" << endl;
    cout << " JUGADOR: " << usuario.nombre << " | BILLETERA: $" << usuario.saldo << endl;
    cout << "========================================" << endl;
    cout << "1. Jugar High or Low" << endl;
    cout << "2. Ver tu registro de apuestas" << endl;
    cout << "3. Salir del juego" << endl;
    cout << "========================================" << endl;
}

void jugarHighOrLow(Jugador& usuario) {
    // Validación de fondos disponibles
    if (usuario.saldo <= 0) {
        cout << "\n[!] No tienes dinero para apostar. ¡Juego terminado!" << endl;
        return;
    }

    double apuesta;
    cout << "\n¿Monto a apostar? $";
    cin >> apuesta;

    // Validaciones estrictas de entrada (Estilo funpar2.cpp)
    if (apuesta <= 0 || apuesta > usuario.saldo) {
        cout << "[!] Error: suma de apuesta invalido o insuficiente." << endl;
        return;
    }

    // Generar cartas (Rango del 1 al 13)
    // ROBADO DE VIDEO DE YOUTUBE 
    int carta1 = rand() % 13 + 1;
    int carta2 = rand() % 13 + 1;

    // Evitar empates idénticos
    // EOBADO DE VIDEO DE YOUTUBE 
    while (carta2 == carta1) {
        carta2 = rand() % 13 + 1;
    }

    int prediccion;
    cout << "La carta actual es: [" << carta1 << "]" << endl;
    cout << "¿La siguiente sera MAS ALTA (1) o MAS BAJA (2)?: ";
    cin >> prediccion;

    cout << "-> La carta oculta era: [" << carta2 << "]" << endl;

    string estado;
    if ((carta2 > carta1 && prediccion == 1) || (carta2 < carta1 && prediccion == 2)) {
        cout << "¡Acertasteeeeee! Ganaste musho: $" << apuesta << endl;
        usuario.saldo += apuesta;
        estado = "GANOOOOOOOO";
    } else {
        cout << "La casa gana (muejejejej). Perdiste: $" << apuesta << endl;
        usuario.saldo -= apuesta;
        estado = "PERDIO MONEY";
    }

    // Registrar jugada usando ios::app (pa guardar basicamente)
    //(lo que nos explico el ING. del archivo3.cpp en clase)
    registrarApuesta(usuario.nombre, apuesta, estado, usuario.saldo);
}
// COPIRYGHT POR: merivas ING. tomado de una de las clases de github
void registrarApuesta(string nombre, double apuesta, string resultado, double saldoFinal) {
    ofstream archivo("historial_casino.txt", ios::app); // Anexar sin borrar
    if (archivo.is_open()) {
        archivo << "Jugador: " << nombre 
                << " | Apuesta: $" << apuesta 
                << " | Resultado: " << resultado 
                << " | Dinero: $" << saldoFinal << endl;
        archivo.close();
    }
}
// COPIRYHHT POR: merivas ING. 
// VIDEO DE YOUTUBE 
// (IA GEMINI) pedi explicacion ya que no entendia y no resultaba loque queria 
void mostrarHistorial() {
    ifstream archivo("historial_casino.txt");
    string linea;

    cout << "\n--- MONTOS DE APUESTAS ---" << endl;
    if (archivo.is_open()) {
        bool vacio = true;
        while (getline(archivo, linea)) {
            cout << linea << endl;
            vacio = false;
        }
        archivo.close();
        if (vacio) cout << "No hay apuestas registradas aun." << endl;
    } else {
        cout << "[!] No se encontro el archivo de registros." << endl;
    }
    cout << "-----------------------------------------" << endl;
}

// ===========================================================
// LUCKY SHOT con opcion de volver a jugar tras perder
void iniciarLuckyShot() {
    char opcion = 0; // igual a 0 pera evitar basura
    cout << " == 🎲 🎰 Bienvenido a Lucky Shot 🎰 🎲 == " << endl;
    cout << "🟥 ==================================== 🍀 " << endl;
    cout << "⬛ === CASINO DE DADOS ==== 🎲 " << endl;
    cout << "🟥 Si la Suma >= 8 = Ganas 🍀 " << endl;
    cout << "⬛ Si la Suma <= 7 = Pierdes🎲 " << endl;
    cout << "🟥 ==================================== 🍀 " << endl;

    while (opcion != 'E' && opcion != 'e') {
        cout << "Presione 'P' para jugar o 'E' para salir: ";
        cin >> opcion;

        if (opcion == 'P' || opcion == 'p') {
            LanzarDados(opcion);
        }
        else if (opcion == 'E' || opcion == 'e') {
            cout << "Gracias por jugar al Lucky Shot" << endl;
        }
        else {
            cout << "Opcion no valida. Por favor, presione 'P' para jugar o 'E' para salir." << endl;
        }
    }
    cout << "Que tengas un buen dia, Dios te ama. " << endl;
}

void LanzarDados(char &opcion) {
int dado1 = (rand() % 6) + 1;
int dado2 = (rand() % 6) + 1;
int suma = dado1 + dado2;

cout<<"====✨ 🧑‍🤝‍🧑 Resultados🏽 ✨ ===="<<endl;
cout<<"====Dado 1: " << dado1 << "===="<<endl;
cout<<"====Dado 2: " << dado2 << "===="<<endl;
cout<<"====Suma: " << suma << "===="<<endl;

if (suma >= 8) {
cout << "===🤩🏅Ganaste🏅🤩===" << endl;
cout << "||==================||" << endl;
} else {
cout << "===😰🎭Perdiste🎭😰===" << endl;
cout << "||==================||" << endl;

char respuesta;
do {
cout << "¿Quieres volver a jugar? (S/N): ";
cin >> respuesta;
} while (respuesta != 'S' && respuesta != 's' && respuesta != 'N' && respuesta != 'n'); 

if (respuesta == 'N' || respuesta == 'n') {
opcion = 'E';
}
}
}


// ===========================================================
// JUEGO DE CARTAS PARA 2 JUGADORES (POR TURNOS)
// Meta: el primero en llegar a 100 puntos gana.
void jugarPoker() {
    srand(time(0));

    // ---------- Crear el mazo (52 cartas, valores 1-13, 4 veces cada uno) ----------
    int mazo[52];
    int pos = 0;
    for (int v = 1; v <= 13; v++) {
        for (int r = 0; r < 4; r++) {
            mazo[pos] = v;
            pos++;
        }
    }

    // ---------- Barajar el mazo (Fisher-Yates) ----------
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = temp;
    }

    int puntosJ1 = 0, puntosJ2 = 0;
    int indiceMazo = 0;
    int turno = 1; // 1 = Jugador1, 2 = Jugador2
    int ronda = 1;

    cout << "=== BIENVENIDO AL JUEGO DE CARTAS ===" << endl;
    cout << "Reglas:" << endl;
    cout << "- Cada turno, el jugador recibe 3 cartas (valores del 1 al 13)." << endl;
    cout << "- Trio (3 cartas iguales)  = 30 puntos + valor de la carta mas alta" << endl;
    cout << "- Pareja (2 cartas iguales) = 15 puntos + valor de la carta mas alta" << endl;
    cout << "- Carta alta (sin combinacion) = valor de la carta mas alta" << endl;
    cout << "- Gana el primero en llegar a 100 puntos." << endl;
    cout << "\nPresiona ENTER para comenzar...";
    cin.get();

    // ---------- Bucle principal del juego ----------
    while (puntosJ1 < 100 && puntosJ2 < 100) {

        cout << "\n----- RONDA " << ronda << " -----" << endl;
        cout << "Turno del Jugador " << turno << endl;

        // Si no quedan suficientes cartas (3 iniciales + hasta 2 de cambio), se rebaraja el mazo
        if (indiceMazo + 5 > 52) {
            for (int i = 51; i > 0; i--) {
                int j = rand() % (i + 1);
                int temp = mazo[i];
                mazo[i] = mazo[j];
                mazo[j] = temp;
            }
            indiceMazo = 0;
            cout << "(El mazo se ha rebarajado)" << endl;
        }

        // Repartir 3 cartas al jugador en turno
        int mano[3];
        for (int i = 0; i < 3; i++) {
            mano[i] = mazo[indiceMazo];
            indiceMazo++;
        }

        // Ordenar la mano de menor a mayor (burbuja simple)
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2 - i; j++) {
                if (mano[j] > mano[j + 1]) {
                    int t = mano[j];
                    mano[j] = mano[j + 1];
                    mano[j + 1] = t;
                }
            }
        }

        cout << "Cartas obtenidas: " << endl;
        cout << "  Carta 1: " << mano[0] << endl;
        cout << "  Carta 2: " << mano[1] << endl;
        cout << "  Carta 3: " << mano[2] << endl;

        // ---------- El jugador decide si cambia cartas ----------
        int numCambios;
        while (true) {
            cout << "\n¿Cuantas cartas quieres cambiar? (0, 1 o 2): ";
            cin >> numCambios;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Entrada invalida, debes ingresar un numero entero." << endl;
            } else {
                break;
            }
        }

        if (numCambios < 0) {
            numCambios = 0;
        }
        if (numCambios > 2) {
            numCambios = 2;
        }

        for (int c = 0; c < numCambios; c++) {
            int elegida;
            while (true) {
                cout << "¿Cual carta quieres cambiar? (1, 2 o 3): ";
                cin >> elegida;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Entrada invalida, debes ingresar un numero entero." << endl;
                } else {
                    break;
                }
            }

            if (elegida == 1 || elegida == 2 || elegida == 3) {
                int indice = elegida - 1;
                mano[indice] = mazo[indiceMazo];
                indiceMazo++;
                cout << "Nueva carta " << elegida << ": " << mano[indice] << endl;
            } else {
                cout << "Numero invalido, no se cambio ninguna carta." << endl;
            }
        }

        // Volver a ordenar la mano despues de los cambios (burbuja simple)
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2 - i; j++) {
                if (mano[j] > mano[j + 1]) {
                    int t = mano[j];
                    mano[j] = mano[j + 1];
                    mano[j + 1] = t;
                }
            }
        }

        cout << "\nMano final: " << mano[0] << " " << mano[1] << " " << mano[2] << endl;

        // Evaluar la combinacion de la mano
        int tipoMano; // 0 = nada, 1 = pareja, 2 = trio
        if (mano[0] == mano[1] && mano[1] == mano[2]) {
            tipoMano = 2;
        } else if (mano[0] == mano[1] || mano[1] == mano[2] || mano[0] == mano[2]) {
            tipoMano = 1;
        } else {
            tipoMano = 0;
        }

        int puntosRonda = 0;
        switch (tipoMano) {
            case 2:
                cout << "Combinacion: TRIO!" << endl;
                puntosRonda = 30 + mano[2];
                break;
            case 1:
                cout << "Combinacion: PAREJA" << endl;
                puntosRonda = 15 + mano[2];
                break;
            default:
                cout << "Combinacion: Carta alta" << endl;
                puntosRonda = mano[2];
                break;
        }

        cout << "Puntos ganados esta ronda: " << puntosRonda << endl;

        // Sumar puntos al jugador correspondiente
        if (turno == 1) {
            puntosJ1 = puntosJ1 + puntosRonda;
            cout << "Puntaje total Jugador 1: " << puntosJ1 << endl;
        } else {
            puntosJ2 = puntosJ2 + puntosRonda;
            cout << "Puntaje total Jugador 2: " << puntosJ2 << endl;
        }

        // Cambiar el turno
        if (turno == 1) {
            turno = 2;
        } else {
            turno = 1;
        }

        ronda++;
    }

    // ---------- Fin del juego ----------
    cout << "\n=== FIN DEL JUEGO ===" << endl;
    cout << "Puntaje final Jugador 1: " << puntosJ1 << endl;
    cout << "Puntaje final Jugador 2: " << puntosJ2 << endl;

    int ganador;
    if (puntosJ1 >= 100) {
        ganador = 1;
        cout << "¡Gana el Jugador 1!" << endl;
    } else {
        ganador = 2;
        cout << "¡Gana el Jugador 2!" << endl;
    }

    // Guardar resultado en archivo
    ofstream archivo("resultados.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Jugador1: " << puntosJ1 << " pts | Jugador2: " << puntosJ2
                << " pts | Ganador: Jugador " << ganador << endl;
        archivo.close();
        cout << "\nResultado guardado en resultados.txt" << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
