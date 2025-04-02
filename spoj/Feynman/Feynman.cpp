#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    map<int,int>mp;
    ll sum = 0;
    for(int i = 1; i <= 100; i++){
        sum += i * i;
        mp[i] = sum;
    }

    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }

        cout << mp[n] << endl;
    }
}