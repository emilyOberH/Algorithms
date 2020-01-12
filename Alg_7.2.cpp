#include <iostream>
#include <vector>
using namespace std;

void display(vector <int>, int);
void heapSort(vector <int> *, int);
void maxHeapify(vector <int> *, int, int);
void swap(vector <int> *, int, int);

int main()
{
    int n = 6;
    vector <int> sorted {1, 2, 3, 4, 5, 6};
    display(sorted, n);


    heapSort(&sorted, n);

    display(sorted, n);

    return 0;
}

void heapSort(vector <int> *arr, int n)
{
    for(int i=n/2; i>1; --i)
    {
        maxHeapify(arr, n, i);
    }

    int j=n;
    while(j>=1)
    {
        swap(arr, 0, j);
        --n;
        --j;
        maxHeapify(arr, n, 0);
    }
}

void display(vector <int> arr, int n)
{
    for(int i=0; i<n; ++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void maxHeapify(vector <int> *arr, int n, int i)
{
    int largest = i;
    int leftChild = i*2;
    int rightChild = i*2+1;

    if(leftChild<=n&&((*arr)[leftChild])>((*arr)[i]))
    {
        largest = leftChild;
    }
    else
    {
        largest = i;
    }
    if(rightChild<=n&&((*arr)[rightChild]>(*arr)[largest]))
    {
        largest = leftChild;
    }
    if(largest!=i)
    {
        swap(arr, i, largest);
        maxHeapify(arr, n, largest);
    }

}

void swap(vector <int> *arr, int n, int m)
{
    int tmp = (*arr)[n];
    (*arr)[n] = (*arr)[m];
    (*arr)[m] = tmp;
}
