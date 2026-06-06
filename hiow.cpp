 /*elegir carta al azar y decidir si sera alta o baja y dependiendo 
 si el usuario adivina lo que sera la carta pues ganara y si no lo lograra perderia*/

 #include <iostream>
 
 using namespace std;

 int main (){
int menu;
int carta1=6;
int carta2=8;
int resultado;
// MENU para cuando el usuario quiera jugar pero por el momento solo jugar
     cout<<"OLA,BIENVENIDO A HIGHT O LOW"<<endl;
      cout<<"1.JUGAR UNA RONDA"<<endl;
      cout<<"2.SALIR DEL JUEGO"<<endl;
     cin>>menu;

     
     switch (menu){
     
     case 1:
         cout<<"la carta actul es:"<<carta1<<endl;
         cout<<"LA SIGUIENTE CARTA SERA ALTA(1) O BAJA(2)";
          cin>>resultado;

            cout<<"y la carta fueeeeeeeeeeeeeee unnnnnn:"<<carta2<<endl;
          

      if (carta2 > carta1 &&  resultado == 1)
      {
        cout<<"GANASTE 1000000000000 PESOS, ERA MAS ALTA"<<endl;
      }
      else if(carta2 < carta1 && resultado == 2)
      {
         cout<<"GANASTE 1000000000000 PESOS, ERA MAS BAJO"<<endl;
      }
      else {
        cout<<"PERDISTE,NO ACERTASTE"<<endl;
      }
      break;
        case 2 :
            cout<<"SALISTE DEL JUEGO"<<endl;
             break;
      
     default:
      cout<<"ERROR. OPCION INGRESADA NO VALIDA"<<endl;
       break;
       
     
  }
       return 0;
 }