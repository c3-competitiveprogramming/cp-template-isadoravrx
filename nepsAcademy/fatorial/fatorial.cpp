#include <iostream>
typedef long long ll;
using namespace std;

ll recursive(ll n){
    if(n == 0){
        return 1;
    }
    return n * recursive(n-1);
}

int main(){
    ll n;
    cin >> n;

    cout << recursive(n) << endl;
}