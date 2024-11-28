#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;

int main(){
    int n;
    bitset<1000001>bt(0);
    for(int i = 2; i <= 1000000; i++){
        bool isprime = true;
        for(int j = 2; j <= sqrt(i); j++){
            if(i % j == 0){
                isprime = false;
                break;
            }
        }

        if(isprime){
            bt[i] = 1;
        }
    }
    
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }
        int cont = 0;    
        for(int i = 2; i <= (n /2); i++){
            if(bt[i] == 1 && n % i == 0){
                cont++;
            }
        }
        
        if(bt[n] == 1){
            cont++;
        }
        cout << n << " " << ": " << cont << endl;
   }
}
