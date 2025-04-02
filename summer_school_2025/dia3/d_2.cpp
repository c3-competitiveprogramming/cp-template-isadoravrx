#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll maxcont = 0;
bool b = true;
ll n;

void recursive(vector<ll>&v, ll index, ll sequencelenght, ll sum){
    if(index >= n -1){
        sum += v[n-1];
        if(b){
            maxcont = sum;
            b = false;
        }else{
            maxcont = max(maxcont, sum);
        }   
        return;
    }


    for(ll i = sequencelenght; i >= 1; i--){
        recursive(v,index + i, i, sum + v[index]);
    }

}

int main(){
   
    cin >> n;

    vector<ll>v(n);
    for(ll i = 0; i < n ; i++){
        cin >> v[i];
    }

    recursive(v,0,n-1,0);
    for(ll i = 1; i < n; i++){
        recursive(v,i,i,v[0]);
    }

    cout << maxcont << endl;
}