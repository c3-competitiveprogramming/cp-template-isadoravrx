#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

int main(){
    ll n;
    cin >> n;

    bool isprime = true;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            isprime = false;
            break;
        }
    }

    if(isprime){
        cout << "sim" << endl;
    }else{
        cout << "nao" << endl;
    }
}