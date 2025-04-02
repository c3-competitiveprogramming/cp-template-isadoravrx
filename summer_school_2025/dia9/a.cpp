#include <iostream>
#include <string>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    string s;
    cin >> s;

    ll maxcont = 1;
    map<char,ll>mp;
    mp['A'] = 1;
    mp['B'] = 1;
    mp['C'] = 1;
    int conta = 0, contb = 0, contc = 0;
    for(int i = 0; i < s.size(); i++){

        if(s[i] == 'A'){
            conta++;
        }else if(s[i] == 'B'){
            contb++;
        }else{
            contc++;
        }

        if(conta > 0 && contb > 0 && contc > 0){
            for(auto it : mp){
                mp[it.first]++;
            }
            conta--;
            contb--;
            contc--;
        }

        if(mp[s[i]] > 0){
            mp[s[i]]--;
        }else{
            maxcont++;
            for(auto it : mp){
                if(it.first != s[i]){
                    mp[it.first]++;
                }
            }
        }


        if(mp['A'] == 0 &&  mp['B'] == 0 && mp['C'] == 0){
            for(auto it : mp){
                mp[it.first] += maxcont;
            }
        }



    }

    cout << maxcont << endl;
    
}
