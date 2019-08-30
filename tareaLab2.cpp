#include <iostream>
#include <stdio.h>
#include <array>
using namespace std;

/**
 *  Escribir un programa que le pida enteros al usuario, guarde los números pares
 * en una  pila y los impares en otra pila.
 * Determianr si la cantidad de ambas pilas es igual
 */
struct Nodo{
    int dato;
    Nodo *sig;
}*inicio;

struct NodoI{
    int dato;
    NodoI *sig;
}*inicioI;


class Pila{
    public:
        Nodo* crearNodo(int valor){
            Nodo *n = new Nodo;
            n -> dato = valor;
            n -> sig = nullptr;
            return n;
        }

        void push(int valor){
            Nodo *n = crearNodo(valor);
            n->sig = inicio;
            inicio = n;
        }
        

        void pop(){
            Nodo *temp = inicio;
            inicio = inicio -> sig;
            free(temp);
        }
        


        void mostrarPila(){
            Nodo *temp = inicio;
            if(!inicio){
                cout<<"Pila vacia"<<endl;
            } else{
                while(temp){
                    cout<<temp->dato<<", ";
                    temp = temp->sig;
                }
            }
        }



};
class PilaI{
    public:
        NodoI* crearNodoI(int valor){
            NodoI *nI = new NodoI;
            nI -> dato = valor;
            nI -> sig = nullptr;
            return nI;
        }
        
        void pushI(int valor){
            NodoI *nI = crearNodoI(valor);
            nI->sig = inicioI;
            inicioI = nI;
        }
        void popI(){
            NodoI *temp = inicioI;
            inicioI = inicioI -> sig;
            free(temp);
        } 
        void mostrarPilaI(){
            NodoI *temp = inicioI;
            if(!inicioI){
                cout<<"Pila vacia"<<endl;
            } else{
                while(temp){
                    cout<<temp->dato<<", ";
                    temp = temp->sig;
                }
            }
        }
};
bool esPar(int num){
    if(num % 2 == 0){
        return true;
    }else{
        return false;
    }
}

void manipulaArray(int enteros[], int cant, Pila PPares, PilaI PImpares){
    int pares = 0, impares = 0;
    for (int i = 0; i < cant; i++){
        //cout<<"Esto hay en el array: "<<enteros[i]<<endl;
        if(esPar(enteros[i])){
            PPares.push(enteros[i]);
            pares++;
        }else{
            PImpares.pushI(enteros[i]);
            impares++;
        }
    }
    if(pares == impares){
        cout<<"Hay mismo número de pares " <<endl;
    }else if(pares > impares){
        cout<<"Hay más pares: " <<pares<<" números"<<endl;
    }else{
        cout<<"Hay más impares: " <<impares<<" números"<<endl;
    }
}
int main(){
    Pila PPar;
    PilaI PImpar;
    int cant = 0, flag = 1, num = 0, itera = 0;
    cout<<"¿Cuántos números enteros ingresará?"<<endl;
    cin >> cant;
    cout<<"Para dejar de ingresar números, ingresa el número cero"
        <<endl<<"Empieza a ingresar numeros: "<<endl;
    int enteros[cant];
    while(itera < cant){
        cin >> num;
        enteros[itera] = num;
        itera++;
    }
    manipulaArray(enteros, cant, PPar, PImpar);   
    cout<<"Pila Par: "<<endl;
    PPar.mostrarPila();

    cout<<endl<<"-------------------"<<endl<<"Pila Impar: "<<endl;
    PImpar.mostrarPilaI();
    cout<<endl;
    return 0;
}