#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

bool somesucessorchosed(vector<vector<int> >&sucessores, vector<int>&v, int j){
    for(int k = 0; k < sucessores[j].size(); k++){
        if(v[sucessores[j][k]] == 1){
            return true;
        }
    }

    return false;
}

int main(){
    int n,k;
    cin >> n >> k;

    vector<int>values(n+1);
    for(int i = 2; i <= n; i++){
        cin >> values[i];
    }

    vector<int>antecessor(n+1);
    for(int i = 2; i <= n; i++){
        cin >> antecessor[i];
    }   

    vector<vector<int> >sucessores(n+1);
    for(int i = 2; i <= n; i++){
        int antecessordei = antecessor[i];
        sucessores[antecessordei].push_back(i);
    }


    int mxsum = 0;
    for(int i = 0; i <= pow(2,n+1); i++){
        bitset<100002>bt(i);
        
        vector<int>v(n+1);
        bool ispossible = true;
        int quns = 0;
        //verificar se no mesmo grupo, tem algum antecessor
        for(int j = 0; j < n; j++){
            if(bt[j] == 1){
                if(antecessor[n-j] == 1 || somesucessorchosed(sucessores, values,n-j)){
                    ispossible = false;
                }else{
                    v[n-j] = 1;
                }
                
                quns++;
            }
        }
        //guarda a soma, se o grupo for valido
        int sum = 0;
        if(ispossible && quns == k){
            
            for(int j = 0; j < n; j++){
                if(bt[j] == 1){
                    sum += values[n-j];
                }
            }
        }
        


        mxsum = max(mxsum, sum);
    }

    cout << mxsum << endl;
}