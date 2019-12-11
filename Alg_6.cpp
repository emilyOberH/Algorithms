#include <iostream>
#include <vector>

using namespace std;

void display(vector <int> );
vector <int> merge(vector <int> , vector <int> );
vector <int> mergeSort(vector <int> );

int main()
{
    vector <int> a{1, 20, 8, -7, 33, 0, 66, 120};
    vector <int> tmp1{5, 10, 12};
    vector <int> tmp2{6, 9, 15};

    display(a);

    display(mergeSort(a));

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

vector <int> merge(vector <int> a, vector <int> b){
    vector <int> c;
    while(a.size()>0&&b.size()>0){
        if(a[0]<=b[0]){
            c.push_back(a[0]);
            a.erase(a.begin());
        }else if(b[0]<a[0]){
            c.push_back(b[0]);
            b.erase(b.begin());
        }
    }

    while(a.size()>0){
        c.push_back(a[0]);
        a.erase(a.begin());
    }
    while(b.size()>0){
        c.push_back(b[0]);
        b.erase(b.begin());
    }
    return c;
}

vector <int> mergeSort(vector <int> v){
    if(v.size()==1){
        return v;
    }

    vector <int> a;
    vector <int> b;
    unsigned int part = v.size()/2;
    for(unsigned int i=0; i<v.size(); ++i){
        if(i<part){
            a.push_back(v[i]);
        }else{
            b.push_back(v[i]);
        }
    }

    a = mergeSort(a);
    b = mergeSort(b);

    return merge(a, b);
}
