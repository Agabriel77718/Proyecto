#include <iostream>
#include <windows.h>
using namespace std;

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
    cout << "│ 🃏 Haz elegido     Video Poker (Five-Card Draw)            │" << endl;
    cout << "├────────────────────────────────────────────────────────────┤" << endl;
    cout << "│ ✨ La suerte puede estar de tu lado. Piensa rapido,        │" << endl;
    cout << "│    arma tu mejor jugada. ¡¡¡VE POR EL JACKPOT!!! ✨        │" << endl;
    cout << "╰────────────────────────────────────────────────────────────╯" << endl;
    break;

case 2:
    cout << "╭────────────────────────────────────────────────────────────╮" << endl;
    cout << "│ 🎲 Haz elegido         High or Low (Mayor o Menor)         │" << endl;
    cout << "├────────────────────────────────────────────────────────────┤" << endl;
   cout << "│🔥Los dados están en el aire.  ¿El total será mayor o menor?│" << endl;
    cout << "│    ¡Arriesga, siente la adrenalina y duplica tus premios!🔥│" << endl;
    cout << "╰────────────────────────────────────────────────────────────╯" << endl;
    break;

      case 3:
    cout << "╭────────────────────────────────────────────────────────────╮" << endl;
    cout << "│ 🎲 Haz elegido                  Lucky Shot                 │" << endl;
    cout << "├────────────────────────────────────────────────────────────┤" << endl;
    cout << "│    ¡Un solo tiro, una sola oportunidad! TODO O NADA        │" << endl;
    cout << "│    ¡Lanza con fuerza y deja que brille tu suerte!          │" << endl;
    cout << "╰────────────────────────────────────────────────────────────╯" << endl;
    break;

      default:
         cout << "--------------ERROR. porfavor elegir solamente uno de los numeros propuestos----------" << endl;
         break;
      }

   } while (menu < 1 || menu > 3);

   return 0;
}
