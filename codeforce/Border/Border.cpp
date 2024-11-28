#include <iostream>
#include <set>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }

    return gcd(b,a%b);
}

int main(){
    int n,k;

    cin >> n >> k;
    
    ll g = 0;
    for(int i = 0; i < n; i++){
        ll num;
        cin >> num;
        g = gcd(g,num);
    }
    

    set<ll>st;
    ll sum = 0;

    for(int i = 0; i < k; i++){
        st.insert(sum%k);
        sum += g;
    }

    int cont = 0;
    cout << st.size() << endl;
    for(ll x : st){
        if(cont != 0){
            cout << " ";
        }
        cout << x; 
        cont = 1;
    }

    cout << endl;
}
