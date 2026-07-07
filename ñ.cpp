#include <iostream> // entrada y salida 
#include <fstream> // flujo de los archivos (recordar po que se me olvida)
#include <string> // Permite usar cadenas de texto completas en lugar de letras individuales(recordarr tambien)
#include <cstdlib> // basicamente la libreria (recordar tambien)
#include <ctime>   //Da acceso a las funciones de fecha y hora del sistema de tu computadora
// la verdad este no lo conozco bien pero en archivo RPG del ingeniero lo utilizo y quise probar 
// al menos me ayudo pa asegurar numeros distitnso siempre en cada mazo de cartas
using namespace std;

// Estructura de datos para el usuario 
// COPIRYGT POR: MERIVAS (visiten su repositorio del juego RPG)
struct Jugador {
    string nombre;
    double saldo;
};

// funciones del juego
// COPIRYGT  POR: merivas (tambien robada la idea del juego "ejemplo" enseñado em clase)
void mostrarMenuCasino(const Jugador& usuario);
void jugarHighOrLow(Jugador& usuario);
void registrarApuesta(string nombre, double apuesta, string resultado, double saldoFinal);
void mostrarHistorial();

int main() {
    srand(time(0)); // COSITO PARA LO DE LAS CARTAS ALEATORIAS 

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
        mostrarMenuCasino(usuario);
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
    return 0;
}

// uso de las funciones 
// apoyo (IA GEMINI) usada para corregir linea 90 
void mostrarMenuCasino(const Jugador& usuario) {
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