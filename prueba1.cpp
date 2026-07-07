/*elegir carta al azar y decidir si sera alta o baja y dependiendo 
 si el usuario adivina lo que sera la carta pues ganara y si no lo lograra perderia*/

#include <iostream>

using namespace std;

// Declaración de la función para la ronda de juego
void jugarRonda();

int main() {
    int menu;

    // MENU para cuando el usuario quiera jugar pero por el momento solo jugar
    cout << "OLA,BIENVENIDO A HIGHT O LOW\n1.JUGAR UNA RONDA\n2.SALIR DEL JUEGO\n";
    cin >> menu;

    switch (menu) {
        case 1:
            jugarRonda(); // Llamamos a la función para que ejecute la lógica del juego
            break;
        case 2:
            cout << "SALISTE DEL JUEGO" << endl;
            break;
        default:
            cout << "ERROR. OPCION INGRESADA NO VALIDA" << endl;
            break;
    }

    return 0;
}

// Definición de la función (Toda la lógica separada aquí)
void jugarRonda() {
    int carta1 = 6;
    int carta2 = 8;
    int resultado;

    cout << "la carta actul es:" << carta1 << endl;
    cout << "LA SIGUIENTE CARTA SERA ALTA(1) O BAJA(2): ";
    cin >> resultado;

    cout << "y la carta fuee unn:" << carta2 << endl;

    if (carta2 > carta1 && resultado == 1) {
        cout << "GANASTE 100 PESOS, ERA MAS ALTA" << endl;
    } 
    else if (carta2 < carta1 && resultado == 2) {
        /*aqui ya funciona correctamente al separarlo*/
        cout << "GANASTE 100 PESOS, ERA MAS BAJO" << endl;
    } 
    else {
        cout << "PERDISTE,NO ACERTASTE" << endl;
    }
}