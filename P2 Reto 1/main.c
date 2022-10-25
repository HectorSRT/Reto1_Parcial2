#include <stdio.h>
#include <stdlib.h>

int busqueda_binaria(int arr[], int x, int n);
void quicksort(int arr[], int l, int r);
int particion(int arr[], int l, int r);
void swap(int *arr, int *arrG);

int main()
{
    int arr[6], x, n=5, y;
    arr[0]=1;
    arr[1]=3;
    arr[2]=5;
    arr[3]=6;
    scanf("%d", &x);
    if(busqueda_binaria(arr,x,n)==-1){
        arr[4]=x;
        quicksort(arr,0,n-1);
        y=busqueda_binaria(arr,x,n);
        printf("%d", y);
    }else{
        y=busqueda_binaria(arr,x,n);
        printf("%d", y);
    }
    return 0;
}

int busqueda_binaria(int arr[], int x, int n){
    int p=0, r=n-1;
    while(p<=r){
        int q=(p+r)/2;
        if(arr[q]==x){
            return q;
        }
        if(arr[q]>x){
            r=q-1;
        }else{
            p=q+1;
        }
    }
    return -1;
}

void quicksort(int arr[], int l, int r){
    if(r<=l){
        return;
    }
    int p=particion(arr, l, r);
    quicksort(arr,l,p-1);
    quicksort(arr,p+1,r);
}

int particion(int arr[], int l, int r){
    int i=l;
    for (int j=l;j<=r-1;j++){
        if(arr[j]<=arr[r]){
            swap(&arr[j],&arr[i]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

void swap(int *arr, int *arrG){
    int t=*arr;
    *arr=*arrG;
    *arrG=t;
}
