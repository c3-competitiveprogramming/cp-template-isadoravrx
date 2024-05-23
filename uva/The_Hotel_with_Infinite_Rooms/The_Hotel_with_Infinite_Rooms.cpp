#include <iostream>
#include <map>
typedef long long ll;
using namespace std;


int main(){
    ll s,d;
    map<pair<ll,ll>,ll>mp;   
    while(cin >> s >> d){
        if(mp.find(make_pair(s,d)) != mp.end()){
            cout << mp[make_pair(s,d)] << endl;
        }else{
            
            ll cont = s;
            ll ini = 1;
            ll fim = s;

            while(!(ini <= d && d <= fim)){
                cont++;
                ini = fim + 1;
                fim = ini + cont - 1;
            }

            cout << cont << endl;
            mp[make_pair(s,d)] = cont;

        }

    }
}
