#include <iostream>
#include <cmath>
using namespace std;

long long phi(double n){
    double val = n;
    for(long long i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            while(n %i == 0){
                n /= i;
            }

            val *= (1 - 1/i);
        }
    }

    if(n > 1){
        val -= val/n;
    }

    return val;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        cout << phi(n) << endl;
    }
}
