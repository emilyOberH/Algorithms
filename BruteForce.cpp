#include <iostream>
#include <vector>

using namespace std;

int main(){
    char text[] = "aabcdgbafabcd";
    char pattern[] = "abc";
    vector <int> ind;

    int sizeP = sizeof(pattern)/sizeof(*pattern)-1;
    int sizeT = sizeof(text)/sizeof(*text)-1;

    int counter = 0;

    int inner = 0;
    for(int i = 0; i<sizeT; ++i){
        if(pattern[inner]==text[i]){
            ++inner;
        }else{
            if(inner!=0){
                inner = 0;
                --i;
            }
        }
        if(inner==sizeP){
            ind.push_back(i-sizeP+1);
        }
    }

    cout<<"Indexes found: ";
    for(auto j = 0; j<ind.size(); ++j){
        cout<<" "<<ind[j]<<", ";
    }
    return 0;
}
