#include <iostream>
#include <string>
#include <map>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    string s;
    cin >> s;

    ll n;
    cin >> n;
    vector<ll>v(n);

    for(ll i = 0; i < n; i++){
        cin >> v[i];
    }

    ll cont = 0;
    for(ll i = 0; i <= s.size()-n; i++){
        map<ll,char>mp;
        bool b = true;
        ll indexdos = i;
        vector<ll>jatemmap(28);
        for(ll j = 0; j < n; j++){
            if(mp.find(v[j]) == mp.end()){
                if(jatemmap[s[indexdos] - 'a'] != 0){
                    b = false;
                    break;
                }
                mp[v[j]] = s[indexdos];
                jatemmap[s[indexdos] - 'a'] = 1;
            }else{
                if(mp[v[j]] != s[indexdos]){
                    b = false; 
                    break;
                }
            }
            indexdos++;
        }

        if(b){
            cont++;
        }
    }
    
    cout << cont << endl;
}