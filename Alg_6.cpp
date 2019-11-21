#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

void display(vector <int> );
vector <int> mergeSort(vector <int> *, int, int);
void partition(vector <int>  *, int, int);

int main()
{
    vector <int> a{1, 2, 8, 7, 33, 66, 120};

    display(a);
    display(a);

    return 0;
}
void display (vector <int>  v)
{
    for(unsigned int i=0; i<v.size(); ++i)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}



