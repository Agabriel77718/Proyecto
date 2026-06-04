#include <iostream>
#include <windows.h>

using namespace std;

int main() { 
    int intentos = 3;
    int dado1=4, dado2=4;
   

    cout << "===Bienvenido al juego de los dados===" << endl;


 cout<<"Dado1:"<<dado1<<endl;
cout<<"Dado2:"<<dado2<<endl;
cout<<"Tu puntuacion final es "<<dado1 + dado2<<endl;

 if (dado1 + dado2 >= 8) {
 cout <<"Superaste el objetivo! GANASTE" << endl;
 } else {
 cout << ">> No superaste 8." << endl;
 }


    return 0;
}