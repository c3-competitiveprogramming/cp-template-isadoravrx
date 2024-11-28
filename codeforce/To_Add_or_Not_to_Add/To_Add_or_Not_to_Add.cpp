#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    ll n,k;
    cin >> n >> k;

    vector<ll>v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i]; 
    }

    ll i = 0; 
    ll j = 0;
    ll sum = 0;
    ll bestq = 0;
    ll bestnum = 0;

    sort(v.begin(),v.end());
    while(j < n){
        if((sum + k) >= (v[j]*(j-i))){
            sum += v[j];
            ll qnumrep = (j-i)+1;
            
            if(qnumrep > bestq){
                bestq = qnumrep;
                bestnum = v[j];
            }

            j++;
        }else{
            sum -= v[i];
            i++;
        }
    }

    cout << bestq << " " << bestnum << endl;
}
