// ===========================================================
// JUEGO DE CARTAS PARA 2 JUGADORES (POR TURNOS)
// Meta: el primero en llegar a 100 puntos gana.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
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

    return 0;
}