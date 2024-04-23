#include <iostream>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }

    return gcd(b,a % b);
}
long long phi(long long n){
    long long val = n;
    for(long long i = 2; i*i <= n; i++){
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
        ll a,m;
        cin >> a >> m;

        cout << phi(m/gcd(m,a)) << endl;
    }
}
