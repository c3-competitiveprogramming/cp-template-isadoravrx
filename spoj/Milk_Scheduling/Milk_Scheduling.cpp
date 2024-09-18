#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n;
    cin >> n;


    int l,t;
    int mx = 0;
    multiset<pair<int,int> >set;

    for(int i = 0; i < n; i++){
        cin >> l >> t;
        set.insert(make_pair(l,t));
        mx = max(mx,t);
    }

    vector<int>v(mx+1); 
    int ans = 0;

    multiset<pair<int,int> >::reverse_iterator rit;

    for (rit = set.rbegin(); rit != set.rend(); rit++){
        if(v[(*rit).second] == 0){
            ans += (*rit).first;
            v[(*rit).second] = 1;
        }else{
            for(int i = (*rit).second -1; i > 0; i--){
                if(v[i] == 0){
                    ans += (*rit).first;
                    v[i] = 1;
                    break;
                }    
            }
        }
    }
    cout << ans << endl;
}
