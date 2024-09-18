#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }

    return gcd(b , a % b);
}

int main(){
   ll t;

   cin >> t;

   while(t--){
      ll a,b,c,d;

      cin >> a >> b >> c >> d;
        
      cout << gcd(abs(c-a),abs(d-b)) + 1 << endl;
   }
}
