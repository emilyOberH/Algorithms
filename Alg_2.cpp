#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>

using namespace std;

void display(int *, int);
int partitionArr(int *, int , int );
void quickSort(int *, int , int );

int main(){
    srand(time(NULL));
    int n = 10;
    int arr[10];

    for(int i=0; i<10; ++i){
        arr[i] = rand()%250;
    }

    display(arr, n);
    int first = 0;
    int last = n-1;

    quickSort(arr, first, last);

    display(arr, n);

    return 0;
}

void quickSort(int *A, int first, int last){
    if(first<last){
        int part = partitionArr(A, first, last);
        //cout<<part-1<<endl;
        //display(A, 10);
        if(first<part-1){
            quickSort(A, first, part-1);
        }
        if(last>part+1){
            quickSort(A, part+1, last);
        }
        //++first;
        //--last;
    }
}

void display(int *A, int n){
    for(int i=0; i<n; ++i){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int partitionArr(int *arr, int first, int last){
    int i = first;
    int pivot = rand() % (last-first+1) + first;
    cout<<pivot<<endl;
    int tmp = arr[last];
    arr[last] = arr[pivot];
    arr[pivot] = tmp;

    for(int j=first; j<last; ++j){
            if(arr[j]<arr[last]){
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
                ++i;
            }
    }
    tmp = arr[i];
    arr[i] = arr[last];
    arr[last] = tmp;

    //cout<<i<<endl;
    return i;
}
