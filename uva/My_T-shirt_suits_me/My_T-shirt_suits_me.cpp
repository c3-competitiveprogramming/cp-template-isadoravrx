#include <iostream>
#include <map>
#include <string>

using namespace std;
bool b = false;
int c,p;

void recursive(map<int,pair<string,string> >&mp,map<string,int>&camisas,int v[], int i){
    if(b){
       return; 
    }
    if(i == p){
        b = true;
        return;
    }


    if(v[camisas[mp[i].first]] > 0){
        v[camisas[mp[i].first]]--;
        recursive(mp,camisas,v,i+1);
        v[camisas[mp[i].first]]++;
    }

    if(v[camisas[mp[i].second]] > 0){
        v[camisas[mp[i].second]]--;
        recursive(mp,camisas,v,i+1);
        v[camisas[mp[i].second]]++;
    }

}



int main(){
    int t;
    cin >> t;
    
    map<string,int>camisas;
    camisas["XXL"] = 0;
    camisas["XL"] = 1;
    camisas["L"] = 2;
    camisas["M"] = 3;
    camisas["S"] = 4;
    camisas["XS"] = 5;


    while(t--){
        cin >> c >> p;
    
        b = false;

        map<int,pair<string,string> >mp;

        for(int i = 0; i < p; i++){
            string s1, s2;
            cin >> s1 >> s2;
            mp[i] = make_pair(s1,s2);
        }
            
        int qcamisas = c/6;
        int v[6];
        
        for(int i = 0; i < 6; i++){
            v[i] = qcamisas;
        }

        recursive(mp,camisas,v,0);

        if(b){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }

    }
}
