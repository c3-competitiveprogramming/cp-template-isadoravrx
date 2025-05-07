#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    ll n;
    ll v[] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441, 1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224, 47045881, 64000000,85766121};
    while(cin >> n){
        if(n == 0){
            break;
        }

        bool b = false;
        for(ll i = 0 ; i < 21; i++){
            if(n == v[i]){
                b = true;
                break;
            }
        }
        if(b){
            cout << "Special" << endl;
        }else{
            cout << "Ordinary" << endl;
        }
    }

    return 0;

}