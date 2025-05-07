#include <iostream>
#include <cmath>
using namespace std;

long long phi(int n){
    double val = n;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            while(n %i == 0){
                n = ((double)n / (double)i);
            }

            val *= (1.0 - (1.0/(double)i));
        }
    }

    if(n > 1){
        val = val - val/ (double)n;
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
