#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

const int M = 1000000007;

ll soma(ll a, ll b){
    return (a+b) % M;
}

ll sub(ll a, ll b){
    return (a-b + M) %M;
}

ll mult(ll a, ll b){
    return 1ll * a * b % M;
}

ll exp(ll x, ll k){
    if(k == 0){
        return 1;
    }

    ll x_k2 = exp(x,k/2) % M;
    if(k % 2 == 1){
        return mult(mult(x_k2,x_k2), x) % M;
    }

    return mult(x_k2, x_k2) % M;
}


int main(){
    ll a,b;
    string opera;
    cin >> a >> opera >> b;


    if(opera == "+"){
        cout << soma(a,b) << endl;
    }
    if(opera == "-"){
        cout << sub(a,b) << endl;
    }
    if(opera == "*"){
        cout << mult(a,b) << endl;
    }
    if(opera == "^"){
        cout << exp(a,b) % M << endl;
    }
}