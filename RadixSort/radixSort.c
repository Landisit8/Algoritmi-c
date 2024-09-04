//  Radix Sort

#include <stdio.h>
#include <stdlib.h>

//  Funzione ausiliaria per trovare il massimo valore nell'array
int getMax(int A[], int n){
    int max = A[0];
    for (int i = 1; i < n; i++){
        if (A[i] > max){
            max = A[i];
        }
    }
    return max;
}

//  Funzione per eseguire il Counting Sort basato su un digit specifico (exp)
void coutingSortRadix(int A[], int n, int exp){
    int i;
    int B[n];   //  array di output
    int count[10] = {0}; //  array di conteggio per le cifre (0-9)

    //  conta il numero di occorrenze per ogni cifra (basata su exp)
    for(i = 0; i < n; i++){
        count[(A[i] / exp) % 10]++;
    }

    //  Modifica cout in modo che contenga le posizioni cumulative
    for (int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }

    //  Costruisci l'array di output B
    for (i = n - 1; i >= 0; i--){
        int digit = (A[i] / exp) % 10;
        B[--count[digit]] = A[i];
    }

    //  Copia gli elementi ordinati dall'array B all'array originali A
    for (i = 0; i < n; i++){
        A[i] = B[i];
    }
}

//  Funzione principale per eseguire il radix sort
void radixSort(int A[], int n){
    //  trova il massimo numero per determinare il numero di cifre
    int max = getMax(A, n);

    //  esegui il Counting Sort per ogni cifra (unita, decine, centinaia, ...)
    for (int i = 1; max / i > 0; i *= 10){
        coutingSortRadix(A, n, i);
    }
}

//  Funzione per stampare un array
void printArray(int A[], int lenght){
    for (int i = 0; i < lenght; i++){
        printf("a[%d] = %d\n", i, A[i]);
    }
}

int main(){
    int n;

    printf("inserire la lunghezza dell'array: ");
    scanf("%d",&n);

    //  Alloca dinamicamente l'array in base alla dimensione inserita
    int *A = (int *)malloc(n * sizeof(int));

    printf("Inserire gli elementi:\n");
    for (int i=0;i<n;i++){   
        scanf("%d",&A[i]);
    }

    printf("Elementi non ordinati: \n");
    printArray(A,n);

    //  Ordinamento Radix Sort
    radixSort(A,n);

    printf("Elementi ordinati: \n");
    printArray(A,n);

    //  libera memoria allocata
    free(A);
    
    return 0;
}