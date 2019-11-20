#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

void display(vector <int> );
int partition(vector <int>*, int, int );
void quickSort(vector <int>*, int, int);

int main(){
    vector <int> test1{1, 3, 17, -3, -5, -6, 8, 5, 7};

    display(test1);

    quickSort(&test1, 0, test1.size());
    display(test1);

    return 0;
}
void display (vector <int>  v){
    for(unsigned int i=0; i<v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int partition(vector <int>  *V, int pivot, int endV){
    int smaller = pivot + 1;
    int counter = 0;
    for(int i=pivot; i<endV; ++i){
        if((*V)[i]<(*V)[pivot]){
            int tmp = (*V)[i];
            (*V)[i] = (*V)[smaller];
            (*V)[smaller] = tmp;
            ++smaller;
            ++counter;
        }
    }

    int val = pivot;
    for(int i=val+1; i<=val+counter; ++i){
            int tmp = (*V)[i];
            (*V)[i] = (*V)[pivot];
            (*V)[pivot] = tmp;
            ++pivot;
    }
    return pivot;
}

void quickSort(vector <int> *v, int a, int b){
    if(a!=b){
        int part = partition(v, a, b);
        quickSort(v, a, part);
        quickSort(v, part+1, b);
    }
}
