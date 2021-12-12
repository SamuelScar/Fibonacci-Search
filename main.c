#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int menor(int x, int y){ return x <= y ? x : y; }

int fibonaccianSearch(int array[], int elementSearch, int n)
{
     // Inicializando os numeros de Fibonacci
     int k2 = 0; // k-2
     int k1 = 1; // k-1
     int k = k2 + k1; // k

     int desloca = -1;
     /* fbK is going to store the smallest Fibonacci
  number greater than or equal to n */
     while (k < n){

         k2 = k1;
         k1 = k;
         k = k2 + k1;

     }

     while (k > 1){

         int i = menor(desloca + k2, n - 1);

         // Se o elemento procurado for maior
         if (array[i] < elementSearch){

             k = k1;
             k1 = k2;
             k2 = k - k1;
             desloca = i;

         }

         // Se o elemento procurado for menor
         else if (array[i] > elementSearch){

             k = k2;
             k1 = k1 - k2;
             k2 = k - k1;

         }

         //Achou o elemento
         else return i;

     }

     // Verificando o ultimo elemento
     if(k1 && array[desloca + 1] == elementSearch)
         return desloca + 1;

     // Elemento não encontrado
     return -1;
}


void limpatela(){ system("clear"); }

void printaArray(int array[], int tamanhoArray){

    for(int i = 0; i < tamanhoArray; i++){
        printf("[%d]", array[i]);

        if((i != 0) && (i % 20 == 0)){
            printf("\n");
        }

    }

    printf("\n\n");

}
//------------------------------------------------------------ MAIN --------------------------------------------------//

int main(){
    
    int escolha,tamanhoArray, elementSearch;
    bool loop = true;

    printf("Quantidade de elementos do array: ");
    scanf( "%d" , &tamanhoArray);
    int array[tamanhoArray];
    for(int i = 0 ;i < tamanhoArray ;i++){ array[i] = i; }

    while(loop){

        limpatela();
        //printf("1 - Preencher array\n");
        printf("2 - Procurar elemento\n");
        printf("3 - Exibir array\n");
        printf("Escolha: ");
        
        scanf( "%d" , &escolha );

        switch (escolha){

        case 1 :


        break;

        case 2 :

            printf("\nElemento que procura: ");
            scanf( "%d", &elementSearch);
            fibonaccianSearch(array, elementSearch, tamanhoArray);

            if(elementSearch != -1){

                limpatela();
                printf("Achado o elemento: %d\n\n", elementSearch);

            }else{

                limpatela();        
                printf("Elemento não encontrado");

            }

        break;

        case 3 :

            printaArray(array,tamanhoArray);

        break;
        
        default:
            printf("Opção invalida, escolha outra\n");
        break;
        
        }
    }

    return 0;
}