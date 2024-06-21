#include <iostream>
#include <vector>
#include <map>
using namespace std;
int cat, prob;
bool b = false;

int recursive(int index, vector<int>qporcat, vector<vector<int> >&v,vector<vector<int> > aux , vector<vector<int> >&ans, map<pair<int,vector<int> >,int > &mp){
    if(b){
        return 1;
    }
    bool allzero = true;
    for(int i = 0; i < cat; i++){
        if(qporcat[i] != 0){
            allzero = false;
            break;
        }
    }

    if(allzero){
        ans = aux;
        b = true;
        return 1;
    }
    
    if(index >= prob){
        return 0;
    }

    for(int x : v[index]){
        if(qporcat[x] == 0){
            continue;
        }
        aux[x].push_back(index+1);
        qporcat[x]--;
        if(mp.find(make_pair(index, qporcat)) == mp.end()){
            mp[make_pair(index,qporcat)] = recursive(index+1,qporcat,v,aux,ans,mp); 
        }else{
            return mp[make_pair(index,qporcat)];
        }
        qporcat[x]++;
        aux[x].pop_back();
    }   

    recursive(index+1,qporcat,v,aux,ans,mp);

}


int main(){
    
    while(cin >> cat >> prob){
        
        if(cat == 0 && prob == 0){
            break;
        }
        
        map<pair<int,vector<int> >, int > mp;

        vector<int>qporcat(cat);
        for(int i = 0; i < cat; i++){
            cin >> qporcat[i];
        }

        vector<vector<int> >v(prob+1);
        for(int i = 0; i < prob; i++){
            int num;
            cin >> num;

            for(int j = 0; j < num; j++){
                int c;
                cin >> c;
                v[i].push_back(c-1);
            }
        }

        vector<vector<int> >ans;
        vector<vector<int> >aux(cat);
        b = false;
        recursive(0,qporcat,v,aux,ans,mp);
        
        if(b){
            cout << 1 << endl;
            
            for(int i = 0; i < cat; i++){
                for(int j = 0; j < ans[i].size(); j++){
                    if(j != 0){
                        cout << " ";
                    }
                    cout << ans[i][j];
                }
                cout << endl;
            }

        }else{
            cout << 0 << endl;
        }
    }
}
