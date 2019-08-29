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
    Nodo *prev;
}*inicio, *fin;

bool esPar(int num){
    if(num % 2 == 0){
        return true;
    }else{
        return false;
    }
}

int manipulaArray(int enteros[], int cant){
    for (int i = 0; i < cant; i++){
        cout<<"Esto hay en el array: "<<enteros[i]<<endl;
        if(esPar(enteros[i])){
            //ingresar a la cola de pares
        }else{
            //ingresar a la cola de impares
        }
    }
}
int main(){
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
    manipulaArray(enteros, cant);   
    
    return 0;
}