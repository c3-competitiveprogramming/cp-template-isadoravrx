#include <iostream>
#include <map>
#include <deque>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
    ll n,m;
    cin >> n >> m;
    
    map<int,ll[3]>mp;
    for(int i = 1; i <= n; i++){
        ll a,b;
        cin >> a >> b;
        
        if(mp.find(a) == mp.end()){
            mp[a][0] = a;
            mp[a][1] = b;
            mp[a][2] = i;
        }else{
            if(mp[a][1] < b){
                mp[a][1] = b;
            	mp[a][2] = i;	
	    }
        }
    }

    ll ini,fim;
    ll cont = 0;
    deque<ll>ans;
    ll qnum = 0;
    ll qrep = 0;
    for(auto i : mp){
        ll a = i.second[0];
        ll b = i.second[1];
        ll ind = i.second[2];
        if(cont == 0){
            ini = a;
            fim = b;
            cont = 1;
            ans.push_back(ind);
            qnum = b-a + 1;
            continue;
        }
        
        if(a < fim){
            if(b < fim){
                continue;
            }else{
                if(a <= ini + qrep){
                    ans.pop_back();
                    qrep = a - (ini+qrep -1); 
                }else{
                    qrep = fim - a + 1;
                }
                
                qnum += b - fim;
                ini = a;
                fim = b;
                ans.push_back(ind);    
            }
        }else{
            ans.push_back(ind);
            qnum += b-a+1;
            ini = a;
            fim = b;
            qrep = 0;
        }
    }
    
    sort(ans.begin(), ans.end());
    if(qnum < m){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        if(i == ans.size() - 1){
            cout << ans[i] << endl;
            return 0;
        }
    
        cout << ans[i] << " ";    
    }

}
