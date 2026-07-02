#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

void LanzarDados() {
int dado1 = (rand() % 6) + 1; 
int dado2 = (rand() % 6) + 1;
int suma = dado1 + dado2;

cout<<"====✨🎊Resultados🎊✨===="<<endl;
cout<<"⬜Dado 1:"<<dado1 << "⬜"<<endl;
cout<<"⬛Dado 2:"<<dado2 << "⬛"<<endl;
cout<<"⬜Suma:  "<<suma  << "⬜"<<endl;

if (suma >= 8) {
cout << "🟥🔥🏅Ganaste🏅🤩" << endl;
cout << "||=================||" << endl;
} else {
cout << "🟩😞Perdiste🎭😢" << endl;
cout << "||==================||" << endl;   
}
}

int main() {
SetConsoleOutputCP(CP_UTF8); //Codigo que permite que los emojis aparezac
srand(time(0));// Inicia la semilla para que se generen los números aleatorios
char opcion = 0;// igual a 0 pera evitar basura
cout<<" == 🎲🎰 Bienvenido a Lucky Shot 🎰🎲 == "<<endl;
cout<<"🟥 ===========================🍀"<<endl;
cout<<"⬛=== CASINO DE DADOS ==== 🎲" << endl;
cout<<"🟥Si la Suma >= 8 = Ganas  ☘️" << endl;
cout<<"⬛Si la Suma <= 7 = Pierdes🎲" << endl;
cout<<"🟥=========================🍀" << endl;

while (opcion != 'E' && opcion != 'e') {
cout << "Presione 'P' para jugar o 'E' para salir: ";
cin >> opcion;

if (opcion == 'P' || opcion == 'p') {
LanzarDados (); // Manda a llamar la funcion 
}
else if (opcion == 'E' || opcion == 'e') {
cout<<"Gracias por jugar al Lucky Shot"<<endl;
}
else {
cout << "Opcion no valida. Por favor, presione 'P' para jugar o 'E' para salir." << endl;
}
}
cout << "Que tengas un buen dia, Dios te ama. " << endl;
return 0;
}