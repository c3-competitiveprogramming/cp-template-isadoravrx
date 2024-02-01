#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int cont = 0;
    map<int,pair<int,int>>mp;
    
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        if(mp.find(x) == mp.end()){
            mp[x] = make_pair(x,y);
        }else{
            if(mp[x].second > y){
                mp[x].second = y;
            }
        }
    }
    
    int ini,fim;
    cont = 0;
    for(auto i : mp){
        if(cont == 0){
            ini = i.second.first; 
            fim = i.second.second;
            cont = 1;
            continue;
        }
        if(i.second.first < fim){
            if(i.second.second > fim){
                continue;
            }
        }else{
            cont++;
        }
            ini = i.second.first;
            fim = i.second.second;
    }

    cout << cont << endl;
}
