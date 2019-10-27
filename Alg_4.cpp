#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

void insertionSort(int *, int);
void swap(int *, int, int);
void display(int *, int);

int main(){
    srand(time(NULL));
    int n = 10;
    int *A = new int[n];
    for(int i=0; i<n; ++i){
        A[i] = rand()%250;
    }

    display(A, n);
    insertionSort(A, n);
    display(A, n);

    delete []A;
    return 0;
}



void insertionSort(int *A, int n){
    int size = 2;
   if(A[0]>A[1]){
        swap(A, 0, 1);
   }
   if(n>2){
        int part = size;
        while(size<n){
            int counter = 0;
            for(int i=0; i<size; ++i){
                if(A[i]>=A[size]){
                    part = i;
                    ++counter;
                    break;
                }
            }
            if(counter>0){
                for(int j=part; j<size; ++j){
                    swap(A, j, size);
                }
            }
            ++size;
        }
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
