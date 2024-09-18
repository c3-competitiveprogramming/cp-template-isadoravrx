#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
long long cont = 0;
long long n,m;

bool seeadj(vector<vector<long long> >&adj, bitset<35>&bt, long long i){
    for(long long x : adj[i]){
        if(bt[x]){
            return true;
        }
    }

    return false;
}



bool validate(vector<vector<long long> >&adj,bitset<35>&bt){

    for(long long i = 0; i < n; i++){
        if(bt[i] != 1 && !seeadj(adj,bt,i)){
            return false;
        }
        if(bt[i]){
            cont++;
        } 
    }

    return true;
}


int main(){

    while(true){
        cin >> n >> m;

        if(n == 0 && m == 0){
            break;
        }
        
        if(m == 0){
            cout << n << endl;
            continue;
        }

        vector<vector<long long> >adj(35);
        for(long long i = 0; i < m; i++){
            long long a,b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    
        long long nn=1;
        for(long long i=1;i<=n;i++){
            nn*=2;
        }
        long long minqum = n;
        for(long long i = 0; i < nn; i++){
            bitset<35>bt(i);
            for(int j = 0; j < 35; j++){
                if(bt[j] && adj[j].size() == 0){
                    continue;
                }
            }

            if(validate(adj,bt)){
                minqum = min(minqum,cont);
            }
            cont = 0;
        }

        cout << minqum << endl;
    }
}
