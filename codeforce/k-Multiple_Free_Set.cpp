#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, k;
vector<int>v;

bool isvalidate(int i , int j){
    bool isok = true;
    for(int l = i; l < j; l++ ){
        if(v[l] * k == v[j]){
            isok = false;
            break;
        }
    }

    return isok;
}

int main(){
    
    cin >> n >> k;

    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }

    int i = 0;
    int j = 1;
    int cont = 1;
    int bestcont = 1;
    while(true){
        if(j == n){
            break;
        }

        if(isvalidate(i,j)){
            cont++;
            j++;
        }else{
            cont = 1;
            i = j;
            j++;
        }

        bestcont = max(cont,bestcont);

    }

    cout << bestcont << endl;
}