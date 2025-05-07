#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int main(){
    map<long long,long long>mp;
    long long aux = 0;

    for(long long i = 1; i <= 1000000; i++){
        long long num = sqrt(i + aux);
        double numdoub = sqrt(i+aux);
        bool isprime = true;
        
        for(long long j = 2; j*j <= num; j++){
            if(num % j == 0){
                isprime = false;
                break;
            }
        }
        
        if(isprime && i != 1 && num == numdoub){
            mp[i + aux] = 1;
        }else{
            mp[i + aux] = 0;
        }
        aux++;
    }
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        long long num;
        cin >> num;
        if(num == 4){
            cout << "YES" << endl;
        }else if(num % 2 == 0){
            cout << "NO" << endl;
        }else{
            if(mp[num] == 1){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
}
