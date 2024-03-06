#include <iostream>
#include <cmath>
using namespace std;

int main(){

    long long v[1000002];
    for(long long i = 2; i <= 1000000; i++){
        bool isprime = true;

        for(long long j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                isprime = false;
                break;
            }
        }

        if(isprime){
            v[i] = 1;;
        }
    }

    int t;
    cin >> t;

    while(t--){
        long long n,m;
        cin >> n >> m;
    
        for(long long i = n; i <= m; i++){
            if(v[i] == 1){
                cout << i << endl;
            }
        }
        
        if(t != 0){
            cout << endl;
        }

    }
}
