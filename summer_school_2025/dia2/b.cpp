#include <iostream>
typedef long long ll;
using namespace std;

int M = 1000000007;

ll mult(ll x, ll y) {
    return 1ll * x *y % M;
}


ll exp(ll x, ll k){
    if(k == 0){
        return 1;
    }

    ll x_k2 = exp(x, k/2) % M;
    if(k % 2 == 1){
        return mult(mult(x_k2, x_k2) % M,x) % M;
    }

    return mult(x_k2, x_k2) % M;
}


int main(){
    ll n; 
    cin >> n;

    cout << exp(2,n-1) % M << endl;
}