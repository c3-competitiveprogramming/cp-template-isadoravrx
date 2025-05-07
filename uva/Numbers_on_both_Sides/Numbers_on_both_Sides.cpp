#include <iostream>
#include <vector>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;

map<pair<pair<ll,ll>,ll>, ll>mp;
ll n;
ll highsumsub = 0;
ll highsum = 0;
vector<ll>v1;
vector<ll>v2;
ll k, l;

void recursive2(ll i, vector<ll>&temp, ll sum, ll contpeguei2){
    if(contpeguei2 == l){
        highsumsub = max(highsumsub, sum);
        return;
    }

    if(i >= temp.size()){
        return;
    }

    recursive2(i+1, temp, sum + v2[temp[i]], contpeguei2+1);
    recursive2(i+1, temp, sum, contpeguei2);

}


void recursive(ll i, ll j, ll sum, ll contpeguei1){ 
    if(mp.find(make_pair(make_pair(i,j), sum)) != mp.end()){
        return;
    }
    if(contpeguei1 == k){
        vector<ll>temp;
        for(ll z = 0; z < i; z++){
            temp.push_back(z);
        }

        for(ll z = j+1; z < n; z++){
            temp.push_back(z);
        }

        if(temp.size() != 0){
            recursive2(temp[0],temp,0,0);
        }
        ll tempsum = highsumsub + sum;
        highsum = max(highsum, tempsum);
        highsumsub = 0;
        return;
    }

    if(i == j){
        recursive(i+1,j,sum+v1[i],contpeguei1+1);
    }
    if(i + 1 <= j){
        recursive(i+1,j,sum+v1[i],contpeguei1+1);
    }
    if(j-1 >= i){
        recursive(i,j-1,sum+v1[j],contpeguei1+1);
    }

    mp[make_pair(make_pair(i,j), sum)] = 1;
}

int main(){
    cin >> n;

    ll num;
    for(ll i = 0; i < n ; i++){
        cin >> num;
        v1.push_back(num);
    }

    for(ll i = 0; i < n ; i++){
        cin >> num;
        v2.push_back(num); 
    }

    
    cin >> k >> l;

    recursive(0,n-1,0,0);

    cout << highsum << endl;
    return 0;
}