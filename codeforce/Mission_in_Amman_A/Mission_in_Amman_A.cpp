#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int>where(n);
    map<int,int>mp;
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        where[i] = num-1;
        mp[num-1]++;
    }
    
    int ans = m - mp.size(); 
    for(int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;

        a--;
        b--;
        
        int pos = where[a];

        if(mp[pos] == 1){
            ans++;
        }

        if( mp.find(b) == mp.end() ||mp[b] == 0){
            ans--;
        }

        if(mp.find(pos) != mp.end() && mp[pos] != 0){
            mp[pos]--;
        }
        mp[b]++;
        where[a] = b;
        cout << ans << endl;
    }

}
