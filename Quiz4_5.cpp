//Elaborado por Ericka Yu Min

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <math.h>
using namespace std;

void radixSort(int *arr, int n, int max) {
    /*
    F(n)= max*(n+10)
    Complejidad = O(n)
    El loop invariant = Antes de entrar al ciclo for, el los digitos del arreglo se encuentran ordenados desde 0 hasta i-1 digitos.
    */

   int i, j, m, p = 1, index, temp, count = 0; //2t
   list<int> pocket[10];      //radix of decimal number is 10
//1t
   for(i = 0; i< max; i++) {//3t
      m = pow(10, i+1);//4t
      p = pow(10, i);//3t
//1t
      for(j = 0; j<n; j++) {//3t
         temp = arr[j]%m;//3t
         index = temp/p;      //find index for pocket array 2t
         pocket[index].push_back(arr[j]);//4t
      }
      count = 0;//1t
//1t
      for(j = 0; j<10; j++) {//3t
         //delete from linked lists and store to array
         while(!pocket[j].empty()) {//3t
            arr[count] = *(pocket[j].begin());//5t
            pocket[j].erase(pocket[j].begin());//5t
            count++;//2t
         }
      }
   }
}

void costo(vector<int> arrFila, vector<int> arrColumna){
    /*
    F(n) = 7+16n+13n
    Complejidad = O(n)
    Loop Invariant = Resultado se le suma elemento( fila/columna)*contador(vertial/horizontal)
    */
    int horizontal=1, vertical=1,resultado=0,contadorFila=0,contadorColumna=0,corte=0;//6 tiempos

    for(;contadorFila<arrFila.size()&&contadorColumna<arrColumna.size();){//5t
        if(arrFila[contadorFila]>arrColumna[contadorColumna]){//3 tiempos
            resultado+=arrFila[contadorFila]*vertical;//4
            horizontal++;//2 tiempos
            contadorFila++;//2t
        }//8t
        else{
            resultado+=arrColumna[contadorColumna]*horizontal;//4t
            vertical++;//2t
            contadorColumna++;//2t
        }//8t
    }//(5t+11t)n

    for(;contadorColumna+contadorFila<arrColumna.size()+arrFila.size();){//5t
        if(contadorFila<arrFila.size()){//2t
            resultado+=arrFila[contadorFila++]*vertical;//6t
        }
        else if(contadorColumna<arrColumna.size()){//2t
            resultado+=arrColumna[contadorColumna++]*horizontal;//6t
        }
    }//(5t+8t)n
    cout<<resultado;//1t
}

int main(){
    //vector<int> arrFila={6,5,8}, arrColumna{7,8};
    //vector<int> arrFila={4,7}, arrColumna={10,5,8};
    //vector<int> arrFila={20,40,60}, arrColumna={3,2,7,8,10};
    //vector<int> arrFila={4,7}, arrColumna={2,8,7,5,10,9};
    //vector<int> arrFila={4,1,2,2,4}, arrColumna={2,1,3,1,4,4};
    vector<int> arrFila={5,2,6,3,8,7}, arrColumna={1,3,2,1};
    //vector<int> arrFila={4,1,2}, arrColumna={2, 1, 3, 1, 4};
    //vector<int> arrFila={1}, arrColumna={2};
    //vector<int> arrFila={16,13,17,11,17}, arrColumna={20,17,12,19,19,18,11,10,13};
    sort(arrFila.begin(),arrFila.end(),greater<int>());
    sort(arrColumna.begin(),arrColumna.end(),greater<int>());
    costo(arrFila,arrColumna);

}

