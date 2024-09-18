#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int>semiprim;

bool bb(int n){
    int i = 0;
    int j = semiprim.size()-1;

    while(i <= j){
        int num = semiprim[i] + semiprim[j];
        if(num == n){
            return true;
        }

        if(num < n){
            i++;
        }else{
            j--;
        }
    }

    return false;
}

int main(){
    vector<int>prim;
    for(int i = 2; i <= 200; i++){
        bool isprime = true;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                isprime = false;
                break;
            }
        }

        if(isprime){
            prim.push_back(i);
        }
    }
    
    for(int i = 0; i < prim.size(); i++){
        for(int j = i + 1; j < prim.size(); j++){
            semiprim.push_back(prim[i] * prim[j]);
        }
    }  
    
    sort(semiprim.begin(),semiprim.end());
    vector<int>ans(202);

    for(int i = 1; i <= 200; i++){
        if(bb(i)){
            ans[i] = 1;
        }
    }

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n;
        cin >> n;

        if(ans[n]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
