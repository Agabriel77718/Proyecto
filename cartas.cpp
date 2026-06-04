#include <iostream>
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()


using namespace std; // Así nos olvidamos del std:: en cada línea

// Estructura simple para representar una carta de forma numérica
struct Carta {
    int palo;  // 0 = Corazon, 1 = Diamante, 2 = Pica, 3 = Trebol
    int valor; // 0 al 12
};

void jugarPoker() {
    cout << "\n=========================================\n";
    cout << "♣ ♦       BIENVENIDO AL POKER          ♥ ♠\n";
    cout << "=========================================\n";

    // 1. Crear el mazo ordenado de 52 cartas
    Carta mazo[52];
    int contador = 0;

    for (int p = 0; p < 4; p++) {       // Recorre los 4 palos
        for (int v = 0; v < 13; v++) {  // Recorre los 13 valores
            mazo[contador].palo = p;
            mazo[contador].valor = v;
            contador++;
        }
    }

    // 2. Barajar el mazo (Intercambiar cartas al azar)
    // Usamos el tiempo actual para que los números cambien en cada partida
    srand(time(0)); 
    for (int i = 0; i < 52; i++) {
        int indiceAleatorio = rand() % 52;
        // Intercambio clásico usando una variable temporal
        Carta temp = mazo[i];
        mazo[i] = mazo[indiceAleatorio];
        mazo[indiceAleatorio] = temp;
    }

    // 3. Repartir las primeras 5 cartas al jugador
    Carta manoJugador[5];
    cout << "\nTus 5 cartas aleatorias (Formato {Palo, Valor}):\n\n";
    
    for (int i = 0; i < 5; i++) {
        manoJugador[i] = mazo[i]; // Tomamos las primeras 5 del mazo ya barajado
        
        // Imprimimos el resultado numérico puro
        cout << "Carta " << (i + 1) << ": {" << manoJugador[i].palo << ", " << manoJugador[i].valor << "}\n";
    }

    cout << "\n=========================================\n";
    cout << "Guia de Palos: 0=Corazon, 1=Diamante, 2=Pica, 3=Trebol\n";
    cout << "Guia de Valores: 0=As, 1-9=Numeros, 10=J, 11=Q, 12=K\n";
    cout << "=========================================\n";
}
// temporal
int main() {
    jugarPoker();
    return 0;
}