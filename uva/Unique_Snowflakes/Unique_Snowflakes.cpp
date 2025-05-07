#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int>v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        int i = 0;
        int j = 1; 

        if(n == 0){
            cout << 0 << endl;
            continue;
        }

        map<int,int>mp;
        mp[v[i]]++;
        int mx = 1;

        while(j < n){
            if(mp.find(v[j]) == mp.end() || mp[v[j]] == 0 ){
                mp[v[j]]++;
                j++;
            }else{
                mx = max(mx,j-i);
                mp[v[i]]--;
                i++;
            }
        }

        mx = max(mx,j-i);
        cout << mx << endl;

    }
}