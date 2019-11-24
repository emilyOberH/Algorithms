#include <iostream>
#include <vector>
using namespace std;

void display(int *, int);
void heapSort(int *, int);
int check(int *, int, int);
void swap(int *, int);

int main()
{
    int n = 7;
    int sorted[7] = {10, 3, 13, 1, 11, 11, 12};
    display(sorted, n);
    do{
        heapSort(sorted, n);
        swap(sorted, n);
        --n;
    }while(n>1);
    n = 7;
    display(sorted, n);

    return 0;
}

void heapSort(int *arr, int n)
{
    for(int i=n-1; i>=0; --i)
    {
        check(arr, i, n);
        int recursive = 0;
        while(recursive != n){
            recursive = check(arr, recursive, n);
        }

    }
}

void display(int *arr, int n)
{
    for(int i=0; i<n; ++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int check(int *arr, int i, int n){
        //int ind = (i-1)/2;
        int childL = 2*i+1;
        int childR = 2*i+2;
        if(childL<n||childR<n){
            int biggest = (childL<n&&childR>=n)?childL:(childL>=n&&childR<n)?childR:(arr[childL]>=arr[childR])?childL:childR;
            int val = arr[biggest];
            if(val>arr[i]){
                //cout<<" "<<i<<" "<<biggest<<endl;
                int tmp = arr[biggest];
                arr[biggest] = arr[i];
                arr[i] = tmp;
                return biggest;
            }
        }
        return n;
}

void swap(int * arr, int m){
    int tmp = arr[0];
    arr[0] = arr[m-1];
    arr[m-1] = tmp;
}
