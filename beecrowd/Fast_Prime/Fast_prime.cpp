#include <iostream>
#include <map>
#include <cmath>
using namespace std;

bool isprime(int n){
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(isprime(n)){
            cout << "Prime" << endl;
        }else{
            cout << "Not Prime" << endl;
        }
    }
}