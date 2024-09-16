#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    ll n,x;
    cin >> n >> x;

    vector<pair<ll,ll> >v;

    for(int i = 0; i < n ;i++){
        ll s,d;
        cin >> s >> d;
        v.push_back(make_pair(s,s+d));
    }

    sort(v.begin(), v.end());
    ll mintime = 10000000000, minconflict = 10000000000;
    for(ll i = 0; i <= 480; i++){
        ll time = i;
        ll acrescimo = x;
        ll qconflitos = 0;
        ll j = 0;

        while(true){
            if(qconflitos > minconflict){
                break;
            }
            while(j < n && time > v[j].first && time > v[j].second){
                j++;
            }

            if(j == v.size()){
                break;
            }

            while(time < v[j].first){
                time+=acrescimo;
            }

            if(j == v.size()){
                break;
            }

            if(time >= v[j].first && time<= v[j].second){
                qconflitos++;
                while((time + acrescimo) <= v[j].second){
                    qconflitos++;
                    time+= acrescimo;
                }

                j++;
            }

            
        }

        if(qconflitos < minconflict){
            minconflict = qconflitos;
            mintime = i;
        }
    }

    cout << mintime << " " << minconflict << endl;

}