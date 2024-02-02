#include <iostream>
#include <map>
#include <deque>
using namespace std;
#define ll long long

int main(){
    ll n,m;
    cin >> n >> m;
    
    map<ll,ll[3]>mp;
    for(int i = 1; i <= n ; i++){
        ll a,b;
        cin >> a >> b;
        if(mp.find(b) == mp.end()){
            mp[b][0] = a;
            mp[b][1] = b;
            mp[b][2] = i;
        }else{
            if(a < mp[b][0]){
                mp[b][0] = a;//ini
                mp[b][1] = b;//fim
                mp[b][2] = i;//index
            }
        }

    }

    map<ll, ll[3]>::reverse_iterator it;

    ll cont = 0;
    ll ini,fim;
    deque<ll>v;
    ll rep = 0;
    
    for(it = mp.rbegin(); it != mp.rend(); ++it){ //it vai do ultimo ao primeiro
        if(cont >= m){
            break;
        }
        ll a = (*it).second[0];
        ll b = (*it).second[1];
        ll ind = (*it).second[2];
        
        if(cont == 0){
            ini = a;
            fim = b;
            v.push_front(ind);
            cont += (fim - ini) + 1;
            continue;
        }
       
        if(a > ini){
            continue;
        }else{
            if(b >= fim - rep && a < ini){ //tem como subs o anterior e abrangir +numbers?
                v.pop_front();
                v.push_front(ind);
                rep = fim - rep - b;
                cont += ini - a;
                ini = a;
                fim = b;
            }else{ //ent vamos ter que gastar msm
                v.push_front(ind);
                rep = b - ini +1;
                ini = a;
                fim = b;
                if(rep < 0){
                    rep = 0;
                }
                cont += b-a+1-rep;
            }
        }

    }
    
    if(cont < m){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        if(i == v.size() - 1){
            cout << v[i] << endl;
            return 0;
        }
    
        cout << v[i] << " ";    
    }
}
