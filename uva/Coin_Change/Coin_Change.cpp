#include <iostream>
#include <map>
using namespace std;

int v[] = {1,5,10,25,50};
int n, ans = 0;
map<int,int>mp;

void busca(int sum, int index){
    if(sum == n){
        ans++;
        return;
    }

    if(sum > n){
        return;
    }

    if(index == 5){
        return;
    }

    int vezes_adiciona = 0;
    while(sum + (vezes_adiciona * v[index]) <= n){
        busca(sum + (vezes_adiciona * v[index]), index+1);
        vezes_adiciona++;
    }
}

int main(){
    mp[0] = 1;
    while(cin >> n){
        ans = 0;

        if(mp.find(n) == mp.end()){
            busca(0,0);
            mp[n] = ans;
        }else{
            ans = mp[n];
        }

        
        
        cout << ans << endl;
    }
}