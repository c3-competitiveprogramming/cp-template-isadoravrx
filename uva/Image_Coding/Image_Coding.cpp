#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t ;
    int test = 1;

    while(t--){
        int r,c,m,n;
        cin >> r >> c >> m >> n;

        vector<vector<char> >v(r, vector<char>(c));
        map<char,int> mp;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                char c;
                cin >> c;
                v[i][j] = c;    
                mp[c]++;
            }
        }

        int mx = 0;
        for(auto it : mp){
            mx = max(mx, it.second);
        }

        vector<char>maiores;
        for(auto it : mp){
            if(it.second == mx){
                maiores.push_back(it.first);
            }
        }

        long long ans = 0;
        ans += mx * maiores.size() * m;
        ans += ((r * c) - (mx * maiores.size())) * n;
        
        printf("Case %d: %lld\n", test, ans);
        test++;
    }
}