#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
bool b = false;
ll n;

int memo[100005][10000000002];

void recursive( vector<ll>&v, int i , ll soma1, ll aux1, ll soma2, ll aux2){

    if(soma1 == 0){
        recursive(v,i+1,soma1+v[i], aux1, soma2,aux2);
        return;
    }else if(soma2 == 0){
        recursive(v,i+1,soma1, aux1, soma2 + v[i],aux2);
        return;
    }

    if(memo[i][soma1] == 1){
        return;
    }
    if(aux1 == soma1){
        soma1 += aux1;
        aux1 = 0;
    }

    if(aux2 == soma2){
        soma2 += aux2;
        aux2 = 0;
    }

    if(i == n && aux1 == 0 && aux2 == 0){
        b = true;
        return;
    }
    recursive(v,i+1, soma1, aux1+v[i], soma2,aux2);
    recursive(v,i+1, soma1, aux1, soma2,aux2+v[i]);
    memo[i][soma1] = 1;
}



int main(){
    
    cin >> n;
    vector<ll>v(n);
    for(ll i = 0; i < n ;i++){
        cin >> v[i];
    }   

    if(n == 1){
        cout << "N" << endl;
    }
    recursive(v,1,v[0],0,0,0);
    recursive(v,1,0,0,v[0],0);

    if(b){
        cout << "Y" << endl;
    }else{
        cout << "N" << endl;
    }
}