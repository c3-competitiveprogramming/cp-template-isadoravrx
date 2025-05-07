#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
    if(b == 0){
        return a;
    }

    return gcd(b, a % b);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        long long cont = 0;
        for(int i = 2; i < n; i++){
            if(gcd(n, i) == 1){
                cont++;
            }
        }

        if(n == 1){
            cout << 1 << endl;
        }else{
            cout << cont << endl;

        }
    }
}
