#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;


bool comp(const pair<ll,ll> &s1, const pair<ll,ll>&s2){
    if(s1.first < s2.first){
        return true;
    }else{
        return false;
    }
}

int main(){

    ll t;
    cin >> t;
    int test = 0;
    while(t--){
        ll slenght, n;
        cin >> slenght >> n;

        if(test != 0){
            cout << endl;
        }

        vector<string>original;
        vector<pair<ll,ll> >v;
        for(ll i = 0; i < n ; i++){
            string s;
            cin >> s;
            
            original.push_back(s);
            ll qta = 0,qtc = 0,qtdg = 0;
            ll cont = 0;
            for(ll j = slenght-1; j >= 0; j--){

                if(s[j] == 'T'){
                    cont+= qta + qtc + qtdg;
                }else if(s[j] == 'G'){
                    cont += qta + qtc;
                    qtdg++;
                }else if(s[j] == 'C'){
                    cont += qta;
                    qtc++;
                }else if(s[j] == 'A'){
                    qta++;
                }
            }

            v.push_back(make_pair(cont, i));

        }

        sort(v.begin(), v.end(), comp);

        for(auto it : v){
            cout  << original[it.second] << endl;
        }

        if(v.size() == 0){
            cout << endl;
        }
        test = 1;
    }
    return 0;
}