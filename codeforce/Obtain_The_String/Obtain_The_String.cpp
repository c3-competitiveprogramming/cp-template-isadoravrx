#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int test;
    cin >> test;

    while(test--){
        string s, t;
        cin >> s >> t;

        vector<int> mp[26];
        for(int i = 0; i < s.size(); i++){
            mp[s[i] - 'a'].push_back(i);
        }

        int index = 0;
        int ans = 1;
        bool naoexiste = false;

        for(int i = 0; i < t.size(); i++) {
            int now = t[i] - 'a';

            if (mp[now].empty()) {
                naoexiste = true;
                break;
            }

            if (index > mp[now][mp[now].size() - 1]) {
                index = 0;
                ans++;
            }

            int a = upper_bound(mp[now].begin(), mp[now].end(), index) - mp[now].begin();

            if ((a < mp[now].size() && a != 0 && mp[now][a - 1] == index) || (a == mp[now].size())) {
                a = a - 1;
            }

            index = (mp[now][a]) + 1;
        }

        if(naoexiste){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }
}