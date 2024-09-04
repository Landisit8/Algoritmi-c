//  couting sort

#include <stdio.h>
#include <stdlib.h>

//  Funzione per l'ordinamento Counting Sort
void CountingSort(int A[], int n){
    int i, B[n];

    //  Trova l'elemento massimo nell'array
    int max = A[0];
    for (i = 1; i < n; i++)
        if (A[i] > max){
            max = A[i];
    }

     //  Crea e inizializza l'array di conteggio
    int count[max + 1];
    for (i = 0; i <= max; i++){
        count[i] = 0;
    }

    //  Memorizza il numero di occorrenze di ciascun elemento nell'array di conteggio
    for (i = 0; i < n; i++){
        count[A[i]]++;
    }

    //  Aggiorna l'array di conteggio per memorizzare le posizioni corrette
    for (i = 1; i <= max; i++){
        count[i] = count[i] + count[i-1];
    }

    //  Costruisce l'array ordinato
    for (i = n - 1; i >= 0; i--){
        B[--count[A[i]]] = A[i];
    }

    //  Copia gli elementi ordinati dall'array B all'array originale A
    for (i = 0; i < n; i++){
        A[i] = B[i];
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

    //  Ordinamento Counting Sort
    CountingSort(A,n);

    printf("Elementi ordinati: \n");
    printArray(A,n);

    //  libera memoria allocata
    free(A);
    
    return 0;
}