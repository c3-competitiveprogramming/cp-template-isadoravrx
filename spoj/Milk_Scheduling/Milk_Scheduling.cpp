#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    map<int,int>mp;
    
    int l,t;
    for(int i = 0; i < n; i++){
        cin >> l >> t;
        
        if(mp.find(t) != mp.end() && mp[t] > l){
            continue;
        }
        mp[t] = l;
    }

        
    int time = 0;
    int cont = 0;
    for(auto it : mp){
        if(it.second >= time){
            cont += it.second;
        }

        time++;
    }

    cout << cont << endl;

}
