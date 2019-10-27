#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

void bubbleSort(int *, int);
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
    bubbleSort(A, n);
    display(A, n);

    delete []A;
    return 0;
}



void bubbleSort(int *A, int n){
    int counter = 1;
    int last = n-1;
    while(1){
        if(counter==0){
            break;
        }else{
            counter = 0;
            for(int i=0; i<last; ++i){
                if(A[i]>A[i+1]){
                    swap(A, i, i+1);
                    ++counter;
                }
            }
            --last;
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
