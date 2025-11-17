#include <stdlib.h>
#include <stdio.h>

//  Funzione per trovare il massimo tra due numeri
int max(int a, int b){
    return (a > b) ? a : b;
}

//  Funzione che risolve il problema del taglio delle aste con programmazione dinamica
int cutRod(int price[], int n){
    int dp[n+1];    //  Array per memorizzare i valori massimo
    dp[0] = 0;          //  Valore massimo per asta di lunghezza 0 è 0

    //  Riempimneto dell'array dp in modo bottom-up
    for(int i = 1; i <= n; i++){
        int max_val = -1;
        for (int j = 0; j < i; j++){
            max_val = max(max_val, price[j] + dp[i - j -1]);
        }
        dp[i] = max_val;
    }
    return dp[n];   //  il valore massimo per asta di lungehzza n
}

void printArray(int A[], int lenght){
    for (int i = 0; i < lenght; i++){
        printf("a[%d] = %d\n", i, A[i]);
    }
}

int main() {
    int n, a;

    printf("inserire il numero dei prezzi: ");
    scanf("%d",&n);

    //  Alloca dinamicamente l'array in base alla dimensione inserita
    int *A = (int *)malloc(n * sizeof(int));

    printf("Inserire i prezzi: \n");
    for (int i=0;i<n;i++){   
        scanf("%d",&A[i]);
    }

    printf("Elementi: \n");
    printArray(A,n);

    //  Taglio delle aste
    a = n;

    printf("Il valore massimo ottenibile e': %d\n", cutRod(A, a));
    return 0;
}