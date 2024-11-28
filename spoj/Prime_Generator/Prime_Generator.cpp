#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        long long m, n;
        cin >> m >> n;
        
        for(long long i = m; i <= n; i++){
            bool isprime = true;
            for(long long j = 2; j * j <= i; j++ ){
                if(i % j == 0){
                    isprime = false;
                    break;
                }
            }
            
            if(isprime && i != 1){
                cout << i << endl;
            }
        }

        if(t != 0){
            cout << endl;
        }
        
    }
}
