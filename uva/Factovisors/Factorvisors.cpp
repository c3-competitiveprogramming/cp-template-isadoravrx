#include <iostream>
#include <map>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    double n,m;

    map<double,double>mp;
    double max = 1024;
    double temp = 1;
    for(double i = 1; i <= max; i++){
        mp[i] = temp;
        temp *= (i+1);
    }

    while(cin >> n >> m){
        if(m == 0){
            printf("0 divides %.0f!\n", n);
            continue;
        }

        if(m < n){
            printf("%.0f divides %.0f!\n",m, n);
            continue;
        }

        ll resto = ll(m) % ll(mp[n]);
        if(m == 1 || resto == 0){
            printf("%.0f divides %.0f!\n",m, n);
        }else{
            printf("%.0f does not divide %.0f!\n", m, n);
        }
    }
}