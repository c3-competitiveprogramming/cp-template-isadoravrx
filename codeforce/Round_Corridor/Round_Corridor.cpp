#include <iostream>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }

    return gcd(b,a%b);
}

int main(){
    ll n,m,q;
    cin >> n >> m >> q;

    ll g = gcd(n,m);

    while(q--){
        ll sx,sy,ex,ey;
        cin >> sx >> sy >> ex >> ey;


        ll qgruposn = n/g;
        ll qgruposm = m/g;


        ey--;        
        sy--; //pra ir de 0 a n-1

        if(sx == 1 && ex == 1){
            if(sy /qgruposn == ey/qgruposn){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else if(sx == 1 && ex == 2){
            if(sy/qgruposn == ey/qgruposm){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }

        }else if(sx == 2 && ex == 1){
            if(sy/qgruposm == ey/qgruposn){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }

        }else{
            if(sy/qgruposm == ey/qgruposm){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }

        }
    }
}
