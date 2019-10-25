#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

void selectionSort(int *, int);
void swap(int *, int, int);
void display(int *, int);

int main(){
    srand(time(NULL));
    int n = 10;
    int A[n];
    for(int i=0; i<n; ++i){
        A[i] = rand()%250;
    }
    display(A, n);
    selectionSort(A, n);
    display(A, n);


    return 0;
}

void selectionSort(int *A, int n){
    int part = 0;
    while(part<n){
        int small = A[part];
        int ind = part;
        for(int i = part; i<n; ++i){
            if(A[i]<small){
                small = A[i];
                ind = i;
            }
        }
        swap(A, part, ind);
        ++part;
    }

}

void swap(int *A, int a, int b){
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

void display(int *A, int n){
    for(int i=0; i<n; ++i){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
