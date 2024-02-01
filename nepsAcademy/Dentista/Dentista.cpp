#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int cont = 0;
    map<int,int>mp;
    
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        if(mp.find(x) == mp.end()){
            mp[x] = y;
        }
    }
    
    int ini,fim;
    cont = 0;
    for(auto i : mp){
        if(cont == 0){
            ini = i.first; 
            fim = i.second;
            cont = 1;
            continue;
            cont++;
        }
        if(mp.fisrt < fim && mp.second < fim){
            ini = i.first;
            fim = i.second;
        }else{
            cont++;
        }
            ini = i.first;
            fim = i.second;
    }

    cout << cont << endl;
}
