/*El jugador debe alcanzar una Puntuación Objetivo (Blind) en cada ronda apostando fichas. 
Para lograrlo, seleccionará combinaciones de cartas de su mano (par, trío, color, full house). 
Cada combinación tiene un puntaje base y un multiplicador básico.*/
#include <iostream>
using namespace std;

int main (){
int cartas=14,manos=3,menu;
//no sera aleatorio,tendra un sistema de cartas ya definido
    cout<<"CASINO MONTERCARLOJUANCARLO"<<endl;
    do
    {
      
     cout<<"Porfavor elige el modo que deseas jugar"<<endl;
     cout<<"1.high or low"<<endl;
     cout<<"2.Lucky"<<endl;
     cout<<"3.Poker"<<endl;
     cin>>menu;


     switch (menu)
     {
     case 1:
        cout<<"Bienvenido a high or low"<<endl;
        /*elegir carta al azar y decidir si sera alta o baja y dependiendo 
        si el usuario adivina lo que sera la carta pues ganara y si no lo lograra perderia*/
        break;
     case 2:
        cout<<"Lucky"<<endl;
        /*tirar dados al azar 3 veces por lo menos y dependiendo de la suma de los dados
        si logra un puntaje igual o mayor al respectivo puntaje ganara y si es menor perdera*/
        break;
     case 3:
        cout<<"Poker"<<endl;
        /*se otorgaran 5 cartas y se iran descartando */
        break;      
     
     default:
       cout<<"ERROR. Porfavor seleccionar una de las opciones dadas"<<endl;
        break;
     }

} while (menu<1 || menu >3);
   
    
    



    return 0;
}
