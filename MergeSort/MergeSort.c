// Merge Sort

#include <stdio.h>
#include <stdlib.h>

//  Funzione per unire due sottoarray
void merge(int A[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    //  Creazione degli array temporanei
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    //  Copia dei dati negli array temporanei L[] e R[]
    for (int i = 0; i < n1; i++){
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = A[q + 1 + j];
    }

    //  Unisci gli array temporanei
    int i = 0;  //  Indice iniziale del primo sotto-array
    int j = 0;  //  Indice iniziale del secondo sotto-array
    int k = p;  //  Indice iniziale del sotto-array unito

    while (i < n1 && j < n2){
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    //  Copia i restanti elementi di L[], se ci sono
    while (i < n1){
        A[k] = L[i];
        i++;
        k++;
    }

    //  Copia i restanti elementi di R[], se ci sono
    while (j < n2){
        A[k] = R[j];
        j++;
        k++;
    }
    //  Libera la memorai allocata
    free(L);
    free(R);
}

//  Funzione principale che implementa il MergeSort
void merge_sort(int A[], int p, int r){
    if (p < r){
        //  Trova il punto di mezzo
        int q = (p + r) / 2;

        //  Ordina la prima e la seconda metà
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);

        //  Unisci le metà ordinate
        merge(A, p, q, r);
    }
}

void printArray(int A[], int lenght){
    for (int i = 0; i < lenght; i++){
        printf("a[%d] = %d\n", i, A[i]);
    }
}

int main(){
    int n,p=0;

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

    merge_sort(A,p,n - 1);

    printf("Elementi ordinati:\n");
    printArray(A,n);

    //  libera la memoria allocata
    free(A);
}