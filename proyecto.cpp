#include <windows.h>
#include <iostream>
using namespace std;
//void provisionales para comprabar funcionamiento del menu xd
void jugarPoker() {
    cout << "\n[ENTRANDO AL JUEGO DE POKER...]" << endl;
    cout << "Aquí correrá el juegpo" << endl;
    cout << "Presiona ENTER para regresar al menu del casino...";
    cin.ignore(); // Limpia el buffer
    cin.get();    // Pausa la pantalla hasta que presionen Enter
}

void jugarHighLow() {
    cout << "\n[ENTRANDO AL JUEGO DE HIGH OR LOW...]" << endl;
    cout << "Aquí correrá el juego" << endl;
    cout << "Presiona ENTER para regresar al menu del casino...";
    cin.ignore();
    cin.get();
}

void jugarLuckyShot() {
    cout << "\n[ENTRANDO AL JUEGO DE LUCKY SHOT...]" << endl;
    cout << "corre el juego" << endl;
    cout << "Presiona ENTER para regresar al menu del casino...";
    cin.ignore();
    cin.get();
}

int main()
{
   SetConsoleOutputCP(65001);
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
    cout << "│ 🃏 Haz elegido          Poker (Five-Card Draw)            │" << endl;
    cout << "├────────────────────────────────────────────────────────────┤" << endl;
    cout << "│ ✨ La suerte puede estar de tu lado. Piensa rapido,        │" << endl;
    cout << "│    arma tu mejor jugada. ¡¡¡VE POR EL JACKPOT!!! ✨        │" << endl;
    cout << "╰────────────────────────────────────────────────────────────╯" << endl;
    jugarPoker();
    break;

case 2:
    cout << "╭────────────────────────────────────────────────────────────╮" << endl;
    cout << "│ 🎲 Haz elegido         High or Low (Mayor o Menor)         │" << endl;
    cout << "├────────────────────────────────────────────────────────────┤" << endl;
   cout << "│🔥Los dados están en el aire.  ¿El total será mayor o menor?│" << endl;
    cout << "│    ¡Arriesga, siente la adrenalina y duplica tus premios!🔥│" << endl;
    cout << "╰────────────────────────────────────────────────────────────╯" << endl;
    jugarHighLow();
    break;

      case 3:
    cout << "╭────────────────────────────────────────────────────────────╮" << endl;
    cout << "│ 🎲 Haz elegido                  Lucky Shot                 │" << endl;
    cout << "├────────────────────────────────────────────────────────────┤" << endl;
    cout << "│    ¡Un solo tiro, una sola oportunidad! TODO O NADA        │" << endl;
    cout << "│    ¡Lanza con fuerza y deja que brille tu suerte!          │" << endl;
    cout << "╰────────────────────────────────────────────────────────────╯" << endl;
    jugarLuckyShot();
    break;
case 4:
            cout << "╭────────────────────────────────────────────────────────────╮" << endl;
            cout << "│ 🚪 Saliendo del Casino Virtual...                          │" << endl;
            cout << "├────────────────────────────────────────────────────────────┤" << endl;
            cout << "│    ¡Gracias por jugar! Vuelve pronto a probar tu suerte.   │" << endl;
            cout << "╰────────────────────────────────────────────────────────────╯" << endl;
      break;

      default:
         cout << "--------------ERROR. porfavor elegir solamente uno de los numeros propuestos----------" << endl;
         break;
      }

   } while (menu !=4);

   return 0;
}