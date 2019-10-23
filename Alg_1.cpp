#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <ctime>
using namespace std;

void display(int *, int);
int partitionArr(int *, int, int *, int *, int);
int quickSelect(int *, int, int *, int *, int);

int main(){
    srand(time(NULL));
    int n = 10;
    int arr[10];

    for(int i=0; i<10; ++i){
        arr[i] = rand()%250;
    }
    display(arr, n);

    int k = 0;
    while(k<1||k>n){
        cout<<"Looking for n-th largest number.\nEnter n: ";
        cin>>k;
    }

    int first = 0;
    int last = n-1;
    int  g = quickSelect(arr, k, &first, &last, n);

    cout<<"The "<<k<<"-largest number in array is: "<<arr[g]<<endl;

    //display(arr, n);

    return 0;
}

void display(int *A, int n){
    for(int i=0; i<n; ++i){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int quickSelect(int *arr, int k, int *first, int *last, int n){
    int g = 0;
    while(((*last)!=(*first))){
        g = partitionArr(arr, k, first, last, n);
    }
    return g;
}


int partitionArr(int *arr, int k, int *first, int *last, int n){
    int ind = n-k;

    int i = (*first);
    int pivot = rand() % ((*last)-(*first)+1) + (*first);
    int tmp = arr[(*last)];
    arr[(*last)] = arr[pivot];
    arr[pivot] = tmp;

    for(int j=(*first); j<(*last); ++j){
            if(arr[j]<arr[(*last)]){
                int tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
                ++i;
            }
    }
    tmp = arr[i];
    arr[i] = arr[(*last)];
    arr[(*last)] = tmp;

    if(i+1==ind){
        (*last)=(*first);
    }else if(i<ind){
        (*first) = i+1;
    }else if(i>ind){
        (*last) = i-1;
    }

    return i+1;
}
