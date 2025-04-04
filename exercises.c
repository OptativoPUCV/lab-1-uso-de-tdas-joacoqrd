#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
   List* L = create_list(); 
   for (int i = 1 ; i <= 10 ; i++){ 
      int* num = (int*) malloc (sizeof(int));
      *(num) = i;
      pushBack(L, num);
   }
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   //recorrer y sumar, debo crear un contador
   int suma = 0;
   int* elemento = first(L);

   while (elemento != NULL){
      suma = suma + *elemento;
      elemento = next(L);
   }
   return suma;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
   int* eleList = first(L);

   while (eleList != NULL){
      if (*eleList == elem){
         popCurrent(L);
      }
      eleList = next(L);
   }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
   Stack* aux = create_stack();
   Stack* aux2 = create_stack();
   int* dato = top(P1);
   
   //pasar P1 a aux y aux 2
   while (dato != NULL){
      push (aux, dato);
      push (aux2, dato);
      pop(P1);
      dato = top(P1);
   }
   int* datoPasar = top(aux);
   
   //pasar aux a P2 y P1
   while (datoPasar != NULL){
      push (P2, datoPasar);
      push (P1, datoPasar);
      pop(aux);
      datoPasar = top(aux);
   }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   Stack* pila = create_stack();
   int longitud = strlen(cadena);
   

   if (longitud % 2 != 0) {
       return 0;
   }

   for (int i = 0; cadena[i] != '\0'; i++){
      char parentesis = cadena[i];
     
      // Caso de apertura: guardar el carácter en la pila
      if (parentesis == '(' || parentesis == '{' || parentesis == '['){
        
         char* dato = (char *)malloc(sizeof(char));
         if (dato == NULL) {
     
            return 0;
         }
         *dato = parentesis;
         push(pila, dato);
      }
      else if (parentesis == ')' || parentesis == '}' || parentesis == ']'){
     
         if(top(pila) == NULL){
            return 0;
         }
         
      
         char* arriba = (char *)pop(pila);
         char apertura = *arriba;


         if ((parentesis == ')' && apertura != '(') ||
             (parentesis == '}' && apertura != '{') ||
             (parentesis == ']' && apertura != '[')) {
            return 0;
         }
      }
   }

   if (top(pila) == NULL){
      return 1;
   }
   else{
      return 0;
   }
}

