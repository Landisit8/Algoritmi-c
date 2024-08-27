// quicksort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  Funzione per scambiare due elementi
void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//funzione per la partizione dell'array
int partition(int A[], int low, int high){
    int pivot = A[high];    //  scegliamo l'ultimo elemento come pivot
    int i = (low - 1);  //  indice dell'elemento più piccolo

    for (int j = low; j < high; j++){
        //  se l'elemento corrente è minore o uguale al pivot
        if (A[j] <= pivot){
            i++;    //  incrementa l'indice dell'elemento più piccolo
            swap(&A[i],&A[j]);  
        }
    }
    //  Scambia il pivot con l'elemento alla posizione i + 1
    swap(&A[i+1],&A[high]);
    return (i + 1); //  restituisce l'indice del pivot
}

//  Funzione per la partizione randomizzata
int randomizedPartition(int A[], int low, int high){
    int random_index = low + rand() % (high - low + 1); //  scelgi un pivot casuale
    swap(&A[random_index],&A[high]);    //  scambia il pivot casuale con l'ultimo elemento
    return (partition(A,low,high)); //  Chiama la partizione standard
}

//  Funzione quicksort principale
void quicksort(int A[], int low, int high){
    if(low < high){
        //  ottieni l'indice del pivot
        int pivot = randomizedPartition(A,low,high);     // partition(A, low, high);

        //  ordina ricorsivamente gli elementi prima e dopo il pivot
        quicksort(A,low,pivot-1);
        quicksort(A,pivot,high);
    }
}

//  funzione per stampare l'array
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

    //  inizializza il generatore di numeri casuali
    srand(time(0));

    printf("Elementi non ordinati: \n");
    printArray(A,n);

    //  Ordinamento con heapsort
    quicksort(A,0,n-1);

    printf("Elementi ordinati: \n");
    printArray(A,n);

    //  Dealloca la memoria dell'array
    free(A);

    return 0;
}