#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;


bool valido(ll a,ll b, ll c){
    if((a < b+c) && (b < a + c) && (c < a + b) ){
        return true;
    }

    return false;
}

int main(){
    ll test;
    cin >> test;
    
    for(int t = 1; t <= test; t++){
        ll a,b,c;
        cin >> a >> b >> c;

        if(valido(a,b,c)){

            if(a == b && b == c){
                printf("Case %d: Equilateral\n", t);
            }else if(a == b || a == c || b == c){
                printf("Case %d: Isosceles\n",t);
            }else{
                printf("Case %d: Scalene\n",t);
            }
        }else{
            printf("Case %d: Invalid\n", t);
        }
    }

}
