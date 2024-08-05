//insertion Sort

#include<stdio.h>

void insertion_sort(int a[], int lenght){
    for (int j=1;j<lenght;j++){
       int key = a[j];
       int i = j-1;

       while (i >= 0 && a[i] > key){
        a[i+1] = a[i];
        i = i-1;
       }
       a[i+1]=key; 
    } 
}

void press(int a[], int lenght){
    for (int i=0;i<lenght;i++){
        printf("a[%d] = %d\n", i, a[i]);
    }
}

int main(){
    int a[10],n;

    printf("inserire la lunghezza dell'array: ");
    scanf("%d",&n);
    printf("inserire gli elementi:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    insertion_sort(a,n);
    press(a,n);
    return 0;
}