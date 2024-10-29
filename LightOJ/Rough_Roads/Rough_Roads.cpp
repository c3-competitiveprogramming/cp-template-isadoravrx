#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
int n;

void djk(int start, int dist[], vector<vector<pair<int, int> > > &adj) {
    set<pair<pair<int,int>, int> > st;
    st.insert(make_pair(make_pair(0,start), 0));
    dist[start] = 0;

    while (!st.empty()) {
        int no = (*st.begin()).first.second;
        int cost = (*st.begin()).first.first;
        int qcaminhos = (*st.begin()).second;
        st.erase(st.begin());

        for(auto it : adj[no]) {
            if (dist[it.first] == -1 || it.second + cost < dist[it.first]) {
                if(it.first == n-1){
                    if(qcaminhos % 2 != 0){
                        dist[it.first] = it.second + cost;
                        st.insert(make_pair(make_pair(dist[it.first], it.first), qcaminhos+1));
                    }
                }else{
                    dist[it.first] = it.second + cost;
                    st.insert(make_pair(make_pair(dist[it.first], it.first), qcaminhos+1));
                }
            }
        }
    }
}

int main() {
    int  m, a, b, c, t = 1;

    while (cin >> n >> m) {
        vector<vector<pair<int, int> > > adj(n+1);
        int dist[502];

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }
        memset(dist, -1, sizeof(dist));
        djk(0, dist, adj);

        printf("Set #%d\n", t);
        if (dist[n-1] == -1) {
            cout << '?' << endl;
        } else {
            cout << dist[n-1] << endl;
        }
        t++;
    }

    return 0;
}