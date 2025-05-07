#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    ll n;
    cin >> n;

    vector<pair<ll,ll> >v;
    for(ll i = 0; i < n; i++){
        ll a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }   

    if(n % 2 != 0){
        cout << "impossible" << endl;
        return 0;
    }


    sort(v.begin(), v.end());
    ll i = 0;
    ll j = n -1;
    bool b = true;
    ll oldsumb,oldsump;

    ll cont = 0;
    while(i < j){
        ll sumb = v[i].first + v[j].first;
        ll sump = v[i].second + v[j].second;  

        if(cont == 0){
            cont++;

        }else if(oldsumb != sumb || oldsump != sump){
            b = false;
            break;
        }

        oldsumb = sumb;
        oldsump = sump;
        i++;
        j--;
    }
    
    if(b){
        cout << "possible" << endl;
    }else{
        cout << "impossible" << endl;
    }
}