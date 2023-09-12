#include <iostream>
#include <vector>
using namespace std;
int d,sum;
vector<int>mim;
vector<int>max;
int main(){

    cin >> d >> sum;
    
    for(int i = 0; i < d; i++){
        int minimo, maximo;
        cin >> minimo >> maximo;
        min.push_back(minimo);
        max.push_back(maximo);
    }

    for(int i = 0; i < n; i++){
        verify(min[i],max[i]);
    }
}
