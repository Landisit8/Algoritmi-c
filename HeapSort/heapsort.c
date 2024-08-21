//  HeapSort

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void maxheapify(int A[], int i, int size){
    int max = i;
    int left = i * 2;       //  Figlio sinistro
    int right = i * 2 + 1;  //  Figlio destro
    int temp;

    if (left < size && A[left] > A[max]){
        max = left;
    }
    if (right < size && A[right] > A[max]){
        max = right;
    } 
    if (max != i){
        //  Scambia A[i] e A[max]
        temp = A[i];
        A[i] = A[max];
        A[max] = temp;

        //  Chiama ricorsivamente maxheapify sull'albero sottostante
        maxheapify(A,max,size);
    }
}

void maxheap(int A[], int size){
    //  Costruisce l'heap partendo dalll'ultimo nodo non foglia
    for (int i = size / 2 - 1; i >= 0; i--){
        maxheapify(A, i, size);
    }
}

void heapsort(int A[], int size){
    int temp;

    // Costruisce l'heap massimo
    maxheap(A, size);

    //  Estrae elementi uno per uno dall'heap
    for (int i = size - 1; i > 0; i--){
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;

        //  richiama maxheapify sulla radice per riformare l'heap
        maxheapify(A,0,i);
    }
}

void printArray(int A[], int lenght){
    for (int i = 0; i < lenght; i++){
        printf("a[%d] = %d\n", i, A[i]);
    }
}

int main (){
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

    //  Ordinamento con heapsort
    heapsort(A,n);

    printf("Elementi ordinati: \n");
    printArray(A,n);

    return 0;
}