#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;
long long qpaths = 0;
long long n,m;

int main(){
    cin >> n >> m;

    vector<long long>v(n+1);
    for(long long i = 1; i <= n; i++){
        long long num;
        cin >> num;
        v[i] = num;
    }
    vector<vector<long long> >adj(n+1);
    for(long long i = 0; i < (n-1) ; i++){
        long long a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long visited[100002] ;
    memset(visited,0,sizeof(visited));

    deque<pair<long long,long long> >dq;
    dq.push_front(make_pair(1,0));

    while(!dq.empty()){
        long long no = dq[0].first;
        long long cont = dq[0].second;

        dq.erase(dq.begin());

        visited[no] = 1;
        if(v[no] == 0){
            cont = 0;
        }else{
            cont++;
        }
        if(adj[no].size() == 1 &&  no != 1 && cont <= m){
            qpaths++;
            continue;
        }

        if(cont > m){
            continue;
        }

        for(auto x : adj[no]){
            if(visited[x] == 0){
                dq.push_front(make_pair(x,cont));
            }
        }
    }




    cout << qpaths << endl;
}