#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;

bool temciclo = false;

void dfs(ll no, map<ll, vector<ll> > &adj ,map<ll,ll>&visited){
    visited[no] = 1;

    for(auto x : adj[no]){
        if(visited.find(x)==visited.end()){
            dfs(x,adj,visited);
        }else{
            temciclo = true;
        }
    }
}

int main(){

    int caso=0;
    ll a,b,raiz,maxno=-1;
    map<ll,ll> aponta_pramim, eu_aponto;
    map<ll, vector<ll> > adj;
    set<ll> nos;

    bool ehArvore=true;
    while(cin>>a>>b){
        if(a < 0 && b < 0){
            break;
        }
        if(a+b==0){
            temciclo=false;
            raiz=-1;

            int cont=0;
            for(auto it:eu_aponto){//ou seja, se o num q ta no inverso nao tiver ngm apontando pra ele
                if(aponta_pramim.find(it.first)==aponta_pramim.end()){
                    cont++;
                    raiz=it.first;
                }
            }

            if(cont!=1 || raiz == -1){
                ehArvore=false;
            }

            if(ehArvore || aponta_pramim.size()+eu_aponto.size()!=0){
                map<ll,ll>visited;
                dfs(raiz, adj, visited); 
                for(auto it : nos){
                    if(visited.find(it)==visited.end()){ 
                        ehArvore = false;
                        break;
                    }
                }
            }

            caso++;
            if(ehArvore || aponta_pramim.size()+eu_aponto.size()==0){
                printf("Case %d is a tree.\n",caso);
            }else{
                printf("Case %d is not a tree.\n",caso);
            }
            ehArvore=true;
            aponta_pramim.clear();
            eu_aponto.clear();
            adj.clear();
            nos.clear();
            maxno=-1;
        }else{
            if(a>maxno){maxno=a;}
            if(b>maxno){maxno=b;}
            nos.insert(a);nos.insert(b);
            adj[a].push_back(b);
            aponta_pramim[b]++;
            eu_aponto[a]++;
            if(aponta_pramim[b]>1 || a==b){
                ehArvore=false;
            }
        }
    }

    return 0;
}