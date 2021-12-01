#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


/* This function used to find mininum of given number */
int menor(int x, int y){
    return x<=y ? x : y;
}


/* Returns index of x if present, else returns -1 */
int fibonaccianSearch(int array[], int x, int n)
{
     /* Here fibonacci numbers are initializing*/
     int fbK2 = 0; // (k-2)'th Fibonacci number
     int fbK1 = 1; // (k-1)'th Fibonacci number
     int fbK = fbK2 + fbK1; // k'th Fibonacci
     // Marks the eliminated range from front
     int offset = -1;
     /* fbK is going to store the smallest Fibonacci
  number greater than or equal to n */
     while (fbK < n)
     {
         fbK2 = fbK1;
         fbK1 = fbK;
         fbK = fbK2 + fbK1;
         }
     while (fbK > 1)
     {
         // Check if fbK2 is a valid location
         int i = menor(offset+fbK2, n-1);
         /* If x is greater than the value at index fbK2,
  cut the subarray array from offset to i */
         if (array[i] < x)
         {
             fbK = fbK1;
             fbK1 = fbK2;
             fbK2 = fbK - fbK1;
             offset = i;
             }
         /* If x is greater than the value at index fbKk2,
  cut the subarray after i+1 */
         else if (array[i] > x)
         {
            fbK = fbK2;
             fbK1 = fbK1 - fbK2;
             fbK2 = fbK - fbK1;
             }
         /* element found. return index */
         else return i;
         }
     /* comparing the last element with x */
     if(fbK1 && array[offset+1] == x)
     return offset+1;
     /*element not found. return -1 */
     return -1;
}
//------------------------------------------------------------ MAIN --------------------------------------------------//

int main(){

     int tamanhoArray, elementSearch;

    printf("Quantidade de elementos so array: ");
    scanf("%d",&tamanhoArray);
    int array[tamanhoArray];

    for(int i = 0 ;i < tamanhoArray ;i++){
        array[i] = i;
    }

    printf("\nElemento que procura: ");
    scanf("%d",&elementSearch);

    printf("Found at index: %d",fibonaccianSearch(array, elementSearch, tamanhoArray));
    getch();
    free(array);
return 0;
}