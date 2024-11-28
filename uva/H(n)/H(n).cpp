#include <iostream>
#include <map>
using namespace std;
map<long long, long long>mp;


int main(){

    for(int j = 0; j <= 2e32; j++){
        long long res = 0;
        long long i;
        for( i = 1; i <= j; i=i+1 ){
            res = (res + j/i);
            if(j/i == 1){
                break;
            }
        }
        res += ( j - i );
        mp[j] = res;
    }


    int t;
    cin >> t;

    while(t--){
        long long n;
        cin >> n;

        if(n < 0) {
            cout << 0 << endl;
        }else{
            cout << mp[n] << endl;
        }
    }

}